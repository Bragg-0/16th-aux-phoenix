#define DEBUG_SYNCHRONOUS

#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\cba\addons\xeh\script_xeh.hpp"

/*
    Boolean
*/
#define TRUE 1
#define FALSE 0

/*
    Side
*/
#define OPFOR 0
#define BLUFOR 1
#define INDEPENDENT 2
#define CIVILIAN 3
#define UNKNOWN 8

/*
    Vehicule Transport Inventory
*/
#define MAG_XX(var1,var2)       \
    class _xx_##var1 {          \
        magazine = QUOTE(var1); \
        count = var2;           \
    }

#define WEAP_XX(var1,var2)      \
    class _xx_##var1 {          \
        weapon = QUOTE(var1);   \
        count = var2;           \
    }

#define ITEM_XX(var1,var2)      \
    class _xx_##var1 {          \
        name = QUOTE(var1);     \
        count = var2;           \
    }

#define EMPTY_ITEM class TransportItems { }

#define EMPTY_BACKPACK class TransportBackpacks { }

#define EMPTY_WEAPON class TransportWeapons { }

#define EMPTY_MAGAZINE class TransportMagazines { }

// Supply
#define SUPPLY_XX(var1) QUOTE(Supply##var1)

/*
    SubComponent
*/
#ifdef SUBCOMPONENT
    #undef PATHTOF
    #define PATHTOF(var1) PATHTOF_SYS(PREFIX,DOUBLES(COMPONENT,SUBCOMPONENT),var1)

    #define SUBGVAR(var1) DOUBLES(SUBADDON,var1)
    #define QSUBGVAR(var1) QUOTE(SUBGVAR(var1))

    #define ESUBGVAR(var1,var2) QUOTE(TRIPLES(ADDON,var1,var2))
    #define QESUBGVAR(var1,var2) QUOTE(ESUBGVAR(var1,var2))

    #define SUBFUNC(var1) TRIPLES(SUBADDON,fnc,var1)
    #define QSUBFUNC(var1) QUOTE(SUBFUNC(var1))
    #define QQSUBFUNC(var1) QUOTE(QSUBFUNC(var1))
#endif

/*
    Preprocessing and Compilation
*/
#undef PREP
#ifdef SUBCOMPONENT
    #define LINKFUNC(x) SUBFUNC(x)
    #define PREP(fncName) [ QPATHTOF(functions\DOUBLES(fnc,fncName).sqf),QSUBFUNC(fncName) ] call CBA_fnc_compileFunction
    #define PREP_RECOMPILE_START ; /* disabled */
    #define PREP_RECOMPILE_END ; /* disabled */
#else
    #define LINKFUNC(x) FUNC(x)
    #define PREP(fncName) [ QPATHTOF(functions\DOUBLES(fnc,fncName).sqf),QFUNC(fncName) ] call CBA_fnc_compileFunction
    #define PREP_RECOMPILE_START ; /* disabled */
    #define PREP_RECOMPILE_END ; /* disabled */
#endif

/*
    Material Light
*/
#define MATERIAL_LIGHT(var1) QPATHTOEF(main,data\rvmat\Light.rvmat)
