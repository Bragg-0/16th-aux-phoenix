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
        hiddenSelections[] = { "camo1", "camo2" };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\body_viper_droid_co.paa),
            "#(rgb,8,8,3)color(0,0,0,1))"
        };
        hiddenSelectionsMaterials[] = {
            "\a3\data_f\penetration\armour_plate.rvmat",
            "\a3\data_f\penetration\glass.rvmat"
        };
    };
};
