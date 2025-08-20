class ACE_Medical_Treatment_Actions {
	class Splint;
    class GVAR(Splint) : Splint {
        items[] = {QGVAR(Splint)};
        displayName = CSTRING(DOUBLES(Splint,ActionName));
        displayNameProgress = CSTRING(DOUBLES(Splint,ActionProgress));
    };
	class SurgicalKit;
	class GVAR(SurgicalKit) : SurgicalKit {
		items[] = {QGVAR(SurgicalKit)};
		displayName = CSTRING(DOUBLES(SurgicalKit,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Spray.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(SurgicalKit,ActionProgress));
	};
	class PersonalAidKit;
	class GVAR(PersonalAidKit) : PersonalAidKit {
		items[] = {QGVAR(PersonalAidKit)};
		displayName = CSTRING(DOUBLES(PersonalAidKit,ActionName));
		displayNameProgress = CSTRING(DOUBLES(PersonalAidKit,ActionProgress));
	};

	class Epinephrine;
	class GVAR(Epinephrine) : Epinephrine {
		items[] = {QGVAR(Epinephrine)};
		displayName = CSTRING(DOUBLES(Epinephrine,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Inject.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(Epinephrine,ActionProgress));
	};
	class Adenosine;
	class GVAR(Adenosine) : Adenosine {
		items[] = {QGVAR(Adenosine)};
		displayName = CSTRING(DOUBLES(Adenosine,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Inject.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(Adenosine,ActionProgress));
	};
	class Morphine;
	class GVAR(Morphine) : Morphine {
		items[] = {QGVAR(Morphine)};
		displayName = CSTRING(DOUBLES(Morphine,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Inject.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(Morphine,ActionProgress));
	};
	class Painkillers;
	class GVAR(Painkillers) : Painkillers {
		items[] = {QGVAR(Painkillers)};
		displayName = CSTRING(DOUBLES(Painkillers,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Pills.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(Painkillers,ActionProgress));
	};

	class PackingBandage;
	class GVAR(PackingBandage) : PackingBandage {
		items[] = {QGVAR(PackingBandage)};
		displayName = CSTRING(DOUBLES(PackingBandage,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Bandage.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(PackingBandage,ActionProgress));
	};
    class ElasticBandage;
	class GVAR(ElasticBandage) : ElasticBandage {
		items[] = {QGVAR(ElasticBandage)};
		displayName = CSTRING(DOUBLES(ElasticBandage,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Bandage.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(ElasticBandage,ActionProgress));
	};
    class QuikClot;
	class GVAR(QuikClot) : QuikClot {
		items[] = {QGVAR(QuikClot)};
		displayName = CSTRING(DOUBLES(QuikClot,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Bandage.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(QuikClot,ActionProgress));
	};

	class BloodIV;
	class GVAR(BloodIV) : BloodIV {
		items[] = {QGVAR(BloodIV)};
		displayName = CSTRING(DOUBLES(BloodIV,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Transfusion.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(BloodIV,ActionProgress));
	};
	class GVAR(BloodIV_250) : GVAR(BloodIV) {
		items[] = {QGVAR(BloodIV_250)};
		displayName = CSTRING(DOUBLES(BloodIV_250,ActionName));
	};
	class GVAR(BloodIV_500) : GVAR(BloodIV) {
		items[] = {QGVAR(BloodIV_500)};
		displayName = CSTRING(DOUBLES(BloodIV_500,ActionName));
	};

	class SalineIV;
	class GVAR(SalineIV) : SalineIV {
		items[] = {QGVAR(SalineIV)};
		displayName = CSTRING(DOUBLES(SalineIV,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Transfusion.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(SalineIV,ActionProgress));
	};
	class GVAR(SalineIV_250) : GVAR(SalineIV) {
		items[] = {QGVAR(SalineIV_250)};
		displayName = CSTRING(DOUBLES(SalineIV_250,ActionName));
	};
	class GVAR(SalineIV_500) : GVAR(SalineIV) {
		items[] = {QGVAR(SalineIV_500)};
		displayName = CSTRING(DOUBLES(SalineIV_500,ActionName));
	};

	class PlasmaIV;
	class GVAR(PlasmaIV) : PlasmaIV {
		items[] = {QGVAR(PlasmaIV)};
		displayName = CSTRING(DOUBLES(PlasmaIV,ActionName));
		sounds[] = {{QPATHTOF(data\sounds\Transfusion.ogg),1,1,50}};
		displayNameProgress = CSTRING(DOUBLES(PlasmaIV,ActionProgress));
	};
	class GVAR(PlasmaIV_250) : GVAR(PlasmaIV) {
		items[] = {QGVAR(PlasmaIV_250)};
		displayName = CSTRING(DOUBLES(PlasmaIV_250,ActionName));
	};
	class GVAR(PlasmaIV_500) : GVAR(PlasmaIV) {
		items[] = {QGVAR(PlasmaIV_500)};
		displayName = CSTRING(DOUBLES(PlasmaIV_500,ActionName));
	};

    class GVAR(Reorientation) : GVAR(Morphine) {
        displayName = CSTRING(DOUBLES(Reorientation,ActionName));
        displayNameProgress = CSTRING(DOUBLES(Reorientation,ActionProgress));
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        items[] = {};
        condition = "!([_patient] call ace_common_fnc_isAwake)";
        litter[] = {};
        callbackSuccess = QFUNC(onReorientation);
        animationMedic = "AinvPknlMstpSnonWnonDnon_medicUp4";
        animationMedicProne = "AinvPknlMstpSnonWnonDnon_medicUp4";
        sounds[] = {{QPATHTOF(data\sounds\Slap.ogg),1,1,50}};
    };
};
