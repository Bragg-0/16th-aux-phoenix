#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Handle the unloading of the dialog
	 *
	 * Arguments:
	 * 0: _display <DISPLAY> - The display to unload
	 * 1: _exitCode (default: 0) <NUMBER> - The exit code to return
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay, 1] call pc_dialogs_SpawnVehicles_fnc_onUnload
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]],
	["_exitCode", 0, [0]]
];

TRACE_1("fnc_onUnload",_this);

if (isNull _display) exitWith {
	ERROR("fnc_onUnload: Invalid display provided");
};

if (_exitCode == 1) then {
	// Handle Ok case
	// get controls
    private _listVehicles = _display displayCtrl ((configFile >> "RscSpawnVehiclesMenu" >> "Controls" >> "List_Vehicles" >> "idc") call BIS_fnc_getCfgData);

    // Get the selected vehicle
    private _selectedVehicle = _listVehicles lbData (lbCurSel _listVehicles);

    // Get the spawn position
    private _spawnPos = uiNamespace getVariable QGVAR(spawnPos);

    // Delete existing vehicle on spawnPos if any
    private _existingVehicle = nearestObjects [getPosATL _spawnPos, ["AllVehicles","ReammoBox_F"], 10];
    {
        deleteVehicle _x;
    } forEach _existingVehicle;

    // Spawn the vehicle
    private _vehicle = createVehicle [_selectedVehicle, [0,0,0]];
    if (!isNull _vehicle) then {
        _vehicle setPosATL (getPosATL _spawnPos);
        _vehicle setDir (getDir _spawnPos);
        TRACE_1("fnc_onUnload: Spawned vehicle",_vehicle);
    [parseText FORMAT_1(LSUBLSTRING(loadMsg),([configOf _vehicle] call BIS_fnc_displayName)), true, nil, 7, 0.7, 0] remoteExec ["BIS_fnc_textTiles", player];
    } else {
        ERROR_1("fnc_onUnload: Failed to create '%1'",_selectedVehicle);
    };
};
