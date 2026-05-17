#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Records a player connection in operation_arma3_attendance.
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
    WARNING("fn_insertPlayerAttendance: This function must be called on the server");
};

if (_uid isEqualTo "") exitWith {
    WARNING("fn_insertPlayerAttendance: Empty Steam ID");
};

private _query = FORMAT_1("insertPlayerAttendanceBySteamId:%1",_uid);
TRACE_1("fn_insertPlayerAttendance Query",_query);

[_query] call FUNC(asyncCall);
