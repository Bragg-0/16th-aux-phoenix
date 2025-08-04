#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        authors[] = { "Bragg" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "PC_Main", "ls_characters_clone_legacy" };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};
