#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Initialize the Arsenal
 *
 * Arguments:
 * 0: _object (default: ObjNull) <OBJECT> - The object to initialize the arsenal for
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [this] call pc_missions_fnc_initArsenal
 *
 * Public: No
 */

params [
    ["_object", objNull, [objNull]]
];

TRACE_1("fnc_initArsenal",_this);

// Build the whitelist from all classnames used in CfgLoadouts
private _allItems = [
    // Add your classnames here

];

// Recursive collector: walks any loadout structure and adds string classnames
private _collect = {
	params ["_value"];
	// If it's a non-empty string, record it
	if (_value isEqualType "") exitWith {
		if (_value != "") then { _allItems pushBackUnique _value; };
	};
	// If it's an array, recurse into its children
	if (_value isEqualType []) exitWith {
		{
			[_x] call _collect;
		} forEach _value;
	};
};

// Iterate all loadouts and their variants, collect classnames from their loadout[] arrays
private _cfgRoot = (configFile >> "CfgLoadouts");
private _allLoadoutsCfg = "true" configClasses _cfgRoot;
{
	private _variants = "true" configClasses (_x >> "loadoutsInfo");
	{
		private _cfgLoadoutArray = (_x >> "loadout");
		if (isArray _cfgLoadoutArray) then {
			private _loadout = getArray _cfgLoadoutArray;
			[_loadout] call _collect;
		} else {
			// Fallback via BIS_fnc_getCfgData in case of non-standard typing
			private _loadout = [_cfgLoadoutArray] call BIS_fnc_getCfgData;
			if (_loadout isEqualType []) then { [_loadout] call _collect; };
		};
	} forEach _variants;
} forEach _allLoadoutsCfg;

// Also include all items coming from this mod (prefix PC_) across common categories
// CfgWeapons (weapons, uniforms, vests, headgear, items)
{
	private _cfg = configFile >> _x;
	private _classes = "true" configClasses _cfg;
	{
		private _cn = configName _x;
		if ((_cn select [0,3]) isEqualTo "PC_") then {
			private _scopeArsenal = getNumber (_x >> "scopeArsenal");
			private _scope = getNumber (_x >> "scope");
			if ((_scopeArsenal == 2) || (_scopeArsenal == 0 && {_scope == 2})) then {
				_allItems pushBackUnique _cn;
			};
		};
	} forEach _classes;
} forEach ["CfgWeapons", "CfgGlasses", "CfgMagazines"];

// CfgVehicles
[] call {
	private _classes = "true" configClasses (configFile >> "CfgVehicles");
	{
		private _cn = configName _x;
		if ((_cn select [0,3]) isEqualTo "PC_") then {
			private _scopeArsenal = getNumber (_x >> "scopeArsenal");
			private _scope = getNumber (_x >> "scope");
			if (((_scopeArsenal == 2) || (_scopeArsenal == 0 && {_scope == 2}))) then {
				_allItems pushBackUnique _cn;
			};
		};
	} forEach _classes;
};

[_object, _allItems, true] call ace_arsenal_fnc_initBox;

// Register all CfgLoadouts as ACE Arsenal default loadouts (once per mission)
if (isNil { missionNamespace getVariable "PC_MISSIONS_DefaultLoadoutsAdded" }) then {
	{
		private _ldName = [_x] call BIS_fnc_displayName;
		private _variants = "true" configClasses (_x >> "loadoutsInfo");
		{
			private _varName = [_x] call BIS_fnc_displayName;
			private _cfgLoadoutArray = (_x >> "loadout");
			private _ld = if (isArray _cfgLoadoutArray) then { getArray _cfgLoadoutArray } else { [_cfgLoadoutArray] call BIS_fnc_getCfgData };
			if (_ld isEqualType []) then {
				private _fullName = format ["%1 - %2", _ldName, _varName];
				[_fullName, _ld] remoteExec ["ace_arsenal_fnc_addDefaultLoadout", 0, true];
			};
		} forEach _variants;
	} forEach _allLoadoutsCfg;
	missionNamespace setVariable ["PC_MISSIONS_DefaultLoadoutsAdded", true, true];
};

_object addAction [LLSTRING(openArsenal), {
	params ["_target", "_caller", "_actionId"];
	[_target, _caller] call ace_arsenal_fnc_openBox;
}, nil, 1.5, true, true, "", "true", 5];
