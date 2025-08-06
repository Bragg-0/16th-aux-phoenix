#define CLASS_UNIFORM(var1)                                         \
    class CVAR(var1) : ls_gar_phase2_uniform_base {                 \
        Author = AUTHOR;                                            \
        scopeArsenal = 2;                                           \
        scope = 2;                                                  \
        displayName = SUBCSTRING(CVAR(var1));                       \
        picture = QPATHTOEF(characters,data\uniforms\##CHARACTERS_TYPE##_body_ca.paa);  \
        class ItemInfo : ItemInfo {                                 \
            uniformModel = "-";                                     \
            uniformType = "neopren";                                \
            uniformClass = CVARF(var1);                             \
            containerClass = SUPPLY_XX(100);                        \
            mass = 20;                                              \
        };                                                          \
    }
