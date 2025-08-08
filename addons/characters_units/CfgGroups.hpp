#define CHARACTERS_TYPE Regs

class CfgGroups {
    class West {
        class PC_16th_Aux_Phoenix {
            name = ECSTRING(Main,3den_FactionBlufor);
            class Infantry {
                name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY0";
                class InfSquad {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFSQUAD0";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QCVARF(Lieutenant);
                        rank = "LIEUTENANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QCVARF(Trooper);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,EOD);
                        rank = "CORPORAL";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,AT);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                    class Unit4 {
                        side = BLUFOR;
                        vehicle = QCVARF(Sergent);
                        rank = "SERGEANT";
                        position[] = { -10, -10, 0 };
                    };
                    class Unit5 {
                        side = BLUFOR;
                        vehicle = QCVARF(Trooper);
                        rank = "CORPORAL";
                        position[] = { 15, -15, 0 };
                    };
                    class Unit6 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,Heavy);
                        rank = "PRIVATE";
                        position[] = { -15, -15, 0 };
                    };
                    class Unit7 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,Medic);
                        rank = "PRIVATE";
                        position[] = { 20, -20, 0 };
                    };
                };
                class InfTeam {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFTEAM0";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QCVARF(Sergent);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,AT);
                        rank = "CORPORAL";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QCVARF(Trooper);
                        rank = "PRIVATE";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,Medic);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                };
                class InfTeam_AT {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFTEAM_AT0";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QCVARF(Sergent);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,AT);
                        rank = "CORPORAL";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,AT);
                        rank = "PRIVATE";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,AT);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                };
                class InfSentry {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFSENTRY0";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,Heavy);
                        rank = "CORPORAL";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QCVARF(Trooper);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                };
                class ReconSentry {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_RECONSENTRY0";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_recon.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QCVARF(Caporal);
                        rank = "CORPORAL";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QCVARF(Trooper);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                };
                class ShinySquad {
                    name = "Shiny Squad";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QCVARF(Lieutenant);
                        rank = "LIEUTENANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QCVARF(Shiny);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVARF(Shiny,EOD);
                        rank = "CORPORAL";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVARF(Shiny,AT);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                    class Unit4 {
                        side = BLUFOR;
                        vehicle = QECVARF(Shiny,Heavy);
                        rank = "PRIVATE";
                        position[] = { -10, -10, 0 };
                    };
                    class Unit5 {
                        side = BLUFOR;
                        vehicle = QECVARF(Shiny,Medic);
                        rank = "PRIVATE";
                        position[] = { 15, -15, 0 };
                    };
                };
                class ShinyTeam {
                    name = "Shiny Team";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QCVARF(Sergent);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QCVARF(Shiny);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVARF(Shiny,Grenadier);
                        rank = "CORPORAL";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVARF(Shiny,Medic);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                };
                class PilotTeam {
                    name = "Pilot Team";
                    side = BLUFOR;
                    faction = QEGVAR(Main,3den_FactionBlufor);
                    icon = "\A3\ui_f\data\map\markers\nato\b_air.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVARF(Shiny,Pilot);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVARF(Trooper,Pilot);
                        rank = "CORPORAL";
                        position[] = { 5, -5, 0 };
                    };
                };
            };
        };
    };
};

#undef CHARACTERS_TYPE
