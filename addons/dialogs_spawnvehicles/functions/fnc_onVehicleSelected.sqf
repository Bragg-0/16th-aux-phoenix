#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Handle vehicle selection changes
	 *
	 * Arguments:
	 * 0: _control <CONTROL> - The control that triggered the event
     * 1: _lbCurSel <NUMBER> - The current selected index
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myControl, 0] call pc_dialogs_SpawnVehicles_fnc_onVehicleSelected
	 *
	 * Public: No
 */

params [
	["_control", controlNull, [controlNull]],
	["_lbCurSel", 0, [0]]
];

TRACE_1("fnc_onVehicleSelected",_this);

if (isNull _control) exitWith {
	ERROR("fnc_onVehicleSelected: Invalid control provided");
};

if (_lbCurSel < 0) exitWith {
	ERROR("fnc_onVehicleSelected: Invalid listbox selection");
};

// Get the display
private _display = ctrlParent _control;

// get controls
private _listVehicles = _control;
private _previewImage = _display displayCtrl ((configFile >> "RscSpawnVehiclesMenu" >> "Controls" >> "Preview_Image" >> "idc") call BIS_fnc_getCfgData);

// Update the preview image based on the selected vehicle
private _selectedVehicle = _listVehicles lbData _lbCurSel;

private _vehiclePreview = (configFile >> "CfgVehicles" >> _selectedVehicle >> "picture") call BIS_fnc_getCfgData;

if (_vehiclePreview != "") then {
    _previewImage ctrlSetText _vehiclePreview;
} else {
    _previewImage ctrlSetText QPATHTOF(data\notFound_co.jpg);
};
