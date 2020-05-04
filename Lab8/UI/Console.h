#pragma once
#include "../Service/Service.h"
#include <string>
using namespace std;

class Console {
 private:
    Service service;
    User user;
    int login();
    void logout();
 public:
    Console();
    explicit Console(Service &);
    ~Console();
//    void add_order();
//    void remove_order();
//    void update_order();
    void show_foods();
    void show_shopping();
    void show_all();
    void run_console();
};
