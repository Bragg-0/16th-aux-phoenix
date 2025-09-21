#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Initialize a heal terminal on an object
 *
 * Arguments:
 * 0: _object (default: ObjNull) <OBJECT> - The object on which the heal terminal will be initialized.
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [this] call pc_missions_fnc_initHealTerminal
 *
 * Public: No
 */

params [
    ["_object",objNull,[objNull]]
];

TRACE_1("fnc_initHealTerminal",_this);

_actionId = _object addAction [LLSTRING(HealTerminal), {
	params ["_target", "_caller"];
	[_caller, _target] call FUNC(onUseHealTerminal);
}, nil, 1.5, true, true, "", "true", 5, false, "", ""];

_object setUserActionText [_actionId, LLSTRING(HealTerminal), QUOTE(<img size='3' image=QUOTE(QPATHTOF(data\medic_ca.paa))/>)];
