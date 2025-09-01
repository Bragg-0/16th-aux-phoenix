#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Open the spawn vehicles menu
	 *
	 * Arguments:
	 * 0: _caller <OBJECT> - The unit calling the function
     * 1: _target <OBJECT> - The target object for spawning vehicles
     * 2: _vehicleList <ARRAY> - The list of classnames of vehicles that can be spawned
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this, targetObject, ["B_Lifeboat"]] call pc_dialogs_SpawnVehicles_fnc_open
	 *
	 * Public: No
 */

params [
	["_caller", objNull, [objNull]],
    ["_target", objNull, [objNull]],
	["_vehicleList", ["B_Lifeboat"], [[]]]
];

TRACE_1("fnc_open",_this);

if (isNull _caller || !isPlayer _caller) exitWith {
    ERROR("fnc_open: Invalid caller provided");
};

if (isNull _target) exitWith {
    ERROR("fnc_open: target provided is null");
};

uiNamespace setVariable [QGVAR(spawnPos), _target];
uiNamespace setVariable [QGVAR(vehiclesList), _vehicleList];

createDialog "RscSpawnVehiclesMenu";
