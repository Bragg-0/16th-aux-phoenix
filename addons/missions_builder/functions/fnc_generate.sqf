#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Initialize mission parameters
	 *
	 * Arguments:
	 * <NONE>
	 *
	 * Return Value:
	 * <BOOLEAN> - Returns true if the generation was successful, false otherwise.
	 *
	 * Example:
	 * call pc_missions_builder_fnc_generate
	 *
	 * Public: No
 */

TRACE_1("fnc_generate",_this);

private _preparedDataDescriptionEXT = [] call FUNC(getDescriptionTemplate);

private _handler = ["description.ext", _preparedDataDescriptionEXT] call FUNC(createFile);

if !(_handler) exitWith {
	[LLSTRING(errorGenerationDescriptionEXT), 1] call BIS_fnc_3DENNotification;
    false
};

[LLSTRING(successGenerationDescriptionEXT)] call BIS_fnc_3DENNotification;
true
