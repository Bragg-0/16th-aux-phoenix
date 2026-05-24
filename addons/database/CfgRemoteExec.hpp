class CfgRemoteExec {
    class Functions {
        mode = 2;
        jip = 1;

        SERVER_REMOTE_FUNC(addMoneyToPlayer);
        SERVER_REMOTE_FUNC(asyncCall);
        SERVER_REMOTE_FUNC(extractPlayerData);
        SERVER_REMOTE_FUNC(init);
        SERVER_REMOTE_FUNC(payAllPlayers);
        SERVER_REMOTE_FUNC(updatePlayerData);
    };
    class Commands {
        mode = 1;
        class systemChat {
            allowedTargets = 0;
        };
    };
};
