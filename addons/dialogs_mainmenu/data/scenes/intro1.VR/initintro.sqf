["", [worldName, (getPosATL cam_pos), (getDir cam_pos), 0.75, [-1.17921, 0], 0, 0, 265.831, 1, 0, 1, 0, 1]] call BIS_fnc_camera;

showChat false;
enableEnvironment false;
showCinemaBorder false;
showHUD false;
setAperture -1;
setViewDistance 200;

"colorCorrections" ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 0.24], [1, 1, 1, 0], [0.7, 0.7, 0, 0, -0.1, 0.4, 0.8]];
"colorCorrections" ppEffectEnable true;
"colorCorrections" ppEffectCommit 0;

// Musique d'ambiance
private _musiclist = ["PC_Music_SW_Epic_The_Clones_Epic_Original_Theme_Brothers_In_Arms"];

0 fadeMusic 1;
playMusic (selectRandom _musiclist);
addMusicEventHandler ["MusicStop", {
	0 fadeMusic 1;
	playMusic (selectRandom _musiclist);
}];

// Caméra loop dans les couloirs pour le main menu
// Création caméra
private _cam = "camera" camCreate getPosATL camPos_0;
_cam cameraEffect ["Internal", "Back"];

// Liste de points de passage
private _path = [
	[camPos_1,targetPos_0],
	[camPos_2,targetPos_0],
	[camPos_3,targetPos_0],
	[camPos_4,targetPos_1],
	[camPos_5,targetPos_1],
	[camPos_6,targetPos_2],
	[camPos_5,targetPos_3],
	[camPos_4,targetPos_4],
	[camPos_3,targetPos_5],
	[camPos_2,targetPos_5],
	[camPos_1,targetPos_6],
	[camPos_0,targetPos_0]
];

// Désactivation de l'interface utilisateur de DIWAKO DUI
diwako_dui_main_inFeatureCamera = true;

// Durée de déplacement entre chaque point
private _time = 10;

// Boucle infinie
while {true} do {
    {
		_x params ["_pathPoint", "_targetPoint"];
		private _pathPos = getPosATL _pathPoint;
        _cam camPreparePos _pathPos;
        _cam camPrepareTarget getPosATL _targetPoint;
        _cam camCommitPrepared _time;
        waitUntil {camCommitted _cam};
    } forEach _path;
};
