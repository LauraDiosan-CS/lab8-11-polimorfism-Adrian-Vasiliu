#pragma once
#include "Order.h"

class Shopping : public Order {
 private:
    string shop_name;
 public:
    Shopping();
    Shopping(const string &, const string &, const vector<string> &, int, const string &);
    Shopping(const string &, char);
    string get_shop_name();
    void set_shop_name(const string &);
    Shopping &operator=(const Shopping &);
    bool operator==(const Shopping &);
    friend ostream &operator<<(ostream &, Shopping);
    string string_delimiter(char delimiter);
};
