#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Loads the player's inventory and equipment.
	 *
	 * Arguments:
	 * 0: _unit <OBJECT> - The unit to load inventory and equipment for.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call pc_missions_fnc_loadPlayer
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

TRACE_1("fnc_loadPlayer",_this);

if !(isDedicated) exitWith {
    WARNING("fnc_loadPlayer: This function must be called on the server");
};

if (isNull _unit || !isPlayer _unit) exitWith {
	WARNING_1("fnc_loadPlayer: Invalid player object %1",_unit);
};

[_unit] remoteExecCall [QEFUNC(database,extractPlayerData), 2];

[{
    // Check if the player data exists
    params ["_unit"];
    count (_unit getVariable [QEGVAR(database,playerData), []]) > 0
}, {
    // Load the player data
    params ["_unit"];
    private _playerData = _unit getVariable [QEGVAR(database,playerData), []];

    private _isMedic = _playerData get "isMedic";
    private _isEOD = _playerData get "isEOD";
    private _loadout = _playerData get "loadout";

    [_unit,"medic",_isMedic] call FUNC(setUnitTrait);
    [_unit,"eod",_isEOD] call FUNC(setUnitTrait);

    _unit setUnitLoadout [_loadout, true];

}, [_unit]] call CBA_fnc_waitUntilAndExecute;
