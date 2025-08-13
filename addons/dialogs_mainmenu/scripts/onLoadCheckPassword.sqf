#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Function to initialize the Check Password dialog.
	 *
	 * Arguments:
	 * <NONE>
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [] execVM '\x\pc\addons\dialogs_mainmenu\scripts\onLoadCheckPassword.sqf';
	 *
	 * Public: No
 */

TRACE_1("onLoadCheckPassword.sqf",_this);

private _savedPassword = profileNamespace getVariable [QGVAR(PasswordSaved), ""];

private _passwordInput = findDisplay 6100 displayCtrl 1234;
private _header = findDisplay 6100 displayCtrl 1000;

if (_savedPassword isEqualTo "") then {
	_passwordInput ctrlSetText "";
	INFO("No saved password found, password input is empty.");
} else {
	_passwordInput ctrlSetText _savedPassword;
	INFO("Saved password found, password input set to saved value.");
};
