#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Initialize the loadout dialog
	 *
	 * Arguments:
	 * 0: _object <OBJECT> - The object to initialize the addAction
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call pc_dialogs_loadout_fnc_init
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("fnc_init",_this);

if (isNull _object) exitWith {
	ERROR("fnc_init: object provided is null");
};

_object addAction [LSUBLSTRING(Open), {
	params ["_target", "_caller", "_actionId"];
	[_caller] call SUBFUNC(open);
}, nil, 1.5, true, true, "", "true", 5];
