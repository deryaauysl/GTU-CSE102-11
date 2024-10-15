#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_HOSPITALS 100
#define MAX_CITIES 100

typedef struct
{
    char *name;
    char citiesServed[3];
} Hospital;

/*Bu fonksiyon belirli bir şehrin bir hastane tarafından kapsanıp kapsanmadığını kontrol eder*/
bool coversCity(Hospital hospital, char city)
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        if (hospital.citiesServed[i] == city)
        {
            return true;
        }
    }
    return false;
}

/* Bu fonksiyon tüm şehirlerin kapsanıp kapsanmadığını kontrol eder*/
bool allCitiesCovered(char cities[], int numCities, Hospital hospitals[], bool selected[], int numHospitals)
{
    int i = 0;
    for (i = 0; i < numCities; i++)
    {
        bool covered = false;
        int j = 0;
        for (j = 0; j < numHospitals; j++)
        {
            if (selected[j] && coversCity(hospitals[j], cities[i]))
            {
                covered = true;
                break;
            }
        }
        if (!covered)
        {
            return false;
        }
    }
    return true;
}

/*Recursive fonksiyon, hastanelerin seçimini kontrol eder*/
bool canCoverAllCities(char cities[], int numCities, Hospital hospitals[], int numHospitals, bool selected[], int currentHospitalIndex, int remainingHospitals)
{
    /*Eğer tüm şehirler kapsandıysa, true döndür*/
    if (allCitiesCovered(cities, numCities, hospitals, selected, numHospitals))
    {
        return true;
    }

    /*Eğer daha fazla hastane kuramıyorsak veya tüm hastaneler incelendiyse, false döndür*/
    if (remainingHospitals == 0 || currentHospitalIndex >= numHospitals)
    {
        return false;
    }

    /*Şu anki hastaneyi seçmemek*/
    if (canCoverAllCities(cities, numCities, hospitals, numHospitals, selected, currentHospitalIndex + 1, remainingHospitals))
    {
        return true;
    }

    /*Şu anki hastaneyi seçmek*/
    selected[currentHospitalIndex] = true;
    if (canCoverAllCities(cities, numCities, hospitals, numHospitals, selected, currentHospitalIndex + 1, remainingHospitals - 1))
    {
        return true;
    }
    selected[currentHospitalIndex] = false;

    return false;
}

int main()
{
    /*Şehirleri tanımla*/
    char cities[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int numCities = sizeof(cities) / sizeof(cities[0]);

    /* Hastaneleri tanımla*/
    Hospital hospitals[] = {
        {"Hospital 1", {'A', 'B', 'C'}},
        {"Hospital 2", {'A', 'C', 'D'}},
        {"Hospital 3", {'B', 'F'}},
        {"Hospital 4", {'C', 'E', 'F'}}};
    int numHospitals = sizeof(hospitals) / sizeof(hospitals[0]);

    /*Maksimum kurulabilecek hastane sayısı*/
    int maxHospitals;
    printf("Enter the max constucted hospital: ");
    scanf("%d", &maxHospitals);

    /* Hastane seçimi için kullanılan dizi*/
    bool selected[MAX_HOSPITALS] = {false};

    /* Fonksiyonu çağır ve sonucu kontrol et*/
    if (canCoverAllCities(cities, numCities, hospitals, numHospitals, selected, 0, maxHospitals))
    {
        printf("It is possible to cover all cities with the given number of hospitals.\n");
        printf("Selected hospitals:\n");
        int i = 0;
        for (i = 0; i < numHospitals; i++)
        {
            if (selected[i])
            {
                printf("%s\n", hospitals[i].name);
            }
        }
    }
    else
    {
        printf("It is not possible to cover all cities with the given number of hospitals.\n");
    }

    return 0;
}
