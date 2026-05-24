#include "..\script_component.hpp"
/*
 * Authors: Bragg
 * Description: Pays all connected players a given amount and notifies them.
 *
 * Arguments:
 * 0: _amount <NUMBER> - The amount to add to each player
 *
 * Return Value:
 * <NONE>
 *
 * Public: No
 */

params [
    ["_amount",0,[0]]
];

if !(isDedicated) exitWith {
    WARNING("fnc_payAllPlayers: This function must be called on the server");
};

if (_amount <= 0) exitWith {
    WARNING("fnc_payAllPlayers: Amount must be positive");
};

TRACE_1("fnc_payAllPlayers",_amount);

{ [_x,_amount] call FUNC(addMoneyToPlayer); } forEach allPlayers;

private _message = format ["Vous avez reçu %1 crédits",_amount];
[_message] remoteExec ["systemChat",0];

INFO_2("payAllPlayers: %1 crédits versés à %2 joueurs",_amount,count allPlayers);
