class RscLoadoutMenu {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(_this call FUNC(onLoad));
    onUnload = QUOTE(_this call FUNC(onUnload));
    class ControlsBackground {
        class Background : RscText {
            x = SAFEZONE_X_SMALL;
            y = SAFEZONE_Y_SMALL;
            w = SAFEZONE_W_SMALL;
            h = SAFEZONE_H_SMALL;
            colorBackground[] = CA_UI_background;
        };
        class Frame : Background {
            style = ST_FRAME;
            colorText[] = GUI_BCG_COLOR;
        };
        class Header : Background {
            h = GUI_STD_HEIGHT;
            colorBackground[] = GUI_BCG_COLOR;
            colorText[] = GUI_TITLETEXT_COLOR;
            text = SUBCSTRING(header);
        };
        class Title_Loadouts : Header {
            x = X_COORD(0.30416667);
            y = Y_COORD(0.26666667);
            w = GUI_STD_WIDTH;
            text = SUBCSTRING(title_loadout);
        };
        class Title_Variants : Title_Loadouts {
            x = X_COORD(0.41770834);
            text = SUBCSTRING(title_variants);
        };
        class Title_Inventory : Title_Loadouts {
            x = X_COORD(0.53072917);
            w = W_COORD(0.16510417);
            text = SUBCSTRING(title_inventory);
        };
    };
    class Controls {
        class IsMedic : RscText {
            idc = 1000;
            x = X_COORD(0.41770834);
            y = Y_COORD(0.6925926);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(ismedic);
            BTN_COLOR_RED;
        };
        class IsEOD : IsMedic {
            idc = 1001;
            y = Y_COORD(0.73333334);
            text = SUBCSTRING(iseod);
        };
        class Logo : RscPicture {
            idc = 1002;
            x = X_COORD(0.41770834);
            y = Y_COORD(0.54166667);
            w = GUI_STD_WIDTH;
            h = H_COORD(0.13796297);
            text = "";
        };
        class List_Loadouts : RscListBox {
            idc = 1003;
            x = X_COORD(0.30416667);
            y = Y_COORD(0.29351852);
            w = GUI_STD_WIDTH;
            h = H_COORD(0.4675926);
            onLBSelChanged = QUOTE(_this call FUNC(onLoadoutSelected));
        };
        class List_Variants : List_Loadouts {
            idc = 1004;
            x = X_COORD(0.41770834);
            h = H_COORD(0.23333334);
            onLBSelChanged = QUOTE(_this call FUNC(onVariantSelected));
        };
        class List_Inventory : List_Loadouts {
            idc = 1005;
            x = X_COORD(0.53125);
            w = Y_COORD(0.16510417);
            h = H_COORD(0.38518519);
        };
        class Button_Load : RscButtonMenuOK {
            x = X_COORD(0.53072917);
            y = Y_COORD(0.73333334);
            w = W_COORD(0.16510417);
            h = GUI_STD_HEIGHT;
            BTN_COLOR_GREEN;
        };
        class Button_Cancel : RscButtonMenuCancel {
            x = X_COORD(0.53072917);
            y = Y_COORD(0.6925926);
            w = W_COORD(0.16510417);
            h = GUI_STD_HEIGHT;
            BTN_COLOR_RED;
        };
        class Button_Close : Button_Cancel {
            x = X_COORD(0.68541667);
            y = Y_COORD(0.225);
            w = W_COORD(0.02083334);
            text = "X";
        };
    };
};
