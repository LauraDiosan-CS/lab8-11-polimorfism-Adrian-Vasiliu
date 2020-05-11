#pragma once
#include "../Repository/TemplateRepository.h"
#include "../Domain/Food.h"
#include "../Domain/Shopping.h"
#include "../Domain/User.h"
#include "../Domain/OrderValidator.h"

class Service {
 private:
    TemplateRepository<User> *user_repo;
    TemplateRepository<Food> *food_repo;
    TemplateRepository<Shopping> *shopping_repo;
    OrderValidator order_validator;
 public:
    Service();
    Service(TemplateRepository<User> *, TemplateRepository<Food> *, TemplateRepository<Shopping> *);
    ~Service();
    vector<Food> get_all_foods();
    vector<Shopping> get_all_shopping();
    bool login(const User &);
    void add_user(const string &, const string &);
    void add_food(const string &, const string &, const vector<string> &, int);
    void add_shopping(const string &, const string &, const vector<string> &, int, const string &);
    void orders_by_client(const string& client_name, vector<Food> &, vector<Shopping> &shopping);
};
