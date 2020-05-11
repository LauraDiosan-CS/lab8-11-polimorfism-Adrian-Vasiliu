#pragma once
#include "Order.h"

class Food : public Order {
 public:
    Food();
    Food(const string &, const string &, const vector<string> &, int);
    Food(const string &, char);
    Food &operator=(const Food &);
    bool operator==(const Food &);
    friend ostream &operator<<(ostream &, Food);
    string string_delimiter(char);
};
