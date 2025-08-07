#define BACKPACKS_BASE                              \
        Author = AUTHOR;                            \
        scopeCurator = 1;                           \
        scopeArsenal = 2;                           \
        scope = 2;                                  \
        editorCategory = QEGVAR(main,3den);         \
        editorSubcategory = "EdSubcat_Backpacks";   \
        mass = 50

#define CLASS_MEDIC_BACKPACK(var1)                                          \
    class ECVAR(var1,Medic) : ls_gar_heavyMedic_backpack {                  \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,HeavyMedic));                   \
        maximumLoad = 500;                                                  \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_Medic_co.paa),                  \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\cover_co.paa",     \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\pouches_co.paa",   \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\medic_co.paa",     \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\medic_co.paa"      \
        };                                                                  \
    }

#define CLASS_STANDARD_BACKPACK(var1)                                       \
    class ECVAR(var1,Standard) : ls_gar_heavy_backpack {                    \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Heavy));                        \
        maximumLoad = 500;                                                  \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_co.paa),    \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\cover_co.paa",     \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\pouches_co.paa",   \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\tube_co.paa"       \
        };                                                                  \
    }

#define CLASS_RADIO_BACKPACK(var1)                                          \
    class ECVAR(var1,Radio) : ls_gar_mediumRadio_backpack {                 \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Radio));                        \
        maximumLoad = 300;                                                  \
        backpackClass = QECVAR(var1,Radio);                                 \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_co.paa),    \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\radio_co.paa",     \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\screen_co.paa",    \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\pouches_co.paa"    \
        };                                                                  \
    }

#define CLASS_ROCKET_BACKPACK(var1)                                         \
    class ECVAR(var1,Rocket) : ls_gar_rocket_backpack {                     \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Rocket));                       \
        maximumLoad = 400;                                                  \
        backpackClass = QECVAR(var1,Rocket);                                \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_co.paa),                        \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\holder_co.paa",    \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\rocket_co.paa",    \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\light_co.paa",     \
			"\ls\core\addons\characters_clone_legacy\backpacks\standard\data\pouches_co.paa"    \
        };                                                                  \
    }

#define CLASS_INVISIBLE_BACKPACK(var1)                                      \
    class ECVAR(var1,Invisible) : ls_gar_heavy_backpack {                   \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Invisible));                    \
        maximumLoad = 300;                                                  \
        backpackClass = QECVAR(var1,Invisible);                             \
        hiddenSelectionsTextures[] = {};                                    \
    }
