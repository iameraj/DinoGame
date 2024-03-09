#pragma once
#include <ncurses.h>

namespace draw {

void ground(int height) {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    for (int i = 0; i < max_x; i++) {
        mvprintw(height, i, "*");
    }
    move(height, 0);
}

void dino(int x_position, int y_position, int height) {

    const char *dino = "                __ \n"
                       "               / -)\n"
                       "      _.----._/ /  \n"
                       "     /         /   \n"
                       "  __/         |    \n"
                       " /_____|_|--|_|    \n";

    mvprintw(y_position, x_position, "%s", dino);
    move(height, 0);
}

void tree(int x_position, int tree_height, int ground_height) {

    const char *tree = "###";
    for (int i = 0; i < tree_height; i++) {
        mvprintw(ground_height - i, x_position, "%s", tree);
    };
    move(ground_height, 0);
}

} // namespace draw
