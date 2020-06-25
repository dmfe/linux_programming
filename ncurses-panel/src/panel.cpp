/*-----------------------------------------------------------------------------
* File Name: panel.cpp
* Purpose:
* Creation Date: 26-06-2020
* Last Modified: Fri 26 Jun 2020 12:46:26 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <panel.h>

int main() {
    WINDOW *wins[3];
    PANEL *panels[3];
    int lines = 10;
    int cols = 40;
    int y = 2;
    int x = 4;

    initscr();
    cbreak();
    noecho();

    /* Create windows for the panels */
    wins[0] = newwin(lines, cols, y, x);
    wins[1] = newwin(lines, cols, y + 1, x + 5);
    wins[2] = newwin(lines, cols, y + 2, x + 10);

    /* Create borders around the windows so that you can see the effect
       of panels
    */
    for (int i = 0; i < 3; i++) {
        box(wins[i], 0, 0);
    }

    /* Attach a panel to each window */
    panels[0] = new_panel(wins[0]);
    panels[1] = new_panel(wins[1]);
    panels[2] = new_panel(wins[2]);

    /* Update the stacking order. 2nd panel will be on the top */
    update_panels();

    /* Show it on the screen */
    doupdate();

    getch();
    endwin();

    return 0;
}
