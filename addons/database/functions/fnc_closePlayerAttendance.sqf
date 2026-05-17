#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Closes the latest open attendance row for a player.
 *
 * Arguments:
 * 0: _uid <STRING> - Steam ID of the player.
 *
 * Return Value:
 * <NONE>
 *
 * Public: No
 */

params [
    ["_uid", "", [""]]
];

if !(isDedicated) exitWith {
    WARNING("fn_closePlayerAttendance: This function must be called on the server");
};

if (_uid isEqualTo "") exitWith {
    WARNING("fn_closePlayerAttendance: Empty Steam ID");
};

private _query = FORMAT_1("closePlayerAttendanceBySteamId:%1",_uid);
TRACE_1("fn_closePlayerAttendance Query",_query);

[_query] call FUNC(asyncCall);
