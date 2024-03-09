#include "./background.cpp"
#include "./draw.cpp"
#include "./jump.cpp"
#include <ncurses.h>
#define delay 25
#define height 30
#define dino_height 6
// All the functions that are to draw somthing should move the cursor back
// to the position (0,0)

int main(int argc, char **argv) {

    initscr();

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    WINDOW *win = newwin(height, max_x, 0, 0);

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    // Initializing Dinasaur
    Body dino(0, height - dino_height, 5, delay);

    // Initailizing the ground
    Background *bg = new Background(height, max_x - 1, delay);

    // Initailizing the Obstacle
    Obstacles *tree = new Obstacles(max_x, 5, 3, height, max_x, delay);

    // Animation logic goes here

    while (1) {

        // If the tree is to the extreme left of the screen
        // we will delete that tree and create a new one
        // for now ?
        if ((*tree).get_x_coordinate() <= 0) {
            delete tree;
            tree = new Obstacles(max_x - 3, 24, 3, height, max_x, delay);
        } // Drawing the ground

        // Getting user input to move our Dinasaur
        int ch = getch();
        if (ch == KEY_UP || ch == 'k' || ch == 'w') {
            dino.update_y_position(-50);
        } else if (ch == 'q') {
            break; // Exit the loop if 'q' is pressed
        } else {
            dino.update_y_position(0.0);
        }
        draw::dino(0, dino.get_y_position(), height);
        tree->move_obstacle(1);
        tree->show_detail();
        bg->draw_ground();

        refresh();
        wrefresh(win);
        napms(delay);
    }
    endwin();

    delete tree;

    return 0;
}
