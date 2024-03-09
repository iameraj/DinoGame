
class Body {
  private:
    float g = 0.981;
    int mass;
    int x_position;
    int y_position;
    int delay;

    int resting_y_position;
    int resting_x_position;

    float y_velocity = 0;
    float x_velocity = 0;

  public:
    Body(int resting_x, int resting_y, int m, int d) {

        x_position = resting_x_position;
        y_position = resting_y_position;

        resting_y_position = resting_y;
        resting_x_position = resting_x;
        delay = d;
        mass = m;
    }

    void update_y_position(float y_force) {

        y_force = y_force + mass * g;

        float y_accleration = y_force / mass;
        y_velocity = y_velocity + y_accleration;

        y_position = y_position + y_velocity * delay / 100;

        if (y_position >= resting_y_position) {
            y_position = resting_y_position;
            y_velocity = 0;
        };
    }
    int get_y_position() { return int(y_position); }
};
