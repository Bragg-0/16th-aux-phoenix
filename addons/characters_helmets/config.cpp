#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) };
        units[] = {
            // Regs
                #define CHARACTERS_TYPE Regs
                QECVARF(Shiny,P2),
                QECVARF(Shiny,P2_Pilot),
                QECVARF(Trooper,P2),
                QECVARF(Trooper,P2_Pilot),
                #undef CHARACTERS_TYPE

            // Customs
                #define CHARACTERS_TYPE Customs
                //* Add the class names for custom vests here
                #undef CHARACTERS_TYPE
        };
        weapons[] = {
            // Regs
                #define CHARACTERS_TYPE Regs
                QECVAR(Shiny,P2),
                QECVAR(Shiny,P2_Pilot),
                QECVAR(Trooper,P2),
                QECVAR(Trooper,P2_Pilot),
                #undef CHARACTERS_TYPE

            // Customs
                #define CHARACTERS_TYPE Customs
                //* Add the class names for custom vests here
                #undef CHARACTERS_TYPE
        };
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class Headgear_Base_F;
    #include "CfgVehicles_Regs.hpp"
    #include "CfgVehicles_Customs.hpp"
};

class CfgWeapons {
    CLASS_INHERITANCE(ls_gar_phase2_helmet);
    CLASS_INHERITANCE(ls_gar_phase2Pilot_helmet);
    #include "CfgWeapons_Regs.hpp"
    #include "CfgWeapons_Customs.hpp"
};
