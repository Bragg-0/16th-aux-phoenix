class RscSpawnVehiclesMenu {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(_this call SUBFUNC(onLoad));
    onUnload = QUOTE(_this call SUBFUNC(onUnload));
    class ControlsBackground {
        class Background : RscText {
            x = SAFEZONE_X_SMALL;
            y = SAFEZONE_Y_SMALL;
            w = SAFEZONE_W_SMALL;
            h = H_COORD(0.32962963);
            colorBackground[] = GUI_BCG_MENU;
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
        class Title_Vehicles : Header {
            x = X_COORD(0.3046875);
            y = Y_COORD(0.26736112);
            w = W_COORD(0.16503907);
            text = SUBCSTRING(title_vehicles);
        };
    };
    class Controls {
        class Preview : RscPictureKeepAspect {
            idc = 1000;
            x = X_COORD(0.47916667);
            y = Y_COORD(0.26666667);
            w = W_COORD(0.21666667);
            h = H_COORD(0.23333334);
            text = QPATHTOF(data\notFound_co.jpg);
        };
        class List_Vehicles : RscListBox {
            idc = 1001;
            x = X_COORD(0.30416667);
            y = Y_COORD(0.29351852);
            w = W_COORD(0.16510417);
            h = H_COORD(0.24722223);
            onLBSelChanged = QUOTE(_this call SUBFUNC(onVehicleSelected));
        };
        class Button_Load : RscButtonMenuOK {
            x = X_COORD(0.47916667);
            y = Y_COORD(0.51388889);
            w = W_COORD(0.103125);
            h = GUI_STD_HEIGHT;
            BTN_COLOR_GREEN;
        };
        class Button_Cancel : RscButtonMenuCancel {
            x = X_COORD(0.59270834);
            y = Y_COORD(0.51388889);
            w = W_COORD(0.103125);
            h = GUI_STD_HEIGHT;
            BTN_COLOR_RED;
        };
    };
};
