class ACE_Medical_Treatment {
    class Medication {
        class GVAR(Epinephrine) {
            painReduce = 0;
            hrIncreaseLow[] = { 10, 20 };
            hrIncreaseNormal[] = { 10, 50 };
            hrIncreaseHigh[] = { 10, 40 };
            timeInSystem = 120;
            timeTillMaxEffect = 10;
            maxDose = 10;
            incompatibleMedication[] = {};
        };

        class GVAR(Adenosine) {
            painReduce = 0;
            hrIncreaseLow[] = { -7, -10 };
            hrIncreaseNormal[] = { -15, -30 };
            hrIncreaseHigh[] = { -15, -35 };
            timeInSystem = 120;
            timeTillMaxEffect = 15;
            maxDose = 6;
            incompatibleMedication[] = {};
        };

        class GVAR(Morphine) {
            painReduce = 0.8;
            hrIncreaseLow[] = { -10, -20 };
            hrIncreaseNormal[] = { -10, -30 };
            hrIncreaseHigh[] = { -10, -35 };
            timeInSystem = 1800;
            timeTillMaxEffect = 30;
            maxDose = 4;
            incompatibleMedication[] = {};
            viscosityChange = -10;
        };

        class GVAR(Painkillers) {
            painReduce = 0.1;
            timeInSystem = 600;
            timeTillMaxEffect = 60;
            maxDose = 6;
            incompatibleMedication[] = {};
            viscosityChange = 5;
        };
    };
    class Bandaging {
        SIMPLE_INHERITANCE(PackingBandage);
        SIMPLE_INHERITANCE(ElasticBandage);
        SIMPLE_INHERITANCE(QuikClot);
    };
    class IV {
        SIMPLE_INHERITANCE(BloodIV);
        SIMPLE_INHERITANCE(BloodIV_250);
        SIMPLE_INHERITANCE(BloodIV_500);
        SIMPLE_INHERITANCE(SalineIV);
        SIMPLE_INHERITANCE(SalineIV_250);
        SIMPLE_INHERITANCE(SalineIV_500);
        SIMPLE_INHERITANCE(PlasmaIV);
        SIMPLE_INHERITANCE(PlasmaIV_250);
        SIMPLE_INHERITANCE(PlasmaIV_500);
    };
};
