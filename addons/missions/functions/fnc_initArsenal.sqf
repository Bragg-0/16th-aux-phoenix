#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Initialize the Arsenal
 *
 * Arguments:
 * 0: _object (default: ObjNull) <OBJECT> - The object to initialize the arsenal for
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [this] call pc_missions_fnc_initArsenal
 *
 * Public: No
 */

params [
    ["_object", objNull, [objNull]]
];

TRACE_1("fnc_initArsenal",_this);

_object addAction [LLSTRING(openArsenal), {
	params ["_target", "_caller", "_actionId"];
	[_target, _caller] call ace_arsenal_fnc_openBox;
}, nil, 1.5, true, true, "", "true", 5];

[_object, true] call ace_arsenal_fnc_initBox;
