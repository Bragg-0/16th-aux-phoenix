#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) };
        units[] = {
            QESUBGVAR(I,Mk1),
            QESUBGVAR(I,Mk1Lights),
            QESUBGVAR(I,Mk2),
            QESUBGVAR(I,Mk2Lights),
            QSUBGVAR(C)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
