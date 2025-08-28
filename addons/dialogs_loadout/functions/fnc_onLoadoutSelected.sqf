#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Handle loadout selection changes
	 *
	 * Arguments:
	 * 0: _control <CONTROL> - The control that triggered the event
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myControl] call pc_dialogs_loadout_fnc_onLoadoutSelected
	 *
	 * Public: No
 */

params [
	["_control", controlNull, [controlNull]]
];

TRACE_1("fnc_onLoadoutSelected",_this);

if (isNull _control) exitWith {
	ERROR("fnc_onLoadoutSelected: Invalid control provided");
};

// Get the display
private _display = ctrlParent _control;

// get controls
private _listLoadouts = _control;
private _listVariants = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Variants" >> "idc") call BIS_fnc_getCfgData);
private _listInventory = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Inventory" >> "idc") call BIS_fnc_getCfgData);
private _isMedicIndicator = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "IsMedic" >> "idc") call BIS_fnc_getCfgData);
private _isEODIndicator = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "IsEOD" >> "idc") call BIS_fnc_getCfgData);

// Clear the variants list
lbClear _listVariants;
lbClear _listInventory;

// get the selected loadout
private _selectedLoadout = _listLoadouts lbData (lbCurSel _listLoadouts);

// get Medic loadout traits and update indicators
private _LoadoutIsMedic = (configFile >> "CfgLoadouts" >> _selectedLoadout >> "isMedic") call BIS_fnc_getCfgDataBool;

if (_LoadoutIsMedic) then {
	_isMedicIndicator ctrlSetText LSUBLSTRING(Medic);
	_isMedicIndicator ctrlSetBackgroundColor [RGB_CO_GREEN, 1];
} else {
	_isMedicIndicator ctrlSetText LSUBLSTRING(NotMedic);
	_isMedicIndicator ctrlSetBackgroundColor [RGB_CO_RED, 1];
};

// get EOD loadout traits and update indicators
private _LoadoutIsEOD = (configFile >> "CfgLoadouts" >> _selectedLoadout >> "isEOD") call BIS_fnc_getCfgDataBool;

if (_LoadoutIsEOD) then {
	_isEODIndicator ctrlSetText LSUBLSTRING(EOD);
	_isEODIndicator ctrlSetBackgroundColor [RGB_CO_GREEN, 1];
} else {
	_isEODIndicator ctrlSetText LSUBLSTRING(NotEOD);
	_isEODIndicator ctrlSetBackgroundColor [RGB_CO_RED, 1];
};

// get the list of all variants for the selected loadout and display them
private _allVariants = "true" configClasses (configFile >> "CfgLoadouts" >> _selectedLoadout >> "loadoutsInfo");

{
	private _classname = configName _x;
	private _index = _listVariants lbAdd ([configFile >> "CfgLoadouts" >> _selectedLoadout >> "loadoutsInfo" >> _classname] call BIS_fnc_displayName);
	_listVariants lbSetPicture [_index, getText (configFile >> "CfgLoadouts" >> _selectedLoadout >> "loadoutsInfo" >> _classname >> "icon")];
	_listVariants lbSetData [_index, _classname];
} forEach _allVariants;
