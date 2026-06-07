class CfgVehicles {
    class House_F;
    class GVARMAIN(Viper) : House_F {
        author = AUTHOR;
        displayName = CSTRING(Viper);
        editorCategory = QEGVAR(main,3den);
        editorSubcategory = QEGVAR(main,Objects_Droid);
        editorPreview = EDITORPREVIEW(GVARMAIN(viper));
        scope = 2;
        scopecurator = 2;
        model = QPATHTOF(data\models\viper_droid.p3d);
        hiddenSelections[] = { "camo1" };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\camo1_co.paa)
        };
        hiddenSelectionsMaterials[] = {
            "\a3\data_f\penetration\armour_plate.rvmat"
        };
    };
};
