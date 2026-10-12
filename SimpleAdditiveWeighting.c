#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rerataRAPOR[10];
float rerataUJIAN[10];
float keaktifan[10];
float tingkatKEAKTIFAN[3] = {60.0, 70.0, 80.0};
float prestasi[10];
float tingkatPRESTASI[16] = {0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0};
float pelanggaran[10];
float skorPRESTASI[10];

float raporMAX;
float ujianMAX;
float aktifMAX;
float prestasiMAX;
float pelanggaranMIN;
float skorpresMAX;

int findMAXmin()
{
    raporMAX = rerataRAPOR[0];
    ujianMAX = rerataUJIAN[0];
    aktifMAX = keaktifan[0];
    prestasiMAX = prestasi[0];
    pelanggaranMIN = pelanggaran[0];
    skorpresMAX = skorPRESTASI[0];

    for (int i = 0; i <= 9; i++)
    {
        if (rerataRAPOR[i] >= raporMAX)
        {
            raporMAX = rerataRAPOR[i];
        }
        else
        {
            raporMAX = raporMAX;
        }

        if (rerataUJIAN[i] >= ujianMAX)
        {
            ujianMAX = rerataUJIAN[i];
        }
        else
        {
            ujianMAX = ujianMAX;
        }

        if (keaktifan[i] >= aktifMAX)
        {
            aktifMAX = keaktifan[i];
        }
        else
        {
            aktifMAX = aktifMAX;
        }

        if (prestasi[i] >= prestasiMAX)
        {
            prestasiMAX = prestasi[i];
        }
        else
        {
            prestasiMAX = prestasiMAX;
        }

        if (pelanggaran[i] <= pelanggaranMIN)
        {
            pelanggaranMIN = pelanggaran[i];
        }
        else
        {
            pelanggaranMIN = pelanggaranMIN;
        }

        if (skorPRESTASI[i] >= skorpresMAX)
        {
            skorpresMAX = skorPRESTASI[i];
        }
        else
        {
            skorpresMAX = skorpresMAX;
        }
    }

    return 0;
}

int normalisasi()
{
    printf("==================== hasil normalisasi ======================\n\n");
    for (int i = 0; i <= 9; i++)
    {
        rerataRAPOR[i] = rerataRAPOR[i] / raporMAX;
        printf("rerata rapor: %.4f, %i\n", rerataRAPOR[i], i);
        rerataUJIAN[i] = rerataUJIAN[i] / ujianMAX;
        printf("rerata ujian: %.4f, %i\n", rerataUJIAN[i], i);
        keaktifan[i] = keaktifan[i] / aktifMAX;
        printf("keaktifan: %.4f, %i\n", keaktifan[i], i);
        prestasi[i] = prestasi[i] / prestasiMAX;
        printf("prestasi: %.4f, %i\n", prestasi[i], i);
        skorPRESTASI[i] = skorPRESTASI[i] / skorpresMAX;
        printf("skor prestasi: %.4f, %i\n", skorPRESTASI[i], i);

        if (pelanggaranMIN == 0)
        {
            pelanggaranMIN = 0.01;
        }

        if (pelanggaran[i] == 0)
        {
            pelanggaran[i] = 0.01;
        }

        pelanggaran[i] = pelanggaranMIN / pelanggaran[i];
        printf("pelanggaran: %.4f, %i\n\n", pelanggaran[i], i);
    }
    printf("=====================================================\n\\n");

    printf("====================== max & min ======================\n\n");
    printf("raporMAX: %.2f\n", raporMAX);
    printf("ujianMAX: %.2f\n", ujianMAX);
    printf("aktifMAX: %.2f\n", aktifMAX);
    printf("prestasiMAX: %.2f\n", prestasiMAX);
    printf("skorpresMAX: %.2f\n", skorpresMAX);
    printf("pelanggaranMIN: %.2f\n\n", pelanggaranMIN);
    printf("=======================================================\n\n");

    return 0;
}

int preferenceVALUE()
{
    printf("=================== nilai preferensi ======================\n\n");
    float preference[10];
    for (int i = 0; i <= 9; i++)
    {
        preference[i] = rerataRAPOR[i] * 0.4 + rerataUJIAN[i] * 0.45 + prestasi[i] * 0.5 + keaktifan[i] * 0.15 + skorPRESTASI[i] * 0.25 + pelanggaran[i] * 0.25;

        printf("preference value: %.4f, %i\n", preference[i], i);
    }
    printf("============================================================\n\n");

    return 0;
}

int main()
{
    srand(time(0));

    printf("============== GENERATE NILAI =====================\n\n");
    for (int i = 0; i <= 9; i++)
    {
        float raporACAK = ((float)rand() / (float)RAND_MAX) * (100.0 - 75.0) + 75.0;
        rerataRAPOR[i] = raporACAK;
        printf("rerataRAPOR: %.2f, %i\n", rerataRAPOR[i], i);

        float ujianACAK = ((float)rand() / (float)RAND_MAX) * (100.0 - 75) + 75.0;
        rerataUJIAN[i] = ujianACAK;
        printf("rerataUJIAN: %.2f, %i\n", rerataUJIAN[i], i);

        int aktifACAK = rand() % 3;
        keaktifan[i] = tingkatKEAKTIFAN[aktifACAK];
        printf("keaktifan: %.2f, %i\n", keaktifan[i], i);

        int prestasiACAK = rand() % 16;
        prestasi[i] = tingkatPRESTASI[prestasiACAK];
        printf("prestasi: %.2f, %i\n", prestasi[i], i);

        int pelanggaranACAK = rand() % 16;
        pelanggaran[i] = pelanggaranACAK;
        printf("pelanggaran: %.2f, %i\n", pelanggaran[i], i);

        int skorpresACAK = rand() % 25;
        skorPRESTASI[i] = skorpresACAK;
        printf("skor prestasi: %.2f, %i\n\n\n", skorPRESTASI[i], i);
    }

    printf("================================\n\n");

    findMAXmin();
    normalisasi();
    preferenceVALUE();
    return 0;
}