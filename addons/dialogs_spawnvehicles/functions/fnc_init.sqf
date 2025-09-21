#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Initialize the spawn vehicles dialog
	 *
	 * Arguments:
	 * 0: _object <OBJECT> - The object to initialize the addAction
     * 1: _target <OBJECT> - The target object for spawning vehicles
	 * 2: _types (optional, default: ["car"]) <ARRAY> - The type of vehicles to spawn (can be : [ "car", "helicopter", "plane", "box" ])
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this, targetObject, ["car"]] call pc_dialogs_SpawnVehicles_fnc_init
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]],
	["_target", objNull, [objNull]],
	["_types", ["car"], [[]]]
];

TRACE_1("fnc_init",_this);

if (isNull _object) exitWith {
	ERROR("fnc_init: object provided is null");
};

if (isNull _target) exitWith {
    ERROR("fnc_init: target provided is null");
};

private _vehicleList = [];

{
    private _vehicles = [];
    switch (_x) do {
        case "car": {
            _vehicles = [
                "3AS_Barc",
                "3AS_BarcSideCar",
                "3AS_ISP",
                "3AS_ISP_Transport",
                "3AS_Saber_M1",
                "3AS_UTAT",
                "3AS_Saber_M1G",
                "3AS_Saber_M1Recon",
                "3AS_Saber_Super",
                "3AS_ATTE_TCW"
            ];
        };
        case "helicopter": {
            _vehicles = [
                "PC_Vehicles_LAAT_C",
                "PC_Vehicles_LAAT_I_Mk1Lights",
                "PC_Vehicles_LAAT_I_Mk1",
                "PC_Vehicles_LAAT_I_Mk2Lights",
                "PC_Vehicles_LAAT_I_Mk2",
                "3AS_Nu_REP_F",
                "3AS_Rho_REP_F"
            ];
        };
        case "plane": {
            _vehicles = [
                "3AS_BTLB_Bomber",
                "3AS_ARC_170_Orange",
                "3AS_Z95_Orange",
                "3as_V19_base"
            ];
        };
        case "box": {
            _vehicles = [
                "PC_Objects_Supply_ammo",
                "PC_Objects_Supply_grenades",
                "PC_Objects_Supply_launchers",
                "PC_Objects_Supply_medical",
                "PC_Objects_Supply_weapons"
            ];
        };
        default {
            ERROR_1(format ["fnc_init: Invalid type '%1' provided",_x]);
        };
    };
    {
        _vehicleList pushBackUnique _x;
    } forEach _vehicles;
} forEach _types;

if (count _vehicleList == 0) then {
    ERROR("fnc_init: No vehicles available to spawn");
    _vehicleList = ["B_Lifeboat"];
};

_object addAction [LSUBLSTRING(Open), {
	params ["_target", "_caller", "_actionId", "_args"];
	_args params ["_target", "_vehicleList"];
	[_caller, _target, _vehicleList] call SUBFUNC(open);
}, [_target, _vehicleList], 1.5, true, true, "", "true", 5];
