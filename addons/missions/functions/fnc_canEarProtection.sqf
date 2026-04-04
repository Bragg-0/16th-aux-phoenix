#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Check if the player can use ear protection
	 *
	 * Arguments:
	 * 0: _player <OBJECT> - The player object
	 * 1: _state <NUMBER> - The test (0 = can deactivate ear protection ?, 1 = can activate ear protection ?)
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player, 1] call pc_missions_fnc_canEarProtection
	 *
	 * Public: No
 */

params [
	["_player", objNull, [objNull]],
	["_state", 0, [0]]
];

TRACE_1("fnc_canEarProtection",_this);

if (isNull _player) exitWith {
	WARNING_1("fnc_canEarProtection: %1 is null",_player);
    false
};

if (!hasInterface) exitWith {
	WARNING("fnc_canEarProtection: Interface is not available");
    false
};

if ((headgear _player) isEqualTo "") exitWith {
    TRACE_1("fnc_canEarProtection: %1 has no headgear",_player);
    false
};

private _earProtectionState = _player getVariable [QGVAR(earProtection), false];

private _canUpdateEarProtection = false;

switch (_state) do {
	case 0: {
		// Can deactivate ear protection
		_canUpdateEarProtection = _earProtectionState; // if ear protection is active, we can deactivate it
	};
	case 1: {
		// Can activate ear protection
		_canUpdateEarProtection = !_earProtectionState; // if ear protection is not active, we can activate it
	};
};

_canUpdateEarProtection
