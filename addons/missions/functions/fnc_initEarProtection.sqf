#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Initialize ear protection for a player
	 *
	 * Arguments:
	 * 0: _player <OBJECT>
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call pc_missions_fnc_initEarProtection
	 *
	 * Public: No
 */

params [
	["_player", player, [objNull]]
];

TRACE_1("fnc_initEarProtection",_this);

_handle = [
	{
		params ["_player"];

		TRACE_1("fnc_initEarProtection",_player);
		private _state = _player getVariable [QGVAR(earProtection), false];
		if ((headgear _player) isEqualTo "") then {
			// Ear protection not worn
			0 fadeSound 1;
        } else {
			if (_state) then {
				// Ear protection activated
				0 fadeSound 0.2;
			} else {
				// Ear protection deactivated
				0 fadeSound 1;
			};
		};
	},
	0.1,
	_player
] call CBA_fnc_addPerFrameHandler;
