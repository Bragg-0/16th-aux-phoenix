#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Sets up the database connection. (Should be run on the dedicated server)
	 *
	 * Arguments:
	 * <NONE>
	 *
	 * Return Value:
	     * <NONE>
	 *
	 * Example:
	 * [] call pc_database_fnc_init //! Need to be executed by the server
	 *
	 * Public: No
 */

if (isDedicated) then {
	// Vérifiez si la base de données est déjà connectée
	if (isNil {
		uiNamespace getVariable "JL_persistence_protocolID"
	}) then {
		/* get extDB3 version */
		private _ret = "extDB3" callExtension "9:VERSION";
		if (_ret == "") exitWith {
            WARNING("extDB3 - Initialization failed");
		};
        INFO_1("extDB3 - Version %1",_ret);

		/* Add database */
		_ret = call compile ("extDB3" callExtension format["9:ADD_DATABASE:%1", "phoenix"]);
		if (_ret select 0 == 0) exitWith {
            WARNING_1("extDB3 - Database error %1",_ret);
		};
        INFO("extDB3 - Database connected");

		/* Add custom SQL protocol */
		_ret = call compile ("extDB3" callExtension format["9:ADD_DATABASE_PROTOCOL:%1:SQL_CUSTOM:%2:a3phoenix.ini", "phoenix", "sqf"]);
		if (_ret select 0 == 0) exitWith {
			WARNING_1("extDB3 - Database error %1",_ret);
		};
		INFO("extDB3 - Custom protocol added");

		/* lock database */
		"extDB3" callExtension "9:LOCK";
		INFO("extDB3 - Database locked");

		/* Store protocol ID */
		uiNamespace setVariable ["JL_persistence_protocolID", _ret];

        /* Add per-frame handler */
        _handle = [
            {
                {
                    [_x] call FUNC(updatePlayerData);
                    INFO_1("Updated data for %1",name _x);
                } forEach allPlayers;
            }, 300
        ] call CBA_fnc_addPerFrameHandler;

        /* Add player Disconnect handler */
        addMissionEventHandler ["HandleDisconnect", {
            params ["_unit", "_id", "_uid", "_name"];
            [_unit] call FUNC(updatePlayerData);
        }];

        /* Add attendance handlers */
        addMissionEventHandler ["PlayerConnected", {
            params ["_id", "_uid", "_name"];

            if (_uid isEqualTo "") exitWith {
                TRACE_1("Skipping attendance for connection without Steam ID",_name);
            };

            [_uid] call FUNC(insertPlayerAttendance);
            INFO_2("Attendance opened for %1 (%2)",_name,_uid);
        }];

        addMissionEventHandler ["PlayerDisconnected", {
            params ["_id", "_uid", "_name"];
            [_uid] call FUNC(closePlayerAttendance);
            INFO_2("Attendance closed for %1 (%2)",_name,_uid);
        }];

        addMissionEventHandler ["Ended", {
            [] call FUNC(closeRecentAttendances);
            INFO("Recent open attendances closed at mission end");
        }];

        {
            private _uid = getPlayerUID _x;

            if (_uid isEqualTo "") then {
                TRACE_1("Skipping already connected player without Steam ID",name _x);
            } else {
                [_uid] call FUNC(insertPlayerAttendance);
                INFO_1("Attendance opened for already connected player %1",name _x);
            };
        } forEach allPlayers;

	} else {
	// La base de données est déjà connectée et le protocole est en place
		INFO("extDB3 - Database already connected");
	};
} else {
    // Si ce n'est pas un serveur dédié, on ne fait rien
    INFO("extDB3 - Not a dedicated server, skipping initialization");
};
