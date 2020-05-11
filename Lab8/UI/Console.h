#pragma once
#include "../Service/Service.h"
#include <string>
using namespace std;

class Console {
 private:
    Service service;
    User user;
    bool login();
    void logout();
    void add_user();
    void add_order();
    void add_food();
    void add_shopping();
//    void remove_order();
    static void show_foods(vector<Food>);
    static void show_shopping(vector<Shopping> shopping);
    static void show_orders(const vector<Food> &, const vector<Shopping> &shopping);
    void show_orders_by_client();
    void menu();
 public:
    Console();
    explicit Console(Service &);
    ~Console();
    void run_console();
};
