#include "script_component.hpp"

class CfgPatches {
    class cba_settings_userconfig {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(MAIN_ADDON), "cba_settings" };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};
