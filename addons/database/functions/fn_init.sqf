#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Sets up the database connection. (Should be run on the dedicated server)
	 *
	 * Arguments:
	 * <NONE>
	 *
	 * Return Value:
	 * <BOOL>
	     * - <true> : if the connection was successful
	     * - <false> : otherwise
	 *
	 * Example:
	 * [] call pc_database_fnc_init
	 *
	 * Public: No
 */

if (isDedicated) then {
	INFO("[extDB3] Initializing database connection...");

	_dbName = "a3phoenix";
    _dbCustomFileName = "a3phoenix.ini";

    GVAR(protocolID) = "sqf_a3phoenix";
    publicVariable QGVAR(protocolID);

	// Connexion à la DB
	private _dbLoad = "extDB3" callExtension FORMAT_1("9:ADD_DATABASE:%1",_dbName);
    if (_dbLoad#0 isEqualTo 0) exitWith {
        ERROR_1("[extDB3] Failed to load database: %1",_dbLoad#1);
        GVAR(protocolID) = "";
        publicVariable QGVAR(protocolID);
        false
    };
    INFO_1("[extDB3] Database %1 loaded successfully.",_dbName);

	// Activation du protocole
	private _dbProto = "extDB3" callExtension FORMAT_3("9:ADD_DATABASE_PROTOCOL:%1:SQL_CUSTOM:%2:%3",_dbName,GVAR(protocolID),_dbCustomFileName);
    if (_dbProto#0 isEqualTo 0) exitWith {
        ERROR_1("[extDB3] Failed to activate database protocol: %1",_dbProto#1);
        GVAR(protocolID) = "";
        publicVariable QGVAR(protocolID);
        false
    };
    INFO_1("[extDB3] Database protocol %1 activated successfully.",GVAR(protocolID));

    "extDB3" callExtension "9:LOCK";
    INFO_1("[extDB3] Database %1 locked successfully.",_dbName);

    INFO_2("[extDB3] Database %1 connection by %2 initialized successfully.",_dbName,GVAR(protocolID));
    true
};
