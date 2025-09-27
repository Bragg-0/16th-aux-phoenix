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
        class TransportWeapons {
            WEAP_XX(3AS_DC15S_F,5);
            WEAP_XX(3AS_DC15A_F,5);
            WEAP_XX(3AS_DC15A_GL,2);
            WEAP_XX(3AS_DC17S_F,10);
            WEAP_XX(JLTS_Z6,2);
            WEAP_XX(3AS_DC15X_F,2);
        };
        EMPTY_MAGAZINE;
    };

    class SUBGVAR(ammo) : JLTS_Ammobox_ammo_GAR {
        displayName = CSTRING(Ammo);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        class TransportMagazines {
            MAG_XX(3AS_16Rnd_EC20_Mag,50);
            MAG_XX(3AS_10Rnd_EC100_Mag,30);
            MAG_XX(3AS_45Rnd_EC50_Mag,20);
            MAG_XX(3AS_60Rnd_EC30_mag,20);
            MAG_XX(JLTS_Z6_mag,10);
        };
    };

    class SUBGVAR(grenades) : JLTS_Ammobox_grenades_GAR {
        displayName = CSTRING(Grenades);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        class TransportMagazines {
            MAG_XX(3AS_3UGL_MK55_Smoke_Red_shell,10);
            MAG_XX(3AS_3UGL_MK55_Smoke_Green_shell,10);
            MAG_XX(3AS_3UGL_MK55_Smoke_Blue_shell,10);
            MAG_XX(3AS_3UGL_MK56_Flare_White_shell,10);
            MAG_XX(3AS_3UGL_MK56_Flare_Red_shell,10);
            MAG_XX(3AS_3UGL_MK56_Flare_Green_shell,10);
            MAG_XX(3AS_SmokeWhite,10);
            MAG_XX(3AS_SmokeRed,10);
            MAG_XX(3AS_SmokeGreen,10);
            MAG_XX(3AS_SmokeBlue,10);
            MAG_XX(3AS_ThermalDetonator,10);
            MAG_XX(3AS_BaridumCore,5);
        };
    };

    class SUBGVAR(launchers) : JLTS_Ammobox_launchers_GAR {
        displayName = CSTRING(Launchers);
        BASE_SUPPLY;
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        class TransportWeapons {
            WEAP_XX(3AS_RPS6_HP,5);
        };
        class TransportMagazines {
            MAG_XX(3AS_MK41_AT,20);
            MAG_XX(3AS_MK42_HE,10);
        };
    };

    class SUBGVAR(medical) : JLTS_Ammobox_support_GAR {
        displayName = CSTRING(Medical);
        BASE_SUPPLY;
        class TransportItems {
            ITEM_XX(PC_Medical_ElasticBandage,100);
            ITEM_XX(PC_Medical_PackingBandage,100);
            ITEM_XX(PC_Medical_Morphine,50);
            ITEM_XX(PC_Medical_Adenosine,20);
            ITEM_XX(PC_Medical_SurgicalKit,10);
            ITEM_XX(PC_Medical_Epinephrine,50);
            ITEM_XX(PC_Medical_PersonalAidKit,10);
            ITEM_XX(PC_Medical_Splint,50);
            ITEM_XX(ACE_tourniquet,50);
            ITEM_XX(PC_Medical_SalineIV_250,50);
            ITEM_XX(PC_Medical_SalineIV_500,30);
            ITEM_XX(PC_Medical_PlasmaIV_500,30);
            ITEM_XX(PC_Medical_BloodIV,20);
            ITEM_XX(PC_Medical_Quikclot,100);
        };
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        class TransportMagazines {
            MAG_XX(PC_Medical_Painkillers,20);
        };
    };
};
