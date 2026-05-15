#include "script_component.hpp"

if (hasInterface) then {
	[player] call FUNC(initUnderfire);
	[player] call FUNC(initEarProtection);
	[player] call FUNC(loadPlayer);
};

if (isServer) then {
	[] call FUNC(initFortify);
};

if (isDedicated) then {
    [10, 6, 22, 30] call FUNC(autoPayment); //add 10 money, every saturday at 22:30 to allPlayer;
};
