#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Update the ear protection state for a player
	 *
	 * Arguments:
	 * 0: _player <OBJECT> - The player object
	 * 1: _state <BOOLEAN> - The new state (false = deactivate, true = activate)
	 *
	 * Return Value:
	 * Return description <NONE>
	 *
	 * Example:
	 * [player, true] call pc_missions_fnc_updateEarProtection
	 *
	 * Public: No
 */

params [
	["_player", objNull, [objNull]],
	["_state", false, [false]]
];

TRACE_1("fnc_updateEarProtection",_this);

if (isNull _player) exitWith {
    WARNING_1("fnc_updateEarProtection: %1 is null",_player);
};

if (!hasInterface) exitWith {
    WARNING("fnc_updateEarProtection: Interface is not available");
};

_player setVariable [QGVAR(earProtection), _state, true];

if (_state) then {
    // Ear protection activated
    0 fadeSound 0.2;
} else {
    // Ear protection deactivated
    0 fadeSound 1;
};
