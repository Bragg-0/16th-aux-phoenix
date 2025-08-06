#define VESTS_BASE                              \
    author = AUTHOR;                            \
    scope = 2;                                  \
    scopeArsenal = 2;                           \
    class ItemInfo : ItemInfo {                 \
        mass = 40;                              \
        containerClass = SUPPLY_XX(100);        \
        class HitpointsProtectionInfo {         \
            class Chest {                       \
                hitpointName = "HitChest";      \
                armor = 12;                     \
                passThrough = 0.1;              \
            };                                  \
            class Diaphragm {                   \
                hitpointName = "HitDiaphragm";  \
                armor = 8;                      \
                passThrough = 0.2;              \
            };                                  \
            class Abdomen {                     \
                hitpointName = "HitAbdomen";    \
                armor = 8;                      \
                passThrough = 0.2;              \
            };                                  \
            class Body {                        \
                hitpointName = "HitBody";       \
                armor = 8;                      \
                passThrough = 0.2;              \
            };                                  \
            class Legs {                        \
                hitpointName = "HitLegs";       \
                armor = 10;                     \
                passThrough = 0.3;              \
            };                                  \
            class Arms {                        \
                hitpointName = "HitArms";       \
                armor = 10;                     \
                passThrough = 0.3;              \
            };                                  \
            class Neck {                        \
                hitpointName = "HitNeck";       \
                armor = 6;                      \
                passThrough = 0.5;              \
            };                                  \
        };                                      \
    }

#define CLASS_ARF_VEST(var1)                                                        \
    class ECVAR(var1,ARF) : ls_gar_arf_vest_base {                                  \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,ARF));                                  \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_officer_accessories_co.paa)  \
        };                                                                          \
    }

#define CLASS_ENGINEER_VEST(var1)                                                   \
    class ECVAR(var1,Engineer) : ls_gar_engineer_vest_base {                        \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Engineer));                             \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_ENGINEERNCO_VEST(var1)                                                \
    class ECVAR(var1,EngineerNCO) : ls_gar_engineerNCO_vest_base {                  \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,EngineerNCO));                          \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_officer_accessories_co.paa), \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            "",                                                                     \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_arc_accessories_co.paa)      \
        };                                                                          \
    }

#define CLASS_FORCERECONNCO_VEST(var1)                                              \
    class ECVAR(var1,ForceReconNCO) : ls_gar_forceReconNCO_vest_base {              \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,ForceReconNCO));                        \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_kama_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_officer_accessories_co.paa), \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_HAZARD_VEST(var1)                                                     \
    class ECVAR(var1,Hazard) : ls_gar_hazard_vest_base {                            \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Hazard));                               \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_kama_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_officer_accessories_co.paa)  \
        };                                                                          \
    }

#define CLASS_HEAVY_VEST(var1)                                                      \
    class ECVAR(var1,Heavy) : ls_gar_heavy_vest_base {                              \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Heavy));                                \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_ARCPLATE_VEST(var1)                                                   \
    class ECVAR(var1,ARCPlate) : ls_gar_arc_vest_base {                            \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,ARCPlate));                            \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_officer_ca.paa);                  \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_arc_accessories_co.paa),     \
            ""                                                                      \
        };                                                                          \
    }

#define CLASS_ASSAULT_VEST(var1)                                                    \
    class ECVAR(var1,Assault) : ls_gar_assault_vest_base {                          \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Assault));                              \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_CFR_VEST(var1)                                                        \
    class ECVAR(var1,CFR) : ls_gar_cfr_vest_base {                                  \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,CFR));                                  \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_GRENADIER_VEST(var1)                                                  \
    class ECVAR(var1,Grenadier) : ls_gar_grenadier_vest_base {                      \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Grenadier));                            \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_KAMA_VEST(var1)                                                       \
    class ECVAR(var1,Kama) : ls_gar_kama_vest_base {                                \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Kama));                                 \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_kama_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_officer_accessories_co.paa)  \
        };                                                                          \
    }

#define CLASS_LIEUTENANT_VEST(var1)                                                 \
    class ECVAR(var1,Lieutenant) : ls_gar_lieutenant_vest_base {                    \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Lieutenant));                           \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_officer_ca.paa);                  \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_officer_accessories_co.paa)  \
        };                                                                          \
    }

#define CLASS_MEDIC_VEST(var1)                                                          \
    class ECVAR(var1,Medic) : ls_gar_medic_vest_base {                                  \
        VESTS_BASE;                                                                     \
        displayName = SUBCSTRING(ECVAR(var1,Medic));                                    \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                         \
        hiddenSelectionsTextures[] = {                                                  \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_medic_heavy_accessories_co.paa)  \
        };                                                                              \
    }

#define CLASS_OFFICER_VEST(var1)                                                    \
    class ECVAR(var1,Officer) : ls_gar_officer_vest_base {                          \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Officer));                              \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_officer_ca.paa);                  \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_officer_accessories_co.paa)  \
        };                                                                          \
    }

#define CLASS_RECON_VEST(var1)                                                      \
    class ECVAR(var1,Recon) : ls_gar_recon_vest_base {                              \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Recon));                                \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_RECONNCO_VEST(var1)                                                   \
    class ECVAR(var1,ReconNCO) : ls_gar_reconNCO_vest_base {                        \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,ReconNCO));                             \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_SPECIALIST_VEST(var1)                                                 \
    class ECVAR(var1,Specialist) : ls_gar_specialist_vest_base {                    \
        VESTS_BASE;                                                                 \
        displayName = SUBCSTRING(ECVAR(var1,Specialist));                           \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa);                     \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_light_accessories_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_heavy_accessories_co.paa)    \
        };                                                                          \
    }

#define CLASS_CLONE_VEST(var1)                                  \
    class ECVAR(var1,Clone) : ls_gar_clone_vest_base {          \
        VESTS_BASE;                                             \
        displayName = SUBCSTRING(ECVAR(var1,Clone));            \
        picture = QPATHTOEF(characters,data\vests\##CHARACTERS_TYPE##_vest_ca.paa); \
        hiddenSelectionsTextures[] = {};                        \
    }
