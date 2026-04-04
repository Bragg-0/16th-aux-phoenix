#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(MAIN_ADDON), "ace_medical" };
        units[] = {};
        weapons[] = {
            QGVAR(Splint),
            QGVAR(SurgicalKit),
            QGVAR(PersonalAidKit),
            QGVAR(Epinephrine),
            QGVAR(Adenosine),
            QGVAR(Morphine),
            QGVAR(PackingBandage),
            QGVAR(ElasticBandage),
            QGVAR(Quikclot),
            QGVAR(BloodIV),
            QGVAR(BloodIV_250),
            QGVAR(BloodIV_500),
            QGVAR(SalineIV),
            QGVAR(SalineIV_250),
            QGVAR(SalineIV_500),
            QGVAR(PlasmaIV),
            QGVAR(PlasmaIV_250),
            QGVAR(PlasmaIV_500)
        };
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "ACE_Medical_Treatment.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"

#include "CfgWeapons.hpp"

#include "CfgMagazines.hpp"
