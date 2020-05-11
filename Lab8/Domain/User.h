#pragma once
#include <iostream>
using namespace std;

class User {
 private:
    string name;
    string password;
 public:
    User();
    User(const string &, const string &);
    User(const string &, char);
    ~User();
    string get_name();
    string get_password();
    void set_name(const string &);
    void set_password(const string &);
    bool operator==(const User &u);
    friend ostream &operator<<(ostream &, User);
    string string_delimiter(char);
};
