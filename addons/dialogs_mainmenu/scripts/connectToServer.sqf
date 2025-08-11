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

private _serverAddress = "localhost";
private _serverPort = 2302;
private _serverName = "Default Server";

switch (ctrlIDC _control) do {
	case 6101: {
		_serverAddress = "game.phoenix-company.fr";
		_serverPort = 2302;
		_serverName = LSUBLSTRING(name1);
		INFO("Main Server selected");
	};
	default {
		INFO("Default Server selected");
	};
};

uiNamespace setVariable [QGVAR(ServerAddress), _serverAddress];
uiNamespace setVariable [QGVAR(ServerPort), _serverPort];
uiNamespace setVariable [QGVAR(ServerName), _serverName];

(findDisplay 0) createDisplay "RscCheckPassword";
