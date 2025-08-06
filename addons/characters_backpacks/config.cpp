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
                QECVAR(Base,Medic),
                QECVAR(Base,Standard),
                QECVAR(EOD,Standard),
                QECVAR(Base,Radio),
                QECVAR(Base,Rocket),
                QECVAR(Base,Invisible),
                #undef CHARACTERS_TYPE

            // Customs
                #define CHARACTERS_TYPE Customs
                //* Add the class names for custom vests here
                #undef CHARACTERS_TYPE
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class ls_gar_heavyMedic_backpack;
    class ls_gar_heavy_backpack;
    class ls_gar_mediumRadio_backpack;
    class ls_gar_rocket_backpack;
    #include "CfgVehicles_Regs.hpp"
    #include "CfgVehicles_Customs.hpp"
};
