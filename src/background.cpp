#pragma once
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <string>

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
    Obstacles(int ox, int h, int w, int d)
        : Background(h, w, d), obstacle_x_coordinate(ox) {
        srand(time(0));
        obstacle_height = 5 + (rand() % 7);
        obstacle_width = 2 + (rand() % 7);
    }

    int get_x_coordinate() { return this->obstacle_x_coordinate; }
    int get_obstacle_height() { return this->obstacle_height; }
    int get_obstacle_width() { return this->obstacle_width; }
    void move_obstacle(int pace);
};
void Obstacles::move_obstacle(int pace) {
    // This method moves the obstacle to the left
    // and then draws it to the screen

    // Clearing the old tree before printing the new one

    std::string free = std::string(obstacle_width, ' ');
    const char *free_str = free.c_str();
    for (int i = 0; i < obstacle_height; i++) {
        mvprintw(height - i, obstacle_x_coordinate, "%s", free_str);
    };

    obstacle_x_coordinate = obstacle_x_coordinate - pace;
    std::string tree = std::string(obstacle_width, '#');
    const char *tree_str = tree.c_str();
    for (int i = 0; i < obstacle_height; i++) {
        mvprintw(height - i, obstacle_x_coordinate, "%s", tree_str);
    };
    move(0, 0);
}
