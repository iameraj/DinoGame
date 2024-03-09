#pragma once
#include <ncurses.h>

class Background {
  protected:
    int height;
    int width;
    int delay;

  public:
    Background(int h, int w, int d) {
        height = h;
        width = w;
        delay = d;
    }
    void show_detail(int score) { mvprintw(0, 0, "Score : %d", score); }
    void draw_ground() {

        for (int i = 0; i < width; i++) {
            mvprintw(height, i, "~");
            mvprintw(height + 1, i, "-");
        }
        move(0, 0);
    }
};

class Obstacles : public Background {
  private:
    int obstacle_x_coordinate;
    int obstacle_height;
    int obstacle_width;

  public:
    Obstacles(int ox, int oh, int ow, int h, int w, int d)
        : Background(h, w, d), obstacle_x_coordinate(ox), obstacle_height(oh),
          obstacle_width(ow) {}

    int get_x_coordinate() { return this->obstacle_x_coordinate; }
    int get_obstacle_height() { return this->obstacle_height; }
    int get_obstacle_width() { return this->obstacle_width; }
    void move_obstacle(int pace);
};
void Obstacles::move_obstacle(int pace) {
    // This method moves the obstacle to the left
    // and then draws it to the screen

    // Clearing the old tree before printing the new one
    const char *free = "   ";
    for (int i = 0; i < obstacle_height; i++) {
        mvprintw(height - i, obstacle_x_coordinate, "%s", free);
    };

    obstacle_x_coordinate = obstacle_x_coordinate - pace;
    const char *tree = "###";
    for (int i = 0; i < obstacle_height; i++) {
        mvprintw(height - i, obstacle_x_coordinate, "%s", tree);
    };
    move(0, 0);
}
