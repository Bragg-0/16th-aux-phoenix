#define BASE_LAAT                                    \
    author = AUTHOR;                                 \
    scope = 2;                                       \
    scopeCurator = 2;                                \
    faction = QEGVAR(Main,3den_FactionBlufor);       \
    editorSubcategory = QEGVAR(Main,Vehicles_Laat);  \
    side = BLUFOR;                                   \
    forceInGarage = 2;                               \
    cargoCanEject = 1;                               \
    crew = "PC_Units_Regs_Shiny_Pilot_F";            \
    EMPTY_BACKPACK;                                  \
    EMPTY_ITEM;                                      \
    EMPTY_WEAPON;                                    \
    EMPTY_MAGAZINE

#define TEXTURES_LAAT_I                                \
    hiddenSelections[] = { "camo" };                   \
    hiddenSelectionsTextures[] = {                     \
        QPATHTOF(data\LAAT_I\Hull_var0_co.paa)         \
    };                                                 \
    class textureSources {                             \
        class SUBGVAR(texture_0) {                     \
            displayName = SUBCSTRING(I_texture_0);     \
            author = AUTHOR;                           \
            textures[] = {                             \
                QPATHTOF(data\LAAT_I\Hull_var0_co.paa) \
            };                                         \
        };                                             \
        class SUBGVAR(texture_1) {                     \
            displayName = SUBCSTRING(I_texture_1);     \
            author = AUTHOR;                           \
            textures[] = {                             \
                QPATHTOF(data\LAAT_I\Hull_var1_co.paa) \
            };                                         \
        };                                             \
        class SUBGVAR(texture_2) {                     \
            displayName = SUBCSTRING(I_texture_2);     \
            author = AUTHOR;                           \
            textures[] = {                             \
                QPATHTOF(data\LAAT_I\Hull_var2_co.paa) \
            };                                         \
        };                                             \
    };                                                 \
    textureList[] = {                                  \
        QSUBGVAR(texture_0), 1,                        \
        QSUBGVAR(texture_1), 1,                        \
        QSUBGVAR(texture_2), 1                         \
    }
