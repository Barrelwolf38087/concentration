#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "concentration.h"

int main()
{
    int i;

    unsigned int uiDIFFICULTY;
    srand(time(NULL));

    printf("Enter difficulty: ");
    scanf("%u", &uiDIFFICULTY);
    printf("\n");

    int iaNums[uiDIFFICULTY];

    // Populate iaNums
    for ( i = 0; i < uiDIFFICULTY; i++ )
    {
        iaNums[i] = (rand() % 100) + 1;
    }

    unsigned int uiScore;
    #ifdef _WIN32
        uiScore = doWindows(uiDIFFICULTY, iaNums);
    #else
        uiScore = doOther(uiDIFFICULTY, iaNums);
    #endif


    printf("You got %u out of %u correct. Your average was %.2f%%.\n",
           uiScore, uiDIFFICULTY, ( (float)uiScore / (float)uiDIFFICULTY ) * 100);

    return 0;
}
