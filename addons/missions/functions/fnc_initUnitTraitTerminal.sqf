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
	[_target, "medic", true] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE(!(_this getUnitTrait 'medic')), 5];

_object addAction [LLSTRING(giveEODUnitTrait), {
	params ["_target", "_caller", "_actionId"];
	[_target, "eod", true] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE(!(_this getUnitTrait 'explosiveSpecialist')), 5];

_object addAction [LLSTRING(removeMedicalUnitTrait), {
	params ["_target", "_caller", "_actionId"];
	[_target, "medic", false] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE(_this getUnitTrait 'medic'), 5];

_object addAction [LLSTRING(removeEODUnitTrait), {
	params ["_target", "_caller", "_actionId"];
	[_target, "eod", false] call FUNC(setUnitTrait);
}, nil, 1.5, true, true, "", QUOTE(_this getUnitTrait 'explosiveSpecialist'), 5];
