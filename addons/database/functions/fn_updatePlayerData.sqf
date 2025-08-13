#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Update player data in the database
	 *
	 * Arguments:
	 * 0: _player (optional,default: player) <OBJECT> - The player to update data for
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call pc_database_fnc_updatePlayerData
	 *
	 * Public: No
 */

params [
	["_player",player,[player]]
];

TRACE_1("fn_updatePlayerData",_this);

// Vérification si le joueur est valide
if !(isPlayer _player) exitWith {};

// Récupération de l'UID du joueur
private _uid = getPlayerUID _player;

// Récupération des données du joueur
private _name = name _player;
private _loadout = str getUnitLoadout [_player,true];
private _isMedic = _player getUnitTrait "medic";
private _isEOD = _player getUnitTrait "explosiveSpecialist";

// Création de la chaîne de données
private _data = FORMAT_4("%1:%2:%3:%4",_name,_loadout,_isMedic,_isEOD);

[
	-1,// Server execution
	{
		params ["_uid","_player","_data"];
		// Prépare la requête
		private _query = FORMAT_2("insertOrUpdateUserBySteamId:%1:%2",_uid,_data);
		TRACE_1("fn_updatePlayerData Query",_query);

		// Exécute la requête
		[_query] call FUNC(asyncCall);
	},
	[_uid,_player,_data]
] call CBA_fnc_globalExecute;
