class CfgVehicles {

    // LAAT_I
    class 3as_LAAT_Mk1;
    class 3as_LAAT_Mk1Lights;
    class 3as_LAAT_Mk2;
    class 3as_LAAT_Mk2Lights;

    class ESUBGVAR(I,Mk1) : 3as_LAAT_Mk1 {
        BASE_LAAT;
        displayName = SUBCSTRING(I_Mk1);
        TEXTURES_LAAT_I;
    };

    class ESUBGVAR(I,Mk1Lights) : 3as_LAAT_Mk1Lights {
        BASE_LAAT;
        displayName = SUBCSTRING(I_Mk1Lights);
        TEXTURES_LAAT_I;
    };

    class ESUBGVAR(I,Mk2) : 3as_LAAT_Mk2 {
        BASE_LAAT;
        displayName = SUBCSTRING(I_Mk2);
        TEXTURES_LAAT_I;
    };

    class ESUBGVAR(I,Mk2Lights) : 3as_LAAT_Mk2Lights {
        BASE_LAAT;
        displayName = SUBCSTRING(I_Mk2Lights);
        TEXTURES_LAAT_I;
    };

    // LAAT_C
    class 3AS_LAATC;
    class SUBGVAR(C) : 3AS_LAATC {
        BASE_LAAT;
        displayName = SUBCSTRING(C);
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\LAAT_C\Hull_var0_co.paa)
        };
        class textureSources {
            class SUBGVAR(texture_0) {
                displayName = SUBCSTRING(C_texture_0);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\LAAT_C\Hull_var0_co.paa)
                };
            };
            class SUBGVAR(texture_1) {
                displayName = SUBCSTRING(C_texture_1);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\LAAT_C\Hull_var1_co.paa)
                };
            };
        };
        textureList[] = {
            QSUBGVAR(texture_0), 1,
            QSUBGVAR(texture_1), 1
        };
    };
};
