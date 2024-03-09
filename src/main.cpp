#include "./background.cpp"
#include "./dino.cpp"
#include <ncurses.h>
#define delay 12
#define mass 2
#define dino_height 6
// All the functions that are to draw somthing should move the cursor back
// to the position (0,0)

int main(int argc, char **argv) {

    initscr();

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int height = max_y - 10;
    WINDOW *win = newwin(height, max_x, 0, 0);

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    // Initializing Dinasaur
    Dino dino(height, mass, delay);

    // Initailizing the ground
    Background *bg = new Background(height, max_x - 1, delay);

    // Initailizing the Obstacle
    Obstacles *tree = new Obstacles(max_x, 7, 3, height, max_x, delay);

    // Animation logic goes here

    while (1) {

        // If the tree is to the extreme left of the screen
        // we will delete that tree and create a new one
        // for now ?
        if (tree->get_x_coordinate() < 0) {
            delete tree;
            tree = new Obstacles(max_x - 3, 7, 3, height, max_x, delay);
        } // Drawing the ground

        // Getting user input to move our Dinasaur
        int ch = getch();
        if (ch == KEY_UP || ch == 'k' || ch == 'w') {
            dino.move_dino(-25);
        } else if (ch == 'q') {
            break; // Exit the loop if 'q' is pressed
        } else {
            dino.move_dino(0.0);
        }
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
