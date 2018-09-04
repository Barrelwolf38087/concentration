#ifndef _WIN32

#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

/*
NOTE: A lot if this is very similar, if not identical, to
      the Windows code. This redundancy is intentional.
      The Windows code works by exploiting conhost.exe's
      unusual mechanics, and is much simpler in nature.
      However, this means it doesn't work on *NIX (or in minpty
      for that matter). So, we must use the ncurses library
      to create similar behavior. I would use this as the sole
      implementation, but ncurses is a bitch to install
      and run on Windows. Thanks, Microsoft!
*/
unsigned int doOther(unsigned int uiDIFFICULTY, int iaNums[])
{
    int i;
    int pos = 0;

    // Begin ncurses mode

    // Begin initialization

    initscr();

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
        printw("%d", i); sleep(1);
        move(pos, 0); // Beginning of current line
        refresh();
    }

    // End main logic

    #ifdef DEBUG
    getch();
    #endif

    endwin();

    // End ncurses mode

    return uiDIFFICULTY;
}
#endif
