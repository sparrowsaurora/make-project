#include <ncurses.h>
#include <stdio.h>

#include "options.h"

int main(int argc, char** argv) {
    const char* name = get_name(argc, argv);
    const supported_langs_t lang = get_lang();

    printf("name: %s, lang: %d", name, lang);
    /*
    initscr();
    printw("Hello ncurses!");
    refresh();
    getch();
    endwin();
    */
    return 0;
}
