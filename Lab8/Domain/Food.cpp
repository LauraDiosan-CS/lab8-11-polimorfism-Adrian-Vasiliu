#include "Food.h"

Food::Food() = default;

Food::Food(const string &client_name,
           const string &client_address,
           const vector<string> &preparations_list,
           int price) {
    this->client_name = client_name;
    this->client_address = client_address;
    this->string_list = preparations_list;
    this->price = price;
}

Food::Food(const string &line, char delimiter) {
    vector<string> tokens = get_tokens(line, delimiter);
    client_name = tokens[0];
    client_address = tokens[1];
    string_list = get_tokens(tokens[2], '-');
    price = stoi(tokens[3]);
}

Food &Food::operator=(const Food &food) {
    if (this == &food) return *this;
    client_name = food.client_name;
    client_address = food.client_address;
    string_list = food.string_list;
    price = food.price;
    return *this;
}

bool Food::operator==(const Food &food) {
    return (client_name == food.client_name and client_address == food.client_address
            and string_list == food.string_list and price == food.price);
}

ostream &operator<<(ostream &os, Food food) {
    string preparations;
    for (const auto &preparation:food.get_string_list())
        preparations += preparation + ',';
    os << "Nume client: " << food.get_client_name() << "; adresa: " << food.get_client_address() << ", preparate: "
       << preparations << " pret: " << food.get_price();
    return os;
}

string Food::string_delimiter(char delimiter) {
    string preparations;
    for (int i = 0; i < string_list.size() - 1; i++)
        preparations += string_list[i] + '-';
    preparations += string_list.back();
    return client_name + delimiter + client_address + delimiter + preparations + delimiter + to_string(price);
}
