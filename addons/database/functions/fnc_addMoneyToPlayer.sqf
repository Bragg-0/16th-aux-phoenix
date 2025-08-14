#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Adds money to a player
 *
 * Arguments:
 * 0: _player <OBJECT> - The player object to add money to
 * 1: _amount <NUMBER> - The amount of money to add
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [player] call pc_database_fnc_addMoneyToPlayer //! Need to be executed by the server
 *
 * Public: No
 */

params [
    ["_player",objNull,[objNull]],
    ["_amount",0,[0]]
];

if !(isDedicated) exitWith {
    WARNING("fn_updatePlayerData: This function must be called on the server");
};

if ((isNull _player) || !(isPlayer _player)) exitWith {
    WARNING("fn_updatePlayerData: Invalid player object");
};

TRACE_1("fnc_addMoneyToPlayer",_this);

// Récupération de l'UID du joueur
private _uid = getPlayerUID _player;

// Prépare la requête
private _query = FORMAT_2("addMoneyToUserBySteamId:%1:%2",_uid,_amount);
TRACE_1("fnc_addMoneyToPlayer Query",_query);

// Exécution de la requête
[_query] call FUNC(asyncCall);
