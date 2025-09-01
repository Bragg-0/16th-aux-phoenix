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
                //TODO : Add vehicles
            ];
        };
        case "helicopter": {
            _vehicles = [
                //TODO : Add vehicles
            ];
        };
        case "plane": {
            _vehicles = [
                //TODO : Add vehicles
            ];
        };
        case "box": {
            _vehicles = [
                //TODO : Add boxes
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
