#include "Order.h"
#include <sstream>
using namespace std;

Order::Order() {
    price = 0;
}

Order::Order(const string &client_name, const string &client_address, const vector<string> &string_list, int price) {
    this->client_name = client_name;
    this->client_address = client_address;
    this->string_list = string_list;
    this->price = price;
}

Order::Order(const Order &order) {
    client_name = order.client_name;
    client_address = order.client_address;
    string_list = order.string_list;
    price = order.price;
}

Order::~Order() {
    client_name = client_address = "";
    string_list.clear();
    price = -1;
}

vector<string> Order::get_tokens(const string &line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

string Order::get_client_name() {
    return client_name;
}

string Order::get_client_address() {
    return client_address;
}

vector<string> Order::get_string_list() {
    return string_list;
}

int Order::get_price() {
    return price;
}

void Order::set_client_name(const string &new_client_name) {
    client_name = new_client_name;

}

void Order::set_client_address(const string &new_client_address) {
    client_address = new_client_address;
}

void Order::set_string_list(const vector<string> &new_string_list) {
    string_list = new_string_list;
}

void Order::set_price(int new_price) {
    price = new_price;
}
