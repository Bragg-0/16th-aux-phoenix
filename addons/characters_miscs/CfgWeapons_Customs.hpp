#define CHARACTERS_TYPE Customs

class ECVAR(1298,CommanderNVG) : lsd_gar_p2Commander_v3_nvg {
    author = AUTHOR;
    scope = 2;
    scopeArsenal = 2;
    picture = QPATHTOEF(characters,data\customs_ca.paa);
    displayName = SUBCSTRING(ECVAR(1298,CommanderNVG));
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\customs\1298_nvg_co.paa),
        QPATHTOF(data\customs\1298_nvg_co.paa)
    };
};

#undef CHARACTERS_TYPE
