class CfgVehicles {
    class Man;

    class CAManBase : Man {
        class ACE_SelfActions {
            class GVAR(activateEarProtection) {
                displayName = CSTRING(activateEarProtection);
                condition = QUOTE([ARR_2(_player,1)] call FUNC(canEarProtection));
                statement = QUOTE([ARR_2(_player,true)] call FUNC(updateEarProtection));
                icon = QPATHTOF(data\waves_ca.paa);
            };
            class GVAR(deactivateEarProtection) {
                displayName = CSTRING(deactivateEarProtection);
                condition = QUOTE([ARR_2(_player,0)] call FUNC(canEarProtection));
                statement = QUOTE([ARR_2(_player,false)] call FUNC(updateEarProtection));
                icon = QPATHTOF(data\unwaves_ca.paa);
            };
        };
    };
};
