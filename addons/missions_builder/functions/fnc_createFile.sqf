#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Create a file in mission folder
	 *
	 * Arguments:
	 * 0: _filename (default: "init.sqf") <STRING> - The name of the file to create or modify in the mission directory.
	 * 1: _data (default: "hint 'Hello World';") <STRING> - The content to write into the file.
	 *
	 * Return Value:
	 * <BOOLEAN> - Returns true if the file was successfully written, false otherwise.
	 *
	 * Example:
	 * ["init.sqf", "hint 'Hello World';"] call pc_missions_builder_fnc_createFile
	 *
	 * Public: No
 */

params [
    ["_filename", "init.sqf", [""]],
    ["_data", "", [""]]
];

TRACE_1("fnc_createFile",_this);

private _filePath = getMissionPath _filename; // Get the full path to the file in the mission directory

private _escapedFilePath = FORMAT_1('"%1"',_filePath); // Enclose the file path in double quotes

private _commandString = FORMAT_2("write %1 %2",_escapedFilePath,_data); // Prepare the command string

private _result = "Arma3FileWriter" callExtension _commandString; // Call the extension
TRACE_1("fnc_createFile",_result);

if (_result != "SUCCESS") exitWith {
	WARNING("fnc_createFile - Error writing file: " + _result);
	false
};

true
