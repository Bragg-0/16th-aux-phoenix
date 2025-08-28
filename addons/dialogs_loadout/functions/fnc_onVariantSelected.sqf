#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Handle variant selection changes
	 *
	 * Arguments:
	 * 0: _control <CONTROL> - The control that triggered the event
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myControl] call pc_dialogs_loadout_fnc_onVariantSelected
	 *
	 * Public: No
 */

params [
	["_control", controlNull, [controlNull]]
];

TRACE_1("fnc_onVariantSelected",_this);

if (isNull _control) exitWith {
	ERROR("fnc_onVariantSelected: Invalid control provided");
};

// Get the display
private _display = ctrlParent _control;

// get controls
private _listLoadouts = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Loadouts" >> "idc") call BIS_fnc_getCfgData);
private _listVariants = _control;
private _listInventory = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Inventory" >> "idc") call BIS_fnc_getCfgData);
private _buttonLoad = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "Button_Load" >> "idc") call BIS_fnc_getCfgData);

// Get the selected variant from the selected loadout
private _selectedLoadout = _listLoadouts lbData (lbCurSel _listLoadouts);
private _selectedVariant = _listVariants lbData (lbCurSel _listVariants);

// Get the loadout selected
private _loadoutSelected = (configFile >> "CfgLoadouts" >> _selectedLoadout >> "loadoutsInfo" >> _selectedVariant >> "loadout") call BIS_fnc_getCfgData;

// Display the selected loadout
[_loadoutSelected, _listInventory] call SUBFUNC(displayLoadout);

// Enable the load button
_buttonLoad ctrlEnable true;
