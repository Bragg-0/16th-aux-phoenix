#define ITEM_ACE_BASED(var1,var2)                                   \
    class DOUBLES(ACE,var1);                                        \
    class GVAR(var1) : DOUBLES(ACE,var1) {                          \
        author = AUTHOR;                                            \
        scope = 2;                                                  \
        scopeArsenal = 2;                                           \
        displayName = CSTRING(DOUBLES(var1,displayName));           \
        descriptionShort = CSTRING(DOUBLES(var1,descriptionShort)); \
        picture = QPATHTOF(data\ui\##var2##_ca.paa);                \
        ACE_isMedicalItem = 1;                                      \
    }

#define SIMPLE_INHERITANCE(var1)            \
    class var1;                             \
	class GVAR(var1) : var1 {}
