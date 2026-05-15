#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Extract player data from the database
	 *
	 * Arguments:
	 * 0: _players <OBJECT> - The player to extract data for
	 *
	 * Return Value:
     * <NONE> //? <HASHMAP> - Player data is stored on the player object and can be accessed using `player getVariable "pc_database_playerData"`
	 *
	 * Example:
	 * [player] call pc_database_fnc_extractPlayerData //! Need to be executed by the server
	 *
	 * Public: No
 */

params [
	["_player",objNull,[objNull]]
];

if !(isDedicated) exitWith {
    WARNING("fn_extractPlayerData: This function must be called on the server");
};

if ((isNull _player) || !(isPlayer _player)) exitWith {
    WARNING("fn_extractPlayerData: Invalid player object");
};

TRACE_1("fn_extractPlayerData",_this);

// Récupération de l'UID du joueur
private _uid = getPlayerUID _player;

// Prépare la requête
private _query = FORMAT_1("getPlayerProfileBySteamId:%1",_uid);
TRACE_1("fn_extractPlayerData Query",_query);

// Exécute la requête
private _return = [_query,2,true] call FUNC(asyncCall);

// Traitement du résultat
TRACE_1("fn_extractPlayerData PreProcess",_return);
if !(_return isEqualType []) exitWith {
    WARNING("fn_extractPlayerData: Invalid database response");
};

if (_return isEqualTo []) exitWith {
    INFO("fn_extractPlayerData New Player, updating database");
    [_player] call FUNC(updatePlayerData);
};

_return = _return param [0, []];
TRACE_1("fn_extractPlayerData PostProcess",_return);

if (_return isEqualTo []) exitWith {
    INFO("fn_extractPlayerData New Player, updating database");
    [_player] call FUNC(updatePlayerData);
};

// Création de la hashmap
private _hashmap = [
    "money",
    "grade",
    "isMedic",
    "isEOD",
    "loadout"
] createHashMapFromArray _return;

// Traitement des données pour les mettre à format utilisable par arma 3
private _isMedic = (_hashmap getOrDefault ["isMedic", 0]) isEqualTo 1;
private _isEod = (_hashmap getOrDefault ["isEOD", 0]) isEqualTo 1;
private _loadout = _hashmap getOrDefault ["loadout", "[]"];

_hashmap set ["isMedic", _isMedic];
_hashmap set ["isEOD", _isEod];
if (_loadout isEqualType "") then {
    _hashmap set ["loadout", call compile _loadout];
} else {
    _hashmap set ["loadout", _loadout];
};

if (count (_hashmap get "loadout") == 0) then {
    // if loadout is empty == is a new player
    INFO("fn_extractPlayerData New Player, updating database");
    [_player] call FUNC(updatePlayerData);
} else {
    // if loadout is not empty == is an existing player
    // Sauvegarde des données du joueur
    TRACE_1("fn_extractPlayerData Save",_hashmap);
    _player setVariable [QGVAR(playerData), _hashmap, true];
};
