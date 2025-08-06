#define HELMET_BASE                         \
    author = AUTHOR;                        \
    scope = 2;                              \
    scopeArsenal = 2;                       \
    class ItemInfo : ItemInfo {             \
        mass = 10;                          \
        class HitpointsProtectionInfo {     \
            class Head {                    \
                hitpointName = "HitHead";   \
                armor = 6;                  \
                passThrough = 0.5;          \
            };                              \
            class Face {                    \
                hitpointName = "HitFace";   \
                armor = 6;                  \
                passThrough = 0.5;          \
            };                              \
        };                                  \
    }

#define CLASS_P2_HELMET(var1)                                               \
    class ECVAR(var1,P2) : ls_gar_phase2_helmet_base {                      \
        HELMET_BASE;                                                        \
        displayName = SUBCSTRING(ECVAR(var1,P2));                           \
        picture = QPATHTOEF(characters,data\helmets\##CHARACTERS_TYPE##_p2_ca.paa);             \
        hiddenSelectionsTextures[] = {                                      \
            QPATHTOF(data\##CHARACTERS_TYPE##\P2\##var1##_helmet_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\P2\##var1##_visor_co.paa)     \
        };                                                                  \
    }

#define CLASS_P2_PILOT_HELMET(var1)                                                 \
    class ECVAR(var1,P2_Pilot) : ls_gar_phase2_pilot_helmet_base {                  \
        HELMET_BASE;                                                                \
        displayName = SUBCSTRING(ECVAR(var1,P2_Pilot));                             \
        picture = QPATHTOEF(characters,data\helmets\##CHARACTERS_TYPE##_p2_pilot_ca.paa);               \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##CHARACTERS_TYPE##\P2_Pilot\##var1##_helmet_co.paa),     \
            QPATHTOF(data\##CHARACTERS_TYPE##\P2_Pilot\##var1##_visor_co.paa)       \
        };                                                                          \
    }
