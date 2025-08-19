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
	 * [myDisplay, 1] call pc_dialogs_loadout_fnc_onUnload
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
	private _listLoadouts = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Loadouts" >> "idc") call BIS_fnc_getCfgData);
	private _listVariants = _display displayCtrl ((configFile >> "RscloadoutMenu" >> "Controls" >> "List_Variants" >> "idc") call BIS_fnc_getCfgData);

	// get current loadout selection
	private _currentLoadout = _listLoadouts lbData [lbCurSel _listLoadouts];
	private _currentVariant = _listVariants lbData [lbCurSel _listVariants];

	// get the loadout selected
	private _loadoutSelected = (configFile >> "CfgLoadouts" >> _currentLoadout >> "loadoutsInfo" >> _currentVariant >> "loadout") call BIS_fnc_getCfgData;

	// get loadout information
	private _LoadoutName = [configFile >> "CfgLoadouts" >> _currentLoadout] call BIS_fnc_displayName;
	private _LoadoutVariantName = [configFile >> "CfgLoadouts" >> _currentLoadout >> "loadoutsInfo" >> _currentVariant] call BIS_fnc_displayName;

	// get loadout traits
	private _LoadoutIsMedic = (configFile >> "CfgLoadouts" >> _currentLoadout >> "isMedic") call BIS_fnc_getCfgDataBool;
	private _LoadoutIsEOD = (configFile >> "CfgLoadouts" >> _currentLoadout >> "isEOD") call BIS_fnc_getCfgDataBool;

	// set loadout information
	player setUnitLoadout _loadoutSelected;

	// set traits
	[player, "medic", _LoadoutIsMedic] call EFUNC(missions,setUnitTrait);
	[player, "eod", _LoadoutIsEOD] call EFUNC(missions,setUnitTrait);

    [parseText FORMAT_2(LSUBLSTRING(loadMsg),_LoadoutName,_LoadoutVariantName), true, nil, 7, 0.7, 0] remoteExec ["BIS_fnc_textTiles", player];
};
