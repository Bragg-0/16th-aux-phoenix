class CfgMarkers {
    class GVAR(Marker_Black) {
        name = CSTRING(Marker_Black); // str_PC_Main_Marker_Black
        scope = 2;
        scopeCurator = 2;
        color[] = { 1, 1, 1, 1 };
        icon = QPATHTOF(data\logo_black_ca.paa);
        markerClass = "flags";
        shadow = 0;
        size = 32;
        texture = QPATHTOF(data\logo_black_ca.paa);
    };
    class GVAR(Marker_White) {
        name = CSTRING(Marker_White); // str_PC_Main_Marker_White
        scope = 2;
        scopeCurator = 2;
        color[] = { 1, 1, 1, 1 };
        icon = QPATHTOF(data\logo_white_ca.paa);
        markerClass = "flags";
        shadow = 0;
        size = 32;
        texture = QPATHTOF(data\logo_white_ca.paa);
    };
};
