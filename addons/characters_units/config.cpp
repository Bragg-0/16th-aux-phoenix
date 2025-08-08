#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON), "PC_characters_uniforms", "PC_characters_helmets", "PC_characters_backpacks", "PC_characters_vests", "JLTS_weapons_Z6", "3AS_Weapons"};
        units[] = {
            #define CHARACTERS_TYPE Regs
                QCVARF(Shiny),
                QECVARF(Shiny,EOD),
                QECVARF(Shiny,Medic),
                QECVARF(Shiny,Grenadier),
                QECVARF(Shiny,Heavy),
                QECVARF(Shiny,AT),
                QECVARF(Shiny,Pilot),
                QCVARF(Trooper),
                QECVARF(Trooper,EOD),
                QECVARF(Trooper,Medic),
                QECVARF(Trooper,Grenadier),
                QECVARF(Trooper,Heavy),
                QECVARF(Trooper,AT),
                QECVARF(Trooper,Pilot),
                QCVARF(Caporal),
                QCVARF(Sergent),
                QCVARF(Lieutenant)
            #undef CHARACTERS_TYPE
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
