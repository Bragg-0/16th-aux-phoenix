#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Extract player data from the database
	 *
	 * Arguments:
	 * 0: _players (optional,default: player) <OBJECT> - The player to extract data for
	 *
	 * Return Value:
     * <NONE> //? <HASHMAP> - Player data is stored on the player object and can be accessed using `player getVariable "pc_database_playerData"`
	 *
	 * Example:
	 * [player] call pc_database_fnc_extractPlayerData
	 *
	 * Public: No
 */

params [
	["_player",player,[player]]
];

TRACE_1("fn_savePlayerData",_this);

// Vérification si le joueur est valide
if !(isPlayer _player) exitWith {};

// Récupération de l'UID du joueur
private _uid = getPlayerUID _player;

[
	-1,// Server execution
	{
		params ["_uid","_player"];

		// Prépare la requête
		private _query = FORMAT_1("getPlayerData:%1",_uid);
		TRACE_1("fn_extractPlayerData Query",_query);

		// Exécute la requête
		private _return = [_query,2,true] call FUNC(asyncCall);

		// Traitement du résultat
		TRACE_1("fn_extractPlayerData PreProcess",_return);
		_return = ((_return select 0) select 0);
		TRACE_1("fn_extractPlayerData PostProcess",_return);

		// Création de la hashmap
		private _hashmap = [
			"uid",
			"name",
			"loadout",
			"isMedic",
			"isEOD"
		] createHashMapFromArray _return;

		// Sauvegarde des données du joueur
		TRACE_1("fn_extractPlayerData Save",_hashmap);
		_player setVariable [QGVAR(playerData),_hashmap];
	},
	[_uid,_player]
] call CBA_fnc_globalExecute;
