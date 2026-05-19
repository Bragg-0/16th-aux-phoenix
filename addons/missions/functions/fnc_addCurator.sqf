#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Create a Zeus module and assign it to the player
	 *
	 * Arguments:
	 * 0: _player (default: objNull) <OBJECT> - The player to assign the Zeus module to
	 *
	 * Return Value:
	 * Boolean - true if the Zeus module was successfully created and assigned, false otherwise
	 *
	 * Example:
	 * [player] call pc_missions_fnc_addCurator
	 *
	 * Public: No
 */

params [["_player", objNull, [objNull]]];
TRACE_1("fnc_addCurator",_this);

if (!isServer) exitWith {
	WARNING("fnc_addCurator: This function must be executed on the server");
	false
};

if (isNull _player) exitWith {
    [{
        !isNull _player && {isPlayer _player}
    }, {
        [_player] call FUNC(loadPlayer);
    }] call CBA_fnc_waitUntilAndExecute;
};

// Création du module Zeus
private _curator = (createGroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, "NONE"];

// Attribution au joueur
_curator assignCurator _player;

// Tous les addons
_curator addCuratorAddons (configProperties [configFile >> "CfgPatches", "true", true] apply {
	configName _x
});

INFO_1("fnc_addCurator: curator created and assigned to player %1",name _player);

true
