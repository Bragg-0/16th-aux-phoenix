#include "..\script_component.hpp"
/*
    * Authors: Bragg
    * Description: Check the mission version against the server version and warn if they are different
    *
    * Arguments:
    * <NONE>
    *
    * Return Value:
    * <NONE>
    *
    * Example:
    * [] call pc_missions_fnc_initCheckVersion
    *
    * Public: No
 */

if (!isMultiplayer) exitWith {};

if (isServer) then {
	if (!fileExists "description.ext") exitWith {
		ERROR("pc_missions_fnc_initCheckVersion: description.ext file not found.");
		QGVAR(missingDescriptionExt) call BIS_fnc_endMissionServer;
	};

    private _serverVersion = [VERSION_AR];
    private _missionVersion = getMissionConfigValue ["pc_missions_version",[0,0,0]];
    if (_missionVersion isNotEqualTo _serverVersion) then {
        ERROR_6("Mission version mismatch! Server version: %1.%2.%3 - Mission version: %4.%5.%6",_serverVersion#0,_serverVersion#1,_serverVersion#2,_missionVersion#0,_missionVersion#1,_missionVersion#2);
        if (isDedicated) then {
            QGVAR(missionVersionMismatch) call BIS_fnc_endMissionServer;
        } else {
            ["Mission version mismatch!",["",FORMAT_6("Server version: %1.%2.%3 - Mission version: %4.%5.%6",_serverVersion#0,_serverVersion#1,_serverVersion#2,_missionVersion#0,_missionVersion#1,_missionVersion#2)]] call BIS_fnc_showNotification;
        };
    };
};
