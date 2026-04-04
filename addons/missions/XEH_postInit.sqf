#include "script_component.hpp"

if (hasInterface) then {
	[player] call FUNC(initUnderfire);
    [player] call FUNC(initEarProtection);
    [player] call FUNC(loadPlayer);
};

if (isServer) then {
    [player] call FUNC(initFortify);
};
