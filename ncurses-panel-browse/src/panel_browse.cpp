/*-----------------------------------------------------------------------------
* File Name: panel_browse.cpp
* Purpose:
* Creation Date: 26-06-2020
* Last Modified: Fri 26 Jun 2020 02:09:04 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/
#include <panel.h>
#include <string.h>

#define NLINES 10
#define NCOLS 40

void init_wins(WINDOW **wins, int n);
void win_show(WINDOW *win, char *label, int label_color);
void print_in_middle(WINDOW *win, int starty, int startx, int width,
                     char *string, chtype color);

int main(){
    WINDOW *wins[3];
    PANEL  *panels[3];
    PANEL  *top;
    int ch;

    /* Initialize curses */
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    init_wins(wins, 3);

    /* Attach a panel to each window */
    panels[0] = new_panel(wins[0]);
    panels[1] = new_panel(wins[1]);
    panels[2] = new_panel(wins[2]);

    /* Set up the user pointers to the next panel */
    set_panel_userptr(panels[0], panels[1]);
    set_panel_userptr(panels[1], panels[2]);
    set_panel_userptr(panels[2], panels[0]);

    /* Update the stacking order. 2nd panel will be on top */
    update_panels();

    /* Show it on the screen */
    attron(COLOR_PAIR(4));
    mvprintw(NLINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
    attroff(COLOR_PAIR(4));
    doupdate();

    top = panels[2];
    while ((ch = getch()) != KEY_F(1)) {
        switch (ch) {
            case 9:
                top = (PANEL *) panel_userptr(top);
                top_panel(top);
                break;
        }
        update_panels();
        doupdate();
    }

    endwin();

    return 0;
}

/* Put all the windows */
void init_wins(WINDOW **wins, int n) {
    int x, y;
    char label[80];

    x = 2;
    y = 10;
    for (int i = 0; i < n; i++) {
        wins[i] = newwin(NLINES, NCOLS, y, x);
        sprintf(label, "Window Number %d", i + 1);
        win_show(wins[i], label, i + 1);
        y += 3;
        x += 7;
    }
}

/* Show the window with a border and a label */
void win_show(WINDOW *win, char *label, int label_color) {
    int startx, starty;
    int height, width;

    //getbegyx(win, starty, startx);
    getmaxyx(win, height, width);

    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE);
    mvwhline(win, 2, 1, ACS_HLINE, width - 2);
    mvwaddch(win, 2, width - 1, ACS_RTEE);

    print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}


void print_in_middle(WINDOW *win, int starty, int startx, int width,
                     char *string, chtype color) {

    int x, y, length;
    float temp;

    if (win == NULL) {
        win = stdscr;
    }

    getyx(win, x, y);
    if (startx != 0) {
        x = startx;
    }
    if (starty != 0) {
        y = starty;
    }
    if (width == 0) {
        width = 80;
    }

    length = strlen(string);
    temp = (width - length) / 2;
    x = startx + (int) temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}
