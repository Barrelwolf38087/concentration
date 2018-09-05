#ifdef _WIN32

#include <stdio.h>
#include <Windows.h>

unsigned int doWindows(unsigned int uiDIFFICULTY, int iaNums[])
{
    int i;

    printf("Memorize these:\n\t");
    for ( i = 0; i < uiDIFFICULTY; i++ )
    {
        // Display the numbers with three columns, indented with a tab
        printf("%d\t", iaNums[i]);
        if ( ( i + 1 ) % 3 == 0 )
            printf("\n\t");
    }
    printf("\n\n"); // Make sure we have enough padding

    printf("You have ten seconds.\n"); Sleep(1000);
    printf("Go!\n");

    for ( i = 10; i > 0; i-- )
    {
        printf("%d \r", i); Sleep(1000);
    }

    system("cls");

    printf("Time's up!\nLet's see if you can recall those numbers.\n");

    int iaResp[uiDIFFICULTY];
    unsigned int uiScore = uiDIFFICULTY;
    for ( i = 0; i < uiDIFFICULTY; i++ )
    {
        printf("\r%d] ", i + 1);
        scanf("%d", &iaResp[i]);

        if ( iaResp[i] != iaNums[i] )
        {
            printf("Incorrect! The correct answer was %d.\n", iaNums[i]);
            uiScore--;
        }
    }

    return uiScore;
}

#endif
