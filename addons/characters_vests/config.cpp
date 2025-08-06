#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) };
        units[] = {};
        weapons[] = {
            // Regs
                #define CHARACTERS_TYPE Regs
                QECVAR(Base,ARF),
                QECVAR(Base,Engineer),
                QECVAR(Base,EngineerNCO),
                QECVAR(Base,ForceReconNCO),
                QECVAR(Base,Hazard),
                QECVAR(Base,Heavy),
                QECVAR(Base,ARCPlate),
                QECVAR(Base,Assault),
                QECVAR(Base,CFR),
                QECVAR(Base,Grenadier),
                QECVAR(Base,Kama),
                QECVAR(Base,Lieutenant),
                QECVAR(Base,Medic),
                QECVAR(Base,Officer),
                QECVAR(Base,Recon),
                QECVAR(Base,ReconNCO),
                QECVAR(Base,Specialist),
                QECVAR(Base,Clone),
                #undef CHARACTERS_TYPE

            // Customs
                #define CHARACTERS_TYPE Customs
                //* Add the class names for custom vests here
                #undef CHARACTERS_TYPE
        };
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    CLASS_INHERITANCE(ls_gar_arf_vest);
    CLASS_INHERITANCE(ls_gar_engineer_vest);
    CLASS_INHERITANCE(ls_gar_engineerNCO_vest);
    CLASS_INHERITANCE(ls_gar_forceReconNCO_vest);
    CLASS_INHERITANCE(ls_gar_hazard_vest);
    CLASS_INHERITANCE(ls_gar_heavy_vest);
    CLASS_INHERITANCE(ls_gar_arc_vest);
    CLASS_INHERITANCE(ls_gar_assault_vest);
    CLASS_INHERITANCE(ls_gar_cfr_vest);
    CLASS_INHERITANCE(ls_gar_grenadier_vest);
    CLASS_INHERITANCE(ls_gar_lieutenant_vest);
    CLASS_INHERITANCE(ls_gar_medic_vest);
    CLASS_INHERITANCE(ls_gar_officer_vest);
    CLASS_INHERITANCE(ls_gar_recon_vest);
    CLASS_INHERITANCE(ls_gar_reconNCO_vest);
    CLASS_INHERITANCE(ls_gar_specialist_vest);
    CLASS_INHERITANCE(ls_gar_clone_vest);
    CLASS_INHERITANCE(ls_gar_kama_vest);

    #include "CfgWeapons_Regs.hpp"
    #include "CfgWeapons_Customs.hpp"
};
