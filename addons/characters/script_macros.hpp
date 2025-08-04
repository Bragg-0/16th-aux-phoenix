#define CLASS_INHERITANCE(var1) \
    class var1;                 \
    class var1##_base : var1 {  \
        scope = 0;              \
        scopeArsenal = 0;       \
        class ItemInfo;         \
    }


//#define CHARACTERS_TYPE -> Regs or Customs

#define CHARACTERS_CATEGORY DOUBLES(PREFIX,SUBCOMPONENT)

#define CVAR(var1) DOUBLES(CHARACTERS_CATEGORY,DOUBLES(CHARACTERS_TYPE,var1))
#define QCVAR(var1) QUOTE(CVAR(var1))

#define CVARF(var1) DOUBLES(CVAR(var1),F)
#define QFCVARF(var1) QUOTE(CVARF(var1))

#define ECVAR(var1,var2) DOUBLES(CHARACTERS_CATEGORY,TRIPLES(CHARACTERS_TYPE,var1,var2))
#define QECVAR(var1,var2) QUOTE(ECVAR(var1,var2))

#define ECVARF(var1,var2) DOUBLES(ECVAR(var1,var2),F)
#define QECVARF(var1,var2) QUOTE(ECVARF(var1,var2))
