#include "OrderValidator.h"
#include <cstring>
using namespace std;

OrderValidator::OrderValidator() {
    no_errors = 0;
}

OrderValidator::~OrderValidator() = default;

int OrderValidator::validate(Order order) {
    message = "";
    no_errors = 0;
    if (order.get_price() <= 0) {
        no_errors++;
        message += "Pretul trebuie sa fie mai mare decat 0!";
    }
    return no_errors;
}

string OrderValidator::get_message() {
    return message;
}
