#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Initialize the loadout dialog
	 *
	 * Arguments:
	 * 0: _display <DISPLAY> - The display to initialize the dialog
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay] call pc_dialogs_loadout_fnc_onLoad
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
private _listLoadouts = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Loadouts" >> "idc") call BIS_fnc_getCfgData);
private _listVariants = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Variants" >> "idc") call BIS_fnc_getCfgData);
private _listInventory = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Inventory" >> "idc") call BIS_fnc_getCfgData);
private _buttonLoad = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "Button_Load" >> "idc") call BIS_fnc_getCfgData);

// Reset controls
lbClear _listLoadouts;
lbClear _listVariants;
lbClear _listInventory;

// Initialize the loadout list
private _allLoadout = "true" configClasses (configFile >> "CfgLoadouts");

{
	private _classname = configName _x;
	private _index = _listLoadouts lbAdd ([configFile >> "CfgLoadouts" >> _classname] call BIS_fnc_displayName);
	_listLoadouts lbSetPicture [_index, getText (configFile >> "CfgLoadouts" >> _classname >> "icon")];
	_listLoadouts lbSetData [_index, _classname];
} forEach _allLoadout;

// Disable the load button
_buttonLoad ctrlEnable false;
