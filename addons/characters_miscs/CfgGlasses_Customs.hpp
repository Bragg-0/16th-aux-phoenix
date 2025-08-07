#define CHARACTERS_TYPE customs

class ECVAR(0770,EngineerNCO) : None {
    author = AUTHOR;
    scope = 2;
    scopeArsenal = 2;
    picture = QPATHTOEF(characters,data\customs_ca.paa);
    displayName = SUBCSTRING(ECVAR(0770,EngineerNCO));
    model = "\ls\core\addons\characters_clone_legacy\vests\engineer\ls_gar_engineerNCO_vest.p3d";
	hiddenSelections[] = {
		"camo1",
		"camo2",
		"camo3",
		"camo4",
		"camo5",
		"camo6",
		"ammo"
	};
    hiddenSelectionsTextures[] = {
        QPATHTOEF(characters_vests,data\regs\base_light_accessories_co.paa),
        "",
        QPATHTOEF(characters_vests,data\regs\base_officer_accessories_co.paa),
        QPATHTOEF(characters_vests,data\regs\base_heavy_accessories_co.paa),
        "",
        QPATHTOEF(characters_vests,data\regs\base_arc_accessories_co.paa),
        ""
    };
    mode = 4;
    mass = 5;
};

class ECVAR(1298,Engineer) : None {
    author = AUTHOR;
    scope = 2;
    scopeArsenal = 2;
    picture = QPATHTOEF(characters,data\customs_ca.paa);
    displayName = SUBCSTRING(ECVAR(1298,Engineer));
    model = "\ls\core\addons\characters_clone_legacy\vests\engineer\ls_gar_engineer_vest.p3d";
	hiddenSelections[] = {
		"camo1",
		"camo2"
	};
    hiddenSelectionsTextures[] = {
        QPATHTOEF(characters_vests,data\regs\base_light_accessories_co.paa),
        ""
    };
    mode = 4;
    mass = 5;
};

#undef CHARACTERS_TYPE
