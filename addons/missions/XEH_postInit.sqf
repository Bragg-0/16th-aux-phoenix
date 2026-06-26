#include "script_component.hpp"

if (isServer) then {
    [] call FUNC(initCheckVersion);
	[] call FUNC(initFortify);
};

if (hasInterface) then {
	[player] call FUNC(initUnderfire);
	[player] call FUNC(initEarProtection);
	[player] call FUNC(loadPlayer);
};
