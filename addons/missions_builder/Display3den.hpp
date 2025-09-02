class ctrlMenuStrip;
class Display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class Tools {
                    items[] += {QGVAR(generate)};
                };
                class GVAR(generate) {
                    text = CSTRING(generateText);
                    picture = QPATHTOEF(main,data\logo_white_ca.paa);
                    action = QUOTE(call FUNC(generate));
                };
            };
        };
    };
};
