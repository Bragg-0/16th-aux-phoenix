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
                QCVARF(Shiny),
                QECVARF(Shiny,EOD),
                QECVARF(Shiny,Medic),
                QCVARF(Trooper),
                QECVARF(Trooper,EOD),
                QECVARF(Trooper,Medic),
                #undef CHARACTERS_TYPE

            // Customs
                #define CHARACTERS_TYPE Customs
                //* Add the class names for custom vests here
                #undef CHARACTERS_TYPE
        };
        weapons[] = {
            // Regs
                #define CHARACTERS_TYPE Regs
                QCVAR(Shiny),
                QECVAR(Shiny,EOD),
                QECVAR(Shiny,Medic),
                QCVAR(Trooper),
                QECVAR(Trooper,EOD),
                QECVAR(Trooper,Medic),
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
    class lsd_gar_phase2_base;
    #include "CfgVehicles_Regs.hpp"

};

class CfgWeapons {
    CLASS_INHERITANCE(ls_gar_phase2_uniform);
    #include "CfgWeapons_Regs.hpp"

};
