#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Closes recent open attendance rows, usually at mission end.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <NONE>
 *
 * Public: No
 */

if !(isDedicated) exitWith {
    WARNING("fn_closeRecentAttendances: This function must be called on the server");
};

INFO("fn_closeRecentAttendances Query");

["closeRecentAttendances"] call FUNC(asyncCall);
