#include "..\script_component.hpp"
/*
	 * Authors: Bryan "Tonic" Boardwine Modified by Bragg
	 * Description: Commits an asynchronous call to ExtDB3
	 *
	 * Arguments:
	 * 0: _queryStmt (default: "") <STRING> - The SQL query to execute
	 * 1: _mode (default: 1) <INTEGER> - The mode of the call,1 for async without return,2 for async with return
	 * 2: _multiarr (default: false) <BOOL> - Whether to return a single array or multiple entries
	 *
	 * Return Value:
	 * Return description <NONE>
	 *
	 * Example:
	 * ["existPlayerInfo:123123123123",2] call pc_database_fnc_asyncCall
	 *
	 * Public: No
 */

params [
	["_queryStmt","",[""]],
	["_mode",1,[0]],
	["_multiarr",false,[false]]
];

TRACE_1("fn_asyncCall",_this);

private _key = "extDB3" callExtension format["%1:%2:%3",_mode,GVAR(protocolID),_queryStmt];

if (_mode isEqualTo 1) exitWith {
	true
};

_key = call compile format["%1",_key];
_key = (_key select 1);
private _queryResult = "extDB3" callExtension format["4:%1",_key];

// Make sure the data is received
if (_queryResult isEqualTo "[3]") then {
	for "_i" from 0 to 1 step 0 do {
		if (_queryResult isNotEqualTo  "[3]") exitWith {};
		_queryResult = "extDB3" callExtension format["4:%1",_key];
	};
};

if (_queryResult isEqualTo "[5]") then {
	private _loop = true;
	for "_i" from 0 to 1 step 0 do {
		_queryResult = "";
		for "_i" from 0 to 1 step 0 do {
			_pipe = "extDB3" callExtension format["5:%1",_key];
			if (_pipe isEqualTo "") exitWith {
				_loop = false
			};
			_queryResult = _queryResult + _pipe;
		};
		if (!_loop) exitWith {};
	};
};

_queryResult = call compile _queryResult;
if ((_queryResult select 0) isEqualTo 0) exitWith {
	diag_log format ["extDB3: Protocol Error: %1",_queryResult];
	[]
};
private _return = (_queryResult select 1);
if (!_multiarr && count _return > 0) then {
	_return = (_return select 0);
};

_return
