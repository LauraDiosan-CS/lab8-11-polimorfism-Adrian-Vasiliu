#include "Table.h"

Table::Table() {
    lines = columns = 0;
    matrix = nullptr;
}
Table::Table(int lines, int columns) {
    this->lines = lines, this->columns = columns;
    //matrix = new int
}
int Table::get_lines() {
    return lines;
}
int Table::get_columns() {
    return columns;
}
//int *Table::get_matrix() {
//    return matrix;
//}
