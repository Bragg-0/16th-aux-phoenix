#include "script_component.hpp"

if (hasInterface) then {
	[player] call FUNC(initUnderfire);
	[player] call FUNC(initEarProtection);
	[player] call FUNC(loadPlayer);
};

if (isServer) then {
	[] call FUNC(initFortify);

	// Warning if mission version is different than server version
	private _serverVersion = [VERSION_AR];
	private _version = getMissionConfigValue ["pc_missions_version",[0,0,0]];
	if (_version isNotEqualTo _serverVersion) then {
		if (isDedicated) then {
            ERROR_6("Mission version mismatch! Server version: %1.%2.%3 - Mission version: %4.%5.%6",_serverVersion#0,_serverVersion#1,_serverVersion#2,_version#0,_version#1,_version#2);
			forceEnd;
		} else {
			[
				{
					params ["_serverVersion","_missionVersion"];
					WARNING_6("Mission version mismatch! Server version: %1.%2.%3 - Mission version: %4.%5.%6",_serverVersion#0,_serverVersion#1,_serverVersion#2,_missionVersion#0,_missionVersion#1,_missionVersion#2);
					["Mission version mismatch!",["",FORMAT_6("Server version: %1.%2.%3 - Mission version: %4.%5.%6",_serverVersion#0,_serverVersion#1,_serverVersion#2,_missionVersion#0,_missionVersion#1,_missionVersion#2)]] call BIS_fnc_showNotification;
				},10,[_serverVersion,_version]
			] call CBA_fnc_addPerFrameHandler;
		};
	};
};
