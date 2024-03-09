#pragma once
#include <ncurses.h>

class Game {
  private:
    int score = 0;
    int height;

  public:
    Game(int h) { height = h; }
    bool is_alive(int dino_y_pos, int obstacle_x_pos, int obstacle_height) {
        if ((obstacle_x_pos < 28) && (obstacle_x_pos > 14)) {
            if ((dino_y_pos + obstacle_height) >= this->height) {
                return 0;
            }
        }
        return 1;
    }
    int get_score() { return this->score; }
    void set_score(int score) { this->score = score; }
};
