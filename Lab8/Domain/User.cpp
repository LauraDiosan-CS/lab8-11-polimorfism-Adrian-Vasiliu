#include "User.h"
#include <vector>
#include <sstream>
User::User() = default;

User::User(const string &name, const string &password) {
    this->name = name, this->password = password;
}

User::User(const string &line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, delimiter))
        tokens.push_back(token);
    name = tokens[0];
    password = tokens[1];
}

User::~User() = default;

string User::get_name() {
    return name;
}

string User::get_password() {
    return password;
}

void User::set_name(const string &new_name) {
    this->name = new_name;
}

void User::set_password(const string &new_password) {
    password = new_password;
}

bool User::operator==(const User &user) {
    return (name == user.name and password == user.password);
}

ostream &operator<<(ostream &os, User user) {
    os << "Nume utilizator: " << user.get_name() << ", parola: " << user.get_password() << endl;
    return os;
}

string User::string_delimiter(char delimiter) {
    return name + delimiter + password;
}
