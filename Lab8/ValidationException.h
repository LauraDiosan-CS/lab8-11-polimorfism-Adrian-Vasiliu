#pragma once
#include <exception>
#include <cstring>
using namespace std;

class ValidationException : public exception {
 private:
    char *message;
 public:
    explicit ValidationException(const char *m) {
        message = new char[strlen(m) + 1];
        strcpy(message, m);
    }

    ~ValidationException() { if (message) delete[] message; }
    virtual const char *get_message() const throw() { return message; }
};
