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

if !(hasInterface) exitWith {
    WARNING("fnc_loadPlayer: This function must be called on a client");
};

if (isNull _unit) exitWith {
    [{
        !isNull player && {isPlayer player}
    }, {
        [player] call FUNC(loadPlayer);
    }] call CBA_fnc_waitUntilAndExecute;
};

if (isNull _unit || !isPlayer _unit) exitWith {
	WARNING_1("fnc_loadPlayer: Invalid player object %1",_unit);
};

_unit setVariable [QEGVAR(database,playerDataLoaded), false, true];
[_unit] remoteExecCall [QEFUNC(database,extractPlayerData), 2];

[{
    // Check if the player data exists
    params ["_unit"];
    _unit getVariable [QEGVAR(database,playerDataLoaded), false]
}, {
    // Load the player data
    params ["_unit"];
    private _playerData = _unit getVariable [QEGVAR(database,playerData), createHashMap];
    if !(_playerData isEqualType createHashMap) exitWith {
        WARNING_1("fnc_loadPlayer: Invalid player data for %1",_unit);
    };

    private _isMedic = _playerData getOrDefault ["isMedic", false];
    private _isEOD = _playerData getOrDefault ["isEOD", false];
    private _loadout = _playerData getOrDefault ["loadout", []];

    [_unit,"medic",_isMedic] call FUNC(setUnitTrait);
    [_unit,"eod",_isEOD] call FUNC(setUnitTrait);

    if !(_loadout isEqualType []) exitWith {
        WARNING_1("fnc_loadPlayer: Invalid loadout for %1",_unit);
    };

    if (_loadout isEqualTo []) exitWith {
        WARNING_1("fnc_loadPlayer: No saved loadout for %1",_unit);
    };

    _unit setUnitLoadout [_loadout, true];

}, [_unit]] call CBA_fnc_waitUntilAndExecute;
