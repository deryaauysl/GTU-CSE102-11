#include <stdio.h>
#include <stdlib.h>

int numPathsHome(int streetnum, int avenuenum)
{
    if ((streetnum > 5 || avenuenum > 5) || (streetnum <= 0 || avenuenum <= 0))
    {
        printf("You're outside the city!\n");
        exit(0);
    }

    if (streetnum == 1 && avenuenum == 1)
    {
        return 0;
    }
    else if (avenuenum == 1 || streetnum == 1)
    {
        return 1;
    }

    return numPathsHome(streetnum - 1, avenuenum) + numPathsHome(streetnum, avenuenum - 1);
}

int main()
{
    int stnum = 0;
    int avenum = 0;
    int pathnum = 0;

    printf("Enter the street number: ");
    scanf("%d", &stnum);
    printf("Street: %d\n", stnum);

    printf("Enter the avenue number: ");
    scanf("%d", &avenum);
    printf("Avenue: %d\n", avenum);

    pathnum = numPathsHome(stnum, avenum);

    printf("Number of the optimal paths to take back home: %d\n", pathnum);
}
