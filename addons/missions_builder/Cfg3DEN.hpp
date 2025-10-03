class Cfg3DEN {
    class Compositions {
        class GVAR(Base) {
            path = "x\pc\addons\missions_builder\data\compositions\Base"; //! DON'T MAKE A `\` BEFORE `x\pc\addons\*`
            side = UNKNOWN;
            editorCategory = QEGVAR(main,3den);
            editorSubcategory = "EdSubcat_Utilities";
            scope = 2;
            scopeCurator = 1;
            displayName = CSTRING(Base);
            icon = QPATHTOF(data\compositions\logo_ca.paa);
            useSideColorOnIcon = 1;
        };
        class GVAR(Venator) : GVAR(Base) {
            path = "x\pc\addons\missions_builder\data\compositions\Venator"; //! DON'T MAKE A `\` BEFORE `x\pc\addons\*`
            displayName = CSTRING(Venator);
        };
    };
};
