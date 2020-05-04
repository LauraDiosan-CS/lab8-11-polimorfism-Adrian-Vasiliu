#include "Service.h"

Service::Service() {
    food_repo = nullptr;
    shopping_repo = nullptr;
    user_repo = nullptr;
};

Service::Service(TemplateRepository<User> *user_repo,
                 TemplateRepository<Food> *food_repo,
                 TemplateRepository<Shopping> *shopping_repo) {
    this->user_repo = user_repo;
    this->food_repo = food_repo;
    this->shopping_repo = shopping_repo;
}

Service::~Service() = default;

bool Service::login(const string &user_name, const string &user_password) {
    User user(user_name, user_password);
    return user_repo->get_position(user) != -1;
}

void Service::logout(const string &user_name, const string &user_password) {
    User user(user_name, user_password);
    user_repo->remove(user);
}

vector<Food> Service::get_all_foods() {
    return food_repo->get_all();
}

vector<Shopping> Service::get_all_shopping() {
    return shopping_repo->get_all();
}

