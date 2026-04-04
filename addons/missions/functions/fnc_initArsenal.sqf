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
    "ACE_CableTie",
    "ACE_bodyBag",
    "ACE_bodyBag_blue",
    "ACE_bodyBag_white",
    "EC01_RemoteMagazine",
    "HX_AT_Mine_Mag",
    "ItemWatch",
    "JLTS_CloneBinocular",
    "JLTS_CloneBinocular_black",
    "JLTS_credit_card",
    "JLTS_credits_10",
    "JLTS_credits_100",
    "JLTS_credits_1000",
    "JLTS_credits_50",
    "JLTS_credits_500",
    "JLTS_credits_5000",
    "JLTS_droidCaller",
    "JLTS_drugs_deathstick",
    "JLTS_drugs_electrolit",
    "JLTS_drugs_protein",
    "JLTS_flan_10",
    "JLTS_flan_100",
    "JLTS_flan_1000",
    "JLTS_flan_50",
    "JLTS_flan_500",
    "JLTS_flan_5000",
    "JLTS_icecream",
    "JLTS_ids_gar_army",
    "JLTS_ids_gar_medical",
    "JLTS_ids_gar_navy",
    "JLTS_ids_license_driver_large",
    "JLTS_ids_license_driver_medium",
    "JLTS_ids_license_driver_small",
    "JLTS_ids_license_weapon_primary",
    "JLTS_ids_license_weapon_secondary",
    "JLTS_ids_police",
    "JLTS_ids_rep_civ",
    "JLTS_intel_briefcase",
    "JLTS_intel_datacard",
    "JLTS_intel_datapad_civ",
    "JLTS_intel_holoProjector",
    "JLTS_intel_holocron_jedi",
    "JLTS_intel_holocron_sith",
    "JLTS_intel_lightsaber_01",
    "JLTS_intel_trackingFob",
    "JLTS_pazaak_deck",
    "JLTS_sabacc_deck",
    "RTX_RemoteMagazine",
    "TrainingMine_Mag",
    "ls_clone_headlampPhase2_double_hud",
    "ls_clone_headlampPhase2_double_hud",
    "ls_clone_headlampPhase2_hud",
    "ls_clone_headlampPhase2_hud",
    "ls_clone_headlampPhase2_right_hud",
    "ls_clone_headlampPhase2_right_hud",
    "ls_gar_beltBag",
    "ls_gar_beltBag_belt",
    "ls_gar_beltBag_leg",
    "ls_gar_recon_rto_backpack",
    "ls_gar_rto_mini_backpack",
    "ls_gar_rto_mini_backpack_night",
    "lsd_gar_rangefinder_nvg",
    "lsd_gar_standardSPC_nvg",
    "lsd_gar_standard_nvg"
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
