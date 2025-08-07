#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON), "PC_Characters_Vests" };
        units[] = {};
        weapons[] = {
            // Customs
                #define CHARACTERS_TYPE Customs
                    QECVAR(1298,CommanderNVG)
                #undef CHARACTERS_TYPE
        };
        glasses[] = {
            // Customs
                #define CHARACTERS_TYPE Customs
                    QECVAR(0770,EngineerNCO),
                    QECVAR(1298,Engineer)
                #undef CHARACTERS_TYPE
        };
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    class lsd_gar_p2Commander_v3_nvg;

    #include "CfgWeapons_Customs.hpp"
};

class CfgGlasses {
    class None;

    #include "CfgGlasses_Customs.hpp"
};
