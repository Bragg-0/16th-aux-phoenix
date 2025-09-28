class RscStandardDisplay;
class RscDisplayMain : RscStandardDisplay {
    delete Spotlight;
    idd = 0;
    idc = 1;
    enableDisplay = 1;
    class ControlsBackground {
        class GVAR(connect1): RscText {
            x = X_COORD(0.43802084);
            y = Y_COORD(0.225);
            w = W_COORD(0.12395834);
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(connect);
            style = ST_CENTER;
            BTN_COLOR_DEFAULT;
        };
    };
    class controls {
        class Logo : RscShortcutButton {
            access = 0;
            color[] = { 1, 1, 1, 1 };
            colorActive[] = { 1, 1, 1, 1 };
            colorDisabled[] = { 1, 1, 1, 0.25 };
            default = 0;
            deletable = 0;
            fade = 0;
            font = "RobotoCondensed";
            h = "1 * 5 * (pixelH * pixelGrid * 2)";
            shadow = 0;
            sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
            soundClick[] = { "", 0.1, 1 };
            soundEnter[] = { "", 0.1, 1 };
            soundEscape[] = { "", 0.1, 1 };
            soundPush[] = { "", 0.1, 1 };
            style = 48;
            text = QPATHTOF(data\logo_ca.paa);
            tooltipColorBox[] = { 1, 1, 1, 1 };
            tooltipColorShade[] = { 0, 0, 0, 0.65 };
            tooltipColorText[] = { 1, 1, 1, 1 };
            type = 11;
            url = "";
            w = "2 * 	5 * 	(pixelW * pixelGrid * 2)";
            x = "0.5 - 	5 * 	(pixelW * pixelGrid * 2)";
            y = "safezoneY + (3 - 0.5 * 	5) * 	(pixelH * pixelGrid * 2)";
        };
        class LogoApex : Logo {
        };

        delete Spotlight1;
        delete Spotlight2;
        delete Spotlight3;
        delete BackgroundSpotlightRight;
        delete BackgroundSpotlightLeft;
        delete BackgroundSpotlight;
        delete SpotlightNext;
        delete SpotlightPrev;

        class GVAR(connect1): RscButton {
            idc = 6101;
            x = X_COORD(0.43802084);
            y = Y_COORD(0.225);
            w = W_COORD(0.12395834);
            h = GUI_STD_HEIGHT;
            onButtonClick = QUOTE(_this execvm '\x\pc\addons\dialogs_mainmenu\scripts\connectToServer.sqf';);
            colorBackground[] = CA_UI_transparent;
            colorBackgroundActive[] = GUI_BCG_COLOR_SELECTED;
            colorBackgroundDisabled[] = GUI_BCG_MENU;
        };
    };
};
