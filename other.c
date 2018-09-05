#ifndef _WIN32

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

/*
NOTE: A lot if this is very similar to
      the Windows code. The Windows code works by
      exploiting conhost.exe's unusual mechanics,
      and is much simpler in nature.
      However, this means it doesn't work on *NIX (or in minpty
      for that matter). So, we must use the ncurses library
      to create similar behavior. I would use this as the sole
      implementation, but ncurses is a bitch to install
      and run on Windows. Thanks, Microsoft!
*/
unsigned int doOther(unsigned int uiDIFFICULTY, int iaNums[])
{
    int i;
    int pos = 0; // Probably better to use getyx, but this will work for now

    // Begin ncurses mode

    // Begin initialization

    initscr();
    noecho();

    // End initialization

    // Begin main logic

    printw("Memorize these:\n\t"); pos++;
    for ( i = 0; i < uiDIFFICULTY; i++ )
    {
        // Display the numbers with three columns, indented with a tab
        printw("%d\t", iaNums[i]);
        if ( ( i + 1 ) % 3 == 0 )
        {
            printw("\n\t"); pos++;
        }
    }

    // Padding
    printw("\n\n"); pos = pos + 2;
    printw("You have ten seconds.\n"); sleep(1); pos++;

    refresh();

    for ( i = 10; i > 0; i-- )
    {
        clrtoeol();
        printw("%d", i);
        move(pos, 0); // Beginning of current line
        refresh();
        sleep(1);
    }

    erase();
    pos = 0;

    echo();
    char respBuffer[3];
    int iaResp[uiDIFFICULTY];
    unsigned int uiScore = uiDIFFICULTY;
    for ( i = 0; i < uiDIFFICULTY; i++ )
    {
        // Equivalent to the "\r" in the Windows code
        move(pos, 0);
        printw("%d] ", i + 1);

        // TODO: Get string; parse to int; add to iaResp

        getstr(respBuffer);
        iaResp[i] = (int)strtol(respBuffer, NULL, 10);

        if ( iaResp[i] != iaNums[i] )
        {
            printw("Incorrect! The correct answer was %d.\n", iaNums[i]); pos++;

            // Pause to display the message if it's the last number
            if ( i == ( uiDIFFICULTY - 1) )
            {
                printw("Press any key to continue.");
                nocbreak();
                noecho();
                getch();
                cbreak();
            }
            uiScore--;
        }

        pos++;
    }

    // End main logic

    endwin();

    // End ncurses mode

    return uiScore;
}
#endif
