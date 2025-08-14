#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Update player data in the database
	 *
	 * Arguments:
	 * 0: _player <OBJECT> - The player to update data for
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call pc_database_fnc_updatePlayerData //! Need to be executed by the server
	 *
	 * Public: No
 */

params [
	["_player",objNull,[objNull]]
];

if !(isDedicated) exitWith {
    WARNING("fn_updatePlayerData: This function must be called on the server");
};

if ((isNull _player) || !(isPlayer _player)) exitWith {
    WARNING("fn_updatePlayerData: Invalid player object");
};

TRACE_1("fn_updatePlayerData",_this);

// Récupération de l'UID du joueur
private _uid = getPlayerUID _player;

// Récupération des données du joueur
private _name = str (name _player);
private _isMedic = parseNumber (_player getUnitTrait "medic");
private _isEOD = parseNumber (_player getUnitTrait "explosiveSpecialist");
private _loadout = FORMAT_1("'%1'",getUnitLoadout [ARR_2(_player,true)]);
private _lastOnline = [systemTimeUTC#0,systemTimeUTC#1,systemTimeUTC#2,systemTimeUTC#3 + 2,systemTimeUTC#4,systemTimeUTC#5]; // UTC+2 (Europe/Paris)

// Création de la chaîne de données
private _data = FORMAT_5("%1:%2:%3:%4:%5",_name,_isMedic,_isEOD,_loadout,_lastOnline);

// Prépare la requête
private _query = FORMAT_2("insertOrUpdateUserBySteamId:%1:%2",_uid,_data);
TRACE_1("fn_updatePlayerData Query",_query);

// Exécute la requête
[_query] call FUNC(asyncCall);
