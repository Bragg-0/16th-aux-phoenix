class CfgMarkers {
    class GVAR(Marker_Black) {
        name = CSTRING(marker_black);
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
        name = CSTRING(marker_white);
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
