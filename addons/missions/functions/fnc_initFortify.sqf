#include "..\script_component.hpp"
/*
    * Authors: Bragg
    * Description: Initializes the fortification system for the mission.
    *
    * Arguments:
    * 0: _side (optional, default: west) <side> - The side for which the fortification system will be initialized.
    *
    * Return Value:
    * <NONE>
    *
    * Example:
    * [params] call PREFIX_missions_fnc_initFortify
    *
    * Public: No
 */

params [
    ["_side", west, [west]]
];

TRACE_1("fnc_initFortify",_this);

[_side, 10000, [
	["3AS_Barricade_2_C_prop", 25],
	["3AS_Cover1", 15],
	["3AS_Cover2", 20],
	["3AS_H_barrier_small_1", 40],
	["3AS_H_barrier_small_3", 50],
	["3AS_H_barrier_small_5", 50],
	["3AS_Short_Wall_Bunker", 80],
	["Land_Plank_01_4m_F", 5],
	["Land_Plank_01_8m_F", 10],
	["land_3as_GenericStairsS", 50],
	["land_3as_Ladder3", 15]
]] call acex_fortify_fnc_registerObjects;
