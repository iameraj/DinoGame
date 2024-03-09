#pragma once
#include <ncurses.h>

class Dino {
  private:
    const char *dino_str = "\t                __ \n"
                           "\t               / -)\n"
                           "\t      _.----._/ /  \n"
                           "\t     /         /   \n"
                           "\t  __/         |    \n"
                           "\t /____/|_|--|_|    \n";
    const char *void_str = "\t                   \n"
                           "\t                   \n"
                           "\t                   \n"
                           "\t                   \n"
                           "\t                   \n"
                           "\t                   \n";

    int dino_y_coordinate;
    int resting_y_coordinate;
    int dino_height = 6;
    int dino_width = 18;
    int mass;
    int delay;

    float g = 0.69;

    float dino_y_velocity = 0;

  public:
    Dino(int x, int m, int d) {
        resting_y_coordinate = x;
        dino_y_coordinate = x;
        mass = m;
        delay = d;
    }
    int get_y_coordinate();
    void move_dino(float force);
};

int Dino::get_y_coordinate() { return this->dino_y_coordinate; }
void Dino::move_dino(float force) {

    mvprintw(dino_y_coordinate - dino_height, 0, "%s", void_str);

    force = force + mass * g;

    float y_accleration = force / mass;
    dino_y_velocity = dino_y_velocity + y_accleration;

    dino_y_coordinate = dino_y_coordinate + dino_y_velocity * delay / 100;

    if (dino_y_coordinate >= resting_y_coordinate) {
        dino_y_coordinate = resting_y_coordinate;
        dino_y_velocity = 0;
    }
    mvprintw(dino_y_coordinate - dino_height, 0, "%s", dino_str);
}
