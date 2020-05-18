#pragma once

class Plane {
 private:
    int head_line, head_column;
 public:
    Plane();
    Plane(int, int);
    int get_head_line();
    int get_head_column();
};
