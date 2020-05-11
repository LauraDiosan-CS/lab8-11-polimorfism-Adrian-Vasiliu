#pragma once
#include "Order.h"
#include <exception>
using namespace std;

class OrderValidator
{protected:
    int no_errors;
    string message;
 public:
    OrderValidator();
    ~OrderValidator();
    virtual int validate(Order);
    string get_message();
};
