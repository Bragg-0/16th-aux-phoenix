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
	 * ["getPlayerProfileBySteamId:76561198113173701",2] call pc_database_fnc_asyncCall //! Need to be executed by the server
	 *
	 * Public: No
 */

private["_queryStmt","_mode","_multiarr","_queryResult","_key","_return","_loop"];
_queryStmt = [_this,0,"",[""]] call BIS_fnc_param;
_mode = [_this,1,1,[0]] call BIS_fnc_param;
_multiarr = [_this,2,false,[false]] call BIS_fnc_param;

_key = "extDB3" callExtension format["%1:%2:%3",_mode,"sqf",_queryStmt];

if (_mode isEqualTo 1) exitWith {true};

private _keyRaw = call compile format["%1",_key];
if (isNil "_keyRaw" || (typeName _keyRaw != "ARRAY") || (count _keyRaw < 2)) exitWith {
    diag_log format ["extDB3: Invalid key returned: %1", _key];
    []
};
_key = _keyRaw select 1;
_queryResult = "extDB3" callExtension format["4:%1", _key];

//Make sure the data is received
if (_queryResult isEqualTo "[3]") then {
    for "_i" from 0 to 1 step 0 do {
        if ((_queryResult isNotEqualTo "[3]")) exitWith {};
        _queryResult = "extDB3" callExtension format["4:%1", _key];
    };
};

if (_queryResult isEqualTo "[5]") then {
    _loop = true;
    for "_i" from 0 to 1 step 0 do {
        _queryResult = "";
        for "_i" from 0 to 1 step 0 do {
            _pipe = "extDB3" callExtension format["5:%1", _key];
            if (_pipe isEqualTo "") exitWith {_loop = false};
            _queryResult = _queryResult + _pipe;
        };
    if (!_loop) exitWith {};
    };
};

private _queryResultRaw = call compile _queryResult;
if (isNil "_queryResultRaw" || (typeName _queryResultRaw != "ARRAY") || (count _queryResultRaw < 2)) exitWith {
    diag_log format ["extDB3: Protocol Error: %1", _queryResult];
    []
};
_queryResult = _queryResultRaw;
if ((_queryResult select 0) isEqualTo 0) exitWith {diag_log format ["extDB3: Protocol Error: %1", _queryResult]; []};
_return = (_queryResult select 1);
if (!_multiarr && count _return > 0) then {
    _return = (_return select 0);
};

_return
