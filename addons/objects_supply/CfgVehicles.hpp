class CfgVehicles {
    class JLTS_Ammobox_ammo_GAR;
    class JLTS_Ammobox_grenades_GAR;
    class JLTS_Ammobox_launchers_GAR;
    class JLTS_Ammobox_support_GAR;
    class JLTS_Ammobox_weapons_GAR;

    class SUBGVAR(weapons) : JLTS_Ammobox_weapons_GAR {
        displayName = CSTRING(Weapons);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        //TODO: Configure weapons box
    };

    class SUBGVAR(ammo) : JLTS_Ammobox_ammo_GAR {
        displayName = CSTRING(Ammo);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        //TODO: Configure ammo box
    };

    class SUBGVAR(grenades) : JLTS_Ammobox_grenades_GAR {
        displayName = CSTRING(Grenades);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        //TODO: Configure grenades box
    };

    class SUBGVAR(launchers) : JLTS_Ammobox_launchers_GAR {
        displayName = CSTRING(Launchers);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        //TODO: Configure launchers box
    };

    class SUBGVAR(medical) : JLTS_Ammobox_support_GAR {
        displayName = CSTRING(Medical);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        //TODO: Configure medical box
    };
};
