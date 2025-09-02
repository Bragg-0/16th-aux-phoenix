#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: get the description template for the mission
	 *
	 * Arguments:
	 * 0: _nameText (default: "16th Phoenix Company", Optional) <STRING> - The name of the mission.
	 * 1: _descriptionText (default: "Bienvenue à la Phoenix Company", Optional) <STRING> - The description of the mission.
	 * 2: _respawnDelay (default: 20, Optional) <NUMBER> - The respawn delay for the mission.
	 *
	 * Return Value:
	 * <STRING> - The description template for the mission.
	 *
	 * Example:
	 * [] call pc_missions_builder_fnc_getDescriptionTemplate
	 *
	 * Public: No
 */

params [
	["_nameText", "16th Phoenix Company", [""]],
	["_descriptionText", "Bienvenue à la Phoenix Company", [""]],
	["_respawnDelay", 20, [0]]
];

TRACE_1("fnc_getDescriptionTemplate",_this);

private _replacements = createHashMap;
_replacements set ["%MINIMAL_VERSION%", QUOTE(GVAR(minimalVersion))];
_replacements set ["%MINIMAL_VERSION_VALUE%", QUOTE(VERSION_AR)];
_replacements set ["%LOADSCREEN_PATH%", QPATHTOEF(missions,data\loadscreen_co.paa)];
_replacements set ["%AUTHOR%", str profileName];
_replacements set ["%MISSION_NAME%", str _nameText];
_replacements set ["%MISSION_DESCRIPTION%", str _descriptionText];
_replacements set ["%RESPAWN_DELAY%", _respawnDelay];

// Load template from external file
private _templateContent = loadFile QPATHTOF(data\description_template.inc);

// Apply replacements to template
{
    _templateContent = [_templateContent, _x, _y] call CBA_fnc_replace;
} forEach _replacements;

_templateContent
