#include "Service.h"
#include "../Repository/TemplateFileRepo.h"
#include "../ValidationException.h"

Service::Service() {
    food_repo = nullptr;
    shopping_repo = nullptr;
    user_repo = nullptr;
}

Service::Service(TemplateRepository<User> *user_repo,
                 TemplateRepository<Food> *food_repo,
                 TemplateRepository<Shopping> *shopping_repo) {
    this->user_repo = user_repo;
    this->food_repo = food_repo;
    this->shopping_repo = shopping_repo;
}

Service::~Service() = default;

vector<Food> Service::get_all_foods() {
    return food_repo->get_all();
}

vector<Shopping> Service::get_all_shopping() {
    return shopping_repo->get_all();
}

bool Service::login(const User &user) {
    return user_repo->get_position(user) != -1;
}

void Service::add_user(const string &user_name, const string &password) {
    User user(user_name, password);
    user_repo->add(user);
    ((TemplateFileRepo<User> *) user_repo)->write_file();
}

void Service::add_food(const string &client_name, const string &client_address, const vector<string> &preparations_list,
                       int price) {
    Food food(client_name, client_address, preparations_list, price);
    if (order_validator.validate(food) == 0) {
        food_repo->add(food);
        ((TemplateFileRepo<Food> *) food_repo)->write_file();
    } else throw ValidationException(order_validator.get_message().c_str());
}

void Service::add_shopping(const string &client_name, const string &client_address,
                           const vector<string> &preparations_list, int price, const string &shop_name) {
    Shopping shopping(client_name, client_address, preparations_list, price, shop_name);
    if (order_validator.validate(shopping) == 0) {
        shopping_repo->add(shopping);
        ((TemplateFileRepo<Shopping> *) shopping_repo)->write_file();
    } else throw ValidationException(order_validator.get_message().c_str());
}

void Service::orders_by_client(const string &client_name, vector<Food> &foods, vector<Shopping> &shopping) {
    foods.clear(), shopping.clear();
    for (auto food:food_repo->get_all())
        if (food.get_client_name() == client_name)
            foods.push_back(food);
    for (auto sh:shopping_repo->get_all())
        if (sh.get_client_name() == client_name)
            shopping.push_back(sh);
}
