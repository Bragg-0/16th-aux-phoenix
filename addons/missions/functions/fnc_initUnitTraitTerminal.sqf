#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Initialize unit trait terminal
	 *
	 * Arguments:
	 * 0: _object <OBJECT> - The object to initialize the trait terminal for
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call pc_missions_fnc_initUnitTraitTerminal
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("fnc_initUnitTraitTerminal",_this);

if (isNull _object) exitWith {
	WARNING_1("fnc_initUnitTraitTerminal: %1 is null",_object);
};

_object addAction [LLSTRING(giveMedicalUnitTrait), {
	params ["_target", "_caller", "_actionId"];
	[_caller, "medic", true] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE(!((_player getVariable [ARR_2('ace_medical_medicclass', 0)]) > 0)), 5];

_object addAction [LLSTRING(giveEODUnitTrait), {
	params ["_target", "_caller", "_actionId"];
	[_caller, "eod", true] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE(!((_player getVariable [ARR_2('ace_isEngineer', 0)]) > 0)), 5];

_object addAction [LLSTRING(removeMedicalUnitTrait), {
	params ["_target", "_caller", "_actionId"];
	[_caller, "medic", false] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE((_player getVariable [ARR_2('ace_medical_medicclass', 0)]) > 0), 5];

_object addAction [LLSTRING(removeEODUnitTrait), {
	params ["_target", "_caller", "_actionId"];
	[_caller, "eod", false] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE((_player getVariable [ARR_2('ace_isEngineer', 0)]) > 0), 5];
