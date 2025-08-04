#define CLASS_P2_HELMET_F(var1)                     \
    class ECVARF(var1,P2) : Headgear_Base_F {       \
        Author = AUTHOR;                            \
        scopeCurator = 2;                           \
        scope = 2;                                  \
        displayName = SUBCSTRING(ECVARF(var1,P2));  \
        editorCategory = QEGVAR(main,3den);         \
        editorSubcategory = "EdSubcat_Helmets";     \
        class TransportItems {                      \
            ITEM_XX(CVAR(var1,P2),1);               \
        };                                          \
    }

#define CLASS_P2_PILOT_HELMET_F(var1)                       \
    class ECVARF(var1,P2_Pilot) : Headgear_Base_F {         \
        Author = AUTHOR;                                    \
        scopeCurator = 2;                                   \
        scope = 2;                                          \
        displayName = SUBCSTRING(ECVARF(var1,P2_Pilot));    \
        editorCategory = QEGVAR(main,3den);                 \
        editorSubcategory = "EdSubcat_Helmets";             \
        class TransportItems {                              \
            ITEM_XX(CVAR(var1,P2_Pilot),1);                 \
        };                                                  \
    }
