#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description:
	 *
	 * Arguments:
	 * 0: _money <NUMBER> - The amount of money to pay each player
     * 1: _days <NUMBER> - The number of days between payments (0 = sunday, 6 = saturday)
     * 2: _hours <NUMBER> - The hour of the day to make the payment (0-23)
     * 3: _minutes <NUMBER> - The minute of the hour to make the payment (0-59)
	 *
	 * Return Value:
	 * Boolean - true if the auto payment handler was successfully set up, false otherwise
	 *
	 * Example:
	 * [10, 6, 22, 30] call pc_missions_fnc_autoPayment //! Need to be executed by the server
	 *
	 * Public: No
 */

params [
    ["_money", 10, [0]],
    ["_days", 6, [0]],
    ["_hours", 22, [0]],
    ["_minutes", 30, [0]]
];

TRACE_1("fnc_autoPayment",_this);

if (!isDedicated) exitWith { false };

private _existingHandler = missionNamespace getVariable [QGVAR(autoPaymentHandler), -1];
if (_existingHandler isNotEqualTo -1) exitWith {
    TRACE_1("fnc_autoPayment: handler already running",_existingHandler);
    true
};

private _handler = [
    {
        params ["_money", "_days", "_hours", "_minutes"];
        private _serverTime = systemTime;
        _serverTime params ["_year", "_month", "_day", "_hour", "_minute"];

        // Day of week (0 = sunday, 6 = saturday)
        private _a = floor ((14 - _month) / 12);
        private _y = _year - _a;
        private _m = _month + (12 * _a) - 2;
        private _weekDay = (_day + _y + floor (_y / 4) - floor (_y / 100) + floor (_y / 400) + floor ((31 * _m) / 12)) mod 7;

        private _isSaturday = _weekDay isEqualTo _days;
        private _isTargetTime = (_hour isEqualTo _hours) && (_minute isEqualTo _minutes);

        if (_isSaturday && _isTargetTime) then {
            private _paymentKey = format ["%1-%2-%3-%4-%5", _year, _month, _day, _hour, _minute];
            private _lastPaymentKey = missionNamespace getVariable [QGVAR(lastAutoPaymentKey), ""];

            if (_paymentKey isNotEqualTo _lastPaymentKey) then {

                {
                    [ _x, _money ] call EFUNC(database,addMoneyToPlayer);
                    INFO_2("fnc_autoPayment: paid %1 to player %2",_money,name _x);
                } forEach allPlayers;

                missionNamespace setVariable [QGVAR(lastAutoPaymentKey), _paymentKey, true];
            };
        };
    },
    30,
    _this
] call CBA_fnc_addPerFrameHandler;

missionNamespace setVariable [QGVAR(autoPaymentHandler), _handler];

true;
