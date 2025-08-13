#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Function to connect to the server.
	 *
	 * Arguments:
	 * 0: _control (default: controlNull) <CONTROL> - The control on which the connection will be initiated.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myControl, 1] execVM '\x\pc\addons\dialogs_mainmenu\scripts\connectToServer.sqf';
	 *
	 * Public: No
 */

params [
	["_control", controlNull, [controlNull]]
];

TRACE_1("connectToServer.sqf",_this);

private _serverAddress = "game.phoenix-company.fr";
private _serverPort = 2302;

uiNamespace setVariable [QGVAR(ServerAddress), _serverAddress];
uiNamespace setVariable [QGVAR(ServerPort), _serverPort];

(findDisplay 0) createDisplay "RscCheckPassword";
