#define CLASS_UNIFORM_F(var1)                                           \
    class CVARF(var1) : lsd_gar_phase2_base {                           \
        Author = AUTHOR;                                                \
        scopeCurator = 1;                                               \
        scope = 1;                                                      \
        uniformClass = QCVAR(var1);                                      \
        hiddenSelectionsTextures[] = {                                  \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_camo1_co.paa),   \
            QPATHTOF(data\##CHARACTERS_TYPE##\##var1##_camo2_co.paa),   \
            QPATHTOF(data\undersuit_co.paa)                             \
        };                                                              \
    }
