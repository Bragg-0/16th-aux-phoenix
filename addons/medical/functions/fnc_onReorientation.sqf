#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Handles the reorientation of medical items.
	 *
	 * Arguments:
	 * 0: _medic (optional, default: objNull) <OBJECT> - The medic performing the treatment. (Not used in the function)
	 * 1: _patient <OBJECT> - The patient receiving the treatment.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player, player1] call PREFIX_medical_fnc_onReorientation
	 *
	 * Public: No
 */

params [
	["_medic", objNull, [objNull]],
	["_patient", objNull, [objNull]]
];

TRACE_1("fnc_onReorientation",_this);

if (isNull _patient) exitWith {
	WARNING("Invalid patient object.");
};

private _patientIsStable = [_patient] call ace_medical_status_fnc_hasStableVitals;

if (_patientIsStable && ((random 1) > 0.5)) then {
	[_patient, false, 5, true] call ace_medical_fnc_setUnconscious;
};
