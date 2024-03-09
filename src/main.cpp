#include "./draw.cpp"
#include "./jump.cpp"
#include <ncurses.h>
#define delay 10
#define height 30
#define dino_height 6

int main(int argc, char **argv) {
    SCREEN *screen = newterm(NULL, stdout, stdin);

    if (!screen) {
        fprintf(stderr, "Error initializing ncurses.\n");
        return 1;
    }

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    // Initializing Dinasaur
    Body dino(0, height - dino_height, 1, delay);

    // Animation logic goes here
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int tree1_x_position = max_x;
    while (1) {

        if (tree1_x_position <= 0) {
            tree1_x_position = max_x;
        } else {
            tree1_x_position--;
        };
        int ch = getch();

        if (ch == KEY_UP) {
            printw("\n^ Arrow Key Pressed!");
            dino.update_y_position(-10);
        } else if (ch == KEY_DOWN) {
            printw("\nv Arrow Key Pressed!");
        } else if (ch == KEY_LEFT) {
            printw("\n< Arrow Key Pressed!");
        } else if (ch == KEY_RIGHT) {
            printw("\n> Arrow Key Pressed!");
        } else if (ch == 'q') {
            break; // Exit the loop if 'q' is pressed
        } else {
            dino.update_y_position(0.0);
        }
        draw::ground(height);
        draw::dino(0, dino.get_y_position(), height);
        draw::tree(tree1_x_position, 5, height - 1);

        refresh();
        napms(delay);
    }
    endwin();
    delscreen(screen);

    return 0;
}
