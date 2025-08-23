#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Open the loadout menu
	 *
	 * Arguments:
	 * _caller <OBJECT> - The unit calling the function
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call pc_dialogs_loadout_fnc_open
	 *
	 * Public: No
 */

params [
	["_caller", objNull, [objNull]]
];

TRACE_1("fnc_open",_this);

if (isNull _caller || !isPlayer _caller) exitWith {
    ERROR("fnc_open: Invalid caller provided");
};

createDialog "RscLoadoutMenu";
