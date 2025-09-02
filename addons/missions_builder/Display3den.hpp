class ctrlMenuStrip;
class Display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class Tools {
                    items[] += {QGVAR(missionParameters)};
                };
                class GVAR(missionParameters) {
                    text = CSTRING(missionParametersText);
                    picture = QPATHTOEF(main,data\logo_white_ca.paa);
                    action = QUOTE(call FUNC(addMissionParameters));
                };
            };
        };
    };
};
