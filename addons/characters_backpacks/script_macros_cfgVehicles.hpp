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
        picture = QPATHTOEF(characters,data\backpacks\medic_ca.paa);        \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_co.paa),    \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Cover_co.paa),       \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Pouches_co.paa),     \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Medic_co.paa),       \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Medic_co.paa)        \
        };                                                                  \
    }

#define CLASS_STANDARD_BACKPACK(var1)                                       \
    class ECVAR(var1,Standard) : ls_gar_heavy_backpack {                    \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Heavy));                        \
        maximumLoad = 500;                                                  \
        picture = QPATHTOEF(characters,data\backpacks\heavy_ca.paa);        \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_co.paa),    \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Cover_co.paa),       \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Pouches_co.paa),     \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Tube_co.paa)         \
        };                                                                  \
    }

#define CLASS_RADIO_BACKPACK(var1)                                          \
    class ECVAR(var1,Radio) : ls_gar_mediumRadio_backpack {                 \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Radio));                        \
        maximumLoad = 300;                                                  \
        picture = QPATHTOEF(characters,data\backpacks\radio_ca.paa);        \
        backpackClass = QECVAR(var1,Radio);                                 \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_co.paa),    \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Radio_co.paa),       \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Screen_co.paa),      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Pouches_co.paa)      \
        };                                                                  \
    }

#define CLASS_ROCKET_BACKPACK(var1)                                         \
    class ECVAR(var1,Rocket) : ls_gar_rocket_backpack {                     \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Rocket));                       \
        maximumLoad = 400;                                                  \
        picture = QPATHTOEF(characters,data\backpacks\rocket_ca.paa);       \
        backpackClass = QECVAR(var1,Rocket);                                \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Backpack_co.paa),    \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Holder_co.paa),      \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Rocket_co.paa),      \
            "#(rgb,8,8,3)color(1,0,0,1)",                                   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_Pouches_co.paa)      \
        };                                                                  \
    }

#define CLASS_INVISIBLE_BACKPACK(var1)                                      \
    class ECVAR(var1,Invisible) : ls_gar_heavy_backpack {                   \
        BACKPACKS_BASE;                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Invisible));                    \
        maximumLoad = 300;                                                  \
        picture = QPATHTOEF(characters,data\backpacks\invisible_ca.paa);    \
        backpackClass = QECVAR(var1,Invisible);                             \
        hiddenSelectionsTextures[] = {};                                    \
    }
