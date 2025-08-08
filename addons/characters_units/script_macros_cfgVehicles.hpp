#define MAGS_X2(var1) var1,var1
#define MAGS_X3(var1) MAGS_X2(var1),var1
#define MAGS_X4(var1) MAGS_X3(var1),var1
#define MAGS_X5(var1) MAGS_X4(var1),var1
#define MAGS_X6(var1) MAGS_X5(var1),var1
#define MAGS_X7(var1) MAGS_X6(var1),var1
#define MAGS_X8(var1) MAGS_X7(var1),var1
#define MAGS_X9(var1) MAGS_X8(var1),var1
#define MAGS_X10(var1) MAGS_X9(var1),var1
#define MAGS_X20(var1) MAGS_X10(var1),MAGS_X10(var1)
#define MAGS_X30(var1) MAGS_X20(var1),MAGS_X10(var1)
#define MAGS_X40(var1) MAGS_X30(var1),MAGS_X10(var1)

#define WEAPONS(var1,var2,var3) \
{ var1,var2,var3,"JLTS_CloneBinocular","Throw","Put" }

#define DC17S "3AS_DC17S_F"
#define DC17S_MAG "3AS_16Rnd_EC20_Mag"

#define Z6 "JLTS_Z6"
#define Z6_MAG "JLTS_Z6_mag"

#define DC15S "3AS_DC15S_F"
#define DC15A_GL "3AS_DC15A_GL"
#define DC15S_MAG "3AS_60Rnd_EC30_mag"
#define DC15A_MAG "3AS_45Rnd_EC50_mag"
#define DC15A_MAG_GL "3AS_3UGL_MK54_HE_shell"

#define RPS6 "3AS_RPS6_HP"
#define RPS6_MAG "3AS_MK41_AT"

#define CTBI "ls_grenade_n20_magazine"
#define DETONATOR "3AS_ThermalDetonator"

#define WEAPON_DEFAULT \
WEAPONS(DC15S,DC17S,"")

#define MAGAZINE_DEFAULT \
MAGS_X7(DC15S_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI

#define ITEM_DEFAULT \
"FirstAidKit","FirstAidKit", "FirstAidKit"

#define LINKED_ITEMS_DEFAULT \
"ItemMap","ItemCompass","ACE_Altimeter","ls_radios_cwp8","ItemGPS"
