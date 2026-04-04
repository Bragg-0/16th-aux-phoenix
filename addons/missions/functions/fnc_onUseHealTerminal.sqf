#include "..\script_component.hpp"
/*
    * Authors: Bragg
    * Description: Use a heal terminal
    *
    * Arguments:
    * 0: _target (default: ObjNull) <OBJECT> - The player using the heal terminal.
    * 1: _object (default: ObjNull) <OBJECT> - The object on which the heal terminal is initialized.
    *
    * Return Value:
    * <NONE>
    *
    * Example:
    * [player, this] call pc_missions_fnc_onUseHealTerminal
    *
    * Public: No
 */

params [
    ["_target",objNull,[objNull]],
    ["_object",objNull,[objNull]]
];

TRACE_1("fnc_onUseHealTerminal",_this);

[
    LLSTRING(ReceivingMedicalTreatment),
    5,
    {
        _this#0 params ["_target", "_object"];
        (_target distance _object) < 5
    },
    {
        _this#0 params ["_target"];
        [_target, false, 5, true] call ace_medical_fnc_setUnconscious;
        [_target] call ace_medical_treatment_fnc_fullHealLocal;
    }, {}, [_target, _object], false, false, true
] call CBA_fnc_progressBar;
