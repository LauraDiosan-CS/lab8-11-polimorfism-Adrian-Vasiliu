#include "OrderValidator.h"
using namespace std;

OrderValidator::OrderValidator() {
    no_errors = 0;
}

OrderValidator::~OrderValidator() = default;

int OrderValidator::validate(Order order) {
    no_errors = 0;
    if (order.get_string_list().empty()) {
        no_errors++;
        message += "\nLista trebuie sa contina minim un element!";
    }
    if (order.get_price() <= 0) {
        no_errors++;
        message += "\nPretul trebuie sa fie mai mare decat 0!";
    }
    return no_errors;
}

string OrderValidator::get_message() {
    return message;
}
