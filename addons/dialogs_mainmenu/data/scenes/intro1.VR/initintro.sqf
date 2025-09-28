["", [worldName, (getPosATL cam_pos), (getDir cam_pos), 0.75, [-1.17921, 0], 10, 0, 817, 0, 0, 1, 0, 1]] call BIS_fnc_camera;

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
_musiclist = ["PC_Music_SW_Epic_The_Clones_Epic_Original_Theme_Brothers_In_Arms"];

0 fadeMusic 1;
playMusic (selectRandom _musiclist);
addMusicEventHandler ["MusicStop", {
	0 fadeMusic 1;
	playMusic (selectRandom _musiclist);
}];

// Caméra loop dans les couloirs pour le main menu
// Création caméra
_cam = "camera" camCreate getPosATL cam_pos;
_cam cameraEffect ["Internal", "Back"];

// Liste de points de passage
_path = [
	[startPos_0, endPos_0, targetPos_0],
	[startPos_1, endPos_1, targetPos_1],
	[startPos_2, endPos_2, targetPos_2]
];

// Désactivation de l'interface utilisateur de DIWAKO DUI
diwako_dui_main_inFeatureCamera = true;

// Boucle infinie
while { true } do {
	{
		_x params ["_startPoint", "_endPoint", "_targetPoint"];
		private _dist = _startPoint distance _endPoint;
		private _time = _dist / 2; // Vitesse de 2 m/s
		_cam camSetPos getPosATL _startPoint;
		_cam camPrepareTarget getPosATL _targetPoint;
		_cam camCommit 0;
		"menu" cutText ["", "BLACK IN", 0.5, true];
		_cam camPreparePos getPosATL _endPoint;
		_cam camCommitPrepared _time;
		// Déclenche le BLACK OUT 1s avant la fin du mouvement
		[_time] spawn {
			params ["_t"];
			private _delay = (_t - 1) max 0;
			sleep _delay;
			"menu" cutText ["", "BLACK OUT", 0.5, true];
		};
		waitUntil {
			camCommitted _cam
		};
	} forEach _path;
};
