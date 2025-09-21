#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Initialize the spawn vehicles dialog
	 *
	 * Arguments:
	 * 0: _display <DISPLAY> - The display to initialize the dialog
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay] call pc_dialogs_SpawnVehicles_fnc_onLoad
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]]
];

TRACE_1("fnc_onLoad",_this);

if (isNull _display) exitWith {
	ERROR("fnc_onLoad: Invalid display provided");
};

// get controls
private _listVehicles = _display displayCtrl ((configFile >> "RscSpawnVehiclesMenu" >> "Controls" >> "List_Vehicles" >> "idc") call BIS_fnc_getCfgData);

// Reset controls
lbClear _listVehicles;

// Populate the vehicle list
{
    private _displayName = [configFile >> "CfgVehicles" >> _x] call BIS_fnc_displayName;
    private _index = _listVehicles lbAdd _displayName;
    _listVehicles lbSetData [_index, _x];
} forEach (uiNamespace getVariable [QGVAR(vehiclesList), ["B_Lifeboat"]]);

// Select the first vehicle by default
_listVehicles lbSetCurSel 0;
