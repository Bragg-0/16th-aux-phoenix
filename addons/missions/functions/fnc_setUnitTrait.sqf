#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: set unit trait
	 *
	 * Arguments:
	 * 0: _unit <OBJECT> - The unit to set the trait for
	 * 1: _trait <STRING> - The trait to set
	 * 2: _value (optional, default: true) <BOOL> - The value to set the trait to
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [params] call pc_missions_fnc_setUnitTrait
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]],
	["_trait", "", [""]],
	["_value", true, [true]]
];

TRACE_1("fnc_setUnitTrait",_this);

if (isNull _unit) exitWith {
	WARNING_1("fnc_setUnitTrait: %1 is null",_unit);
};

private _medicalTrait = {
	params ["_unit", "_value", "_lvlValue"];
	_unit setVariable ["ace_medical_medicclass", _lvlValue, true];
	_unit setUnitTrait ["Medic", _value];
};

private _eodTrait = {
	params ["_unit", "_value", "_lvlValue"];
	_unit setVariable ["ace_isEngineer", _lvlValue, true];
	_unit setUnitTrait ["Engineer", _value];
	_unit setVariable ["ace_isExplosiveSpecialist", _value, true];
	_unit setUnitTrait ["ExplosiveSpecialist", _value];
};

if (_trait isNotEqualTo "") then {
	private _lvlValue = 2;
	if (!_value) then {
		_lvlValue = 0;
	};

	switch (_trait) do {
		case "medic": {
            [_unit, _value, _lvlValue] call _medicalTrait;
        };
		case "eod": {
			[_unit, _value, _lvlValue] call _eodTrait;
		};
		case "all": {
            [_unit, _value, _lvlValue] call _medicalTrait;
			[_unit, _value, _lvlValue] call _eodTrait;
		};
		default {
			WARNING_1("fnc_setUnitTrait: Unknown trait %1",_trait);
		};
	};
} else {
	WARNING("fnc_setUnitTrait: Trait is empty");
};
