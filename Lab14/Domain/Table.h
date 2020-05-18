#pragma once

class Table {
 private:
    int lines, columns;
    int *matrix;
 public:
    Table();
    Table(int, int);
    int get_lines();
    int get_columns();
    int get_matrix();
};
