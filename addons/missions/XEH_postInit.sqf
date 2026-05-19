#include "script_component.hpp"

if (hasInterface) then {
	[player] call FUNC(initUnderfire);
	[player] call FUNC(initEarProtection);
	[player] call FUNC(loadPlayer);
};

if (isServer) then {
	[] call FUNC(initFortify);

	// Warning if mission version is different than server version
	private _version = getMissionConfigValue ["pc_missions_version", [0, 0, 0]];
	if (_version isEqualTo [VERSION_AR]) then {
        [
            {
                WARNING_6("Mission version mismatch! Server version: %1.%2.%3 - Mission version: %4.%5.%6",[VERSION_AR]#0,[VERSION_AR]#1,[VERSION_AR]#2,_this#0,_this#1,_this#2);
                ["Mission version mismatch!", ["", FORMAT_6("Server version: %1.%2.%3 - Mission version: %4.%5.%6",[VERSION_AR]#0,[VERSION_AR]#1,[VERSION_AR]#2,_this#0,_this#1,_this#2)]] call BIS_fnc_showNotification;
            }, 10, _version
        ] call CBA_fnc_addPerFrameHandler;
	};
};

if (isDedicated) then {
	[10, 6, 22, 30] call FUNC(autoPayment);// add 10 money, every saturday at 22:30 to allPlayer;

	// stop mission if mission version is different than server version
	private _version = getMissionConfigValue ["pc_missions_version", [0, 0, 0]];
	if (_version isEqualTo [VERSION_AR]) then {
		forceEnd;
	};
};
