#include "Plane.h"

Plane::Plane() {
    head_line = head_column = 0;
}
Plane::Plane(int head_line, int head_column) {
    this->head_line = head_line, this->head_column = head_column;
}
int Plane::get_head_line() {
    return head_line;
}
int Plane::get_head_column() {
    return head_column;
}
