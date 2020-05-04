#pragma once
#include "../Repository/TemplateRepository.h"
#include "../Domain/Food.h"
#include "../Domain/Shopping.h"
#include "../Domain/User.h"

class Service {
 private:
    TemplateRepository<User> *user_repo;
    TemplateRepository<Food> *food_repo;
    TemplateRepository<Shopping> *shopping_repo;
 public:
    Service();
    Service(TemplateRepository<User> *, TemplateRepository<Food> *, TemplateRepository<Shopping> *);
    bool login(const string &, const string &);
    void logout(const string &, const string &);
    vector<Food> get_all_foods();
    vector<Shopping> get_all_shopping();
    ~Service();
};
