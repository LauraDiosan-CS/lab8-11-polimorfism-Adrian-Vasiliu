#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Order {
 protected:
    string client_name;
    string client_address;
    vector<string> string_list;
    int price;
 public:
    Order();
    Order(const string &, const string &, const vector<string> &, int);
    Order(const Order &);
    ~Order();
    static vector<string> get_tokens(const string &, char);
    string get_client_name();
    string get_client_address();
    vector<string> get_string_list();
    int get_price();
    void set_client_name(const string &);
    void set_client_address(const string &);
    void set_string_list(const vector<string> &);
    void set_price(int);
};
