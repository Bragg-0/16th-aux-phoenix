#define CHARACTERS_TYPE Regs

class CfgVehicles {
    // Imported classes
    class lsd_gar_phase2_Base;

    // Shiny P2
    // Basic Armed
    class CVARF(Shiny) : lsd_gar_phase2_Base {
        author = AUTHOR;
        displayName = CSTRING(Shiny);
        scope = 2;
        scopeCurator = 2;
        faction = QEGVAR(Main,3den_FactionBlufor);
        editorSubcategory = QEGVAR(Main,Characters_Regs_Shiny);
        uniformClass = "PC_Uniforms_Regs_Shiny";
        backpack = "";
        weapons[] = WEAPON_DEFAULT;
        respawnWeapons[] = WEAPON_DEFAULT;
        magazines[] = { MAGAZINE_DEFAULT };
        respawnMagazines[] = { MAGAZINE_DEFAULT };
        items[] = { ITEM_DEFAULT };
        respawnItems[] = { ITEM_DEFAULT };
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Clone" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Clone" };
    };

    // EOD
    class ECVARF(Shiny,EOD) : CVARF(Shiny) {
        displayName = CSTRING(Shiny_EOD);
        uniformClass = "PC_Uniforms_Regs_Shiny_EOD";
        backpack = "PC_Backpacks_Regs_EOD_Standard";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Engineer" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Engineer" };
    };

    // Medic
    class ECVARF(Shiny,Medic) : CVARF(Shiny) {
        displayName = CSTRING(Shiny_Medic);
        uniformClass = "PC_Uniforms_Regs_Shiny_Medic";
        backpack = "PC_Backpacks_Regs_Base_Medic";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Medic" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Medic" };
        items[] = { ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT };
        respawnItems[] = { ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT };
    };

    // Grenadier
    class ECVARF(Shiny,Grenadier) : CVARF(Shiny) {
        displayName = CSTRING(Shiny_Grenadier);
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Grenadier" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Grenadier" };
        weapons[] = WEAPONS(DC15A_GL,DC17S,"");
        respawnWeapons[] = WEAPONS(DC15A_GL,DC17S,"");
        magazines[] = { MAGS_X6(DC15A_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DC15A_MAG_GL),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
        respawnMagazines[] = { MAGS_X6(DC15A_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DC15A_MAG_GL),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
    };

    // Heavy
    class ECVARF(Shiny,Heavy) : CVARF(Shiny) {
        displayName = CSTRING(Shiny_Heavy);
        backpack = "PC_Backpacks_Regs_Base_Standard";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Heavy" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2","PC_Vests_Regs_Base_Heavy" };
        weapons[] = WEAPONS(Z6,DC17S,"");
        respawnWeapons[] = WEAPONS(Z6,DC17S,"");
        magazines[] = { MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
        respawnMagazines[] = { MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
    };

    // AT
    class ECVARF(Shiny,AT) : CVARF(Shiny) {
        displayName = CSTRING(Shiny_AT);
        backpack = "PC_Backpacks_Regs_Base_Rocket";
        weapons[] = WEAPONS(DC15S,DC17S,RPS6);
        respawnWeapons[] = WEAPONS(DC15S,DC17S,RPS6);
        magazines[] = { MAGAZINE_DEFAULT,MAGS_X6(RPS6_MAG) };
        respawnMagazines[] = { MAGAZINE_DEFAULT,MAGS_X6(RPS6_MAG) };
    };

    // Pilot
    class ECVARF(Shiny,Pilot) : CVARF(Shiny) {
        displayName = CSTRING(Shiny_Pilot);
        backpack = "ls_gar_rto_mini_backpack";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2_Pilot","PC_Vests_Regs_Base_CFR" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Shiny_P2_Pilot","PC_Vests_Regs_Base_CFR" };
    };

    // Trooper P2
    // Basic Armed
    class CVARF(Trooper) : CVARF(Shiny) {
        displayName = CSTRING(Trooper);
        uniformClass = "PC_Uniforms_Regs_Trooper";
        editorSubcategory = QEGVAR(Main,Characters_Regs_Trooper);
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Clone" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Clone" };
    };

    // EOD
    class ECVARF(Trooper,EOD) : CVARF(Trooper) {
        displayName = CSTRING(Trooper_EOD);
        uniformClass = "PC_Uniforms_Regs_Trooper_EOD";
        backpack = "PC_Backpacks_Regs_EOD_Standard";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Engineer" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Engineer" };
    };

    // Medic
    class ECVARF(Trooper,Medic) : CVARF(Trooper) {
        displayName = CSTRING(Trooper_Medic);
        uniformClass = "PC_Uniforms_Regs_Trooper_Medic";
        backpack = "PC_Backpacks_Regs_Base_Medic";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Medic" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Medic" };
        items[] = { ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT };
        respawnItems[] = { ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT };
    };

    // Grenadier
    class ECVARF(Trooper,Grenadier) : CVARF(Trooper) {
        displayName = CSTRING(Trooper_Grenadier);
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Grenadier" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Grenadier" };
        weapons[] = WEAPONS(DC15A_GL,DC17S,"");
        respawnWeapons[] = WEAPONS(DC15A_GL,DC17S,"");
        magazines[] = { MAGS_X6(DC15A_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DC15A_MAG_GL),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
        respawnMagazines[] = { MAGS_X6(DC15A_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DC15A_MAG_GL),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
    };

    // Heavy
    class ECVARF(Trooper,Heavy) : CVARF(Trooper) {
        displayName = CSTRING(Trooper_Heavy);
        backpack = "PC_Backpacks_Regs_Base_Standard";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Heavy" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Heavy" };
        weapons[] = WEAPONS(Z6,DC17S,"");
        respawnWeapons[] = WEAPONS(Z6,DC17S,"");
        magazines[] = { MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
        respawnMagazines[] = { MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI };
    };

    // AT
    class ECVARF(Trooper,AT) : CVARF(Trooper) {
        displayName = CSTRING(Trooper_AT);
        backpack = "PC_Backpacks_Regs_Base_Rocket";
        weapons[] = WEAPONS(DC15S,DC17S,RPS6);
        respawnWeapons[] = WEAPONS(DC15S,DC17S,RPS6);
        magazines[] = { MAGAZINE_DEFAULT,MAGS_X6(RPS6_MAG) };
        respawnMagazines[] = { MAGAZINE_DEFAULT,MAGS_X6(RPS6_MAG) };
    };

    // Pilot
    class ECVARF(Trooper,Pilot) : CVARF(Trooper) {
        displayName = CSTRING(Trooper_Pilot);
        backpack = "ls_gar_rto_mini_backpack";
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2_Pilot","PC_Vests_Regs_Base_CFR" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2_Pilot","PC_Vests_Regs_Base_CFR" };
    };

    // NCOs and Officers
    // Caporal
    class CVARF(Caporal) : CVARF(Trooper) {
        displayName = CSTRING(Caporal);
        editorSubcategory = QEGVAR(Main,Characters_Regs_NCO_Officer);
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Recon" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Recon" };
    };

    // Sergent
    class CVARF(Sergent) : CVARF(Caporal) {
        displayName = CSTRING(Sergent);
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_ReconNCO" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_ReconNCO" };
    };

    // Lieutenant
    class CVARF(Lieutenant) : CVARF(Caporal) {
        displayName = CSTRING(Lieutenant);
        linkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Lieutenant" };
        respawnlinkedItems[] = { LINKED_ITEMS_DEFAULT,"PC_Helmets_Regs_Trooper_P2","PC_Vests_Regs_Base_Lieutenant" };
    };
};

#undef CHARACTERS_TYPE
