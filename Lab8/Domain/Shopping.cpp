#include "Shopping.h"

Shopping::Shopping() = default;

Shopping::Shopping(const string &client_name,
                   const string &client_address,
                   const vector<string> &shopping_list,
                   int price, const string &shop_name) {
    this->client_name = client_name;
    this->client_address = client_address;
    this->string_list = shopping_list;
    this->price = price;
    this->shop_name = shop_name;
}

Shopping::Shopping(const string &line, char delimiter) {
    vector<string> tokens = get_tokens(line, delimiter);
    client_name = tokens[0];
    client_address = tokens[1];
    string_list = get_tokens(tokens[2], '-');
    price = stoi(tokens[3]);
    shop_name = tokens[4];
}

string Shopping::get_shop_name() {
    return shop_name;
}

void Shopping::set_shop_name(const string &new_shop_name) {
    shop_name = new_shop_name;
}

Shopping &Shopping::operator=(const Shopping &shopping) {
    if (this == &shopping) return *this;
    client_name = shopping.client_name;
    client_address = shopping.client_address;
    string_list = shopping.string_list;
    price = shopping.price;
    shop_name = shopping.shop_name;
    return *this;
}

bool Shopping::operator==(const Shopping &shopping) {
    return (client_name == shopping.client_name and client_address == shopping.client_address
            and string_list == shopping.string_list and price == shopping.price and shop_name == shopping.shop_name);
}

ostream &operator<<(ostream &os, Shopping shopping) {
    string articles;
    for (const auto &article:shopping.get_string_list())
        articles += article + ',';
    os << "Nume client: " << shopping.get_client_name() << "; adresa: " << shopping.get_client_address()
       << ", cumparaturi: " << articles << " pret: " << shopping.get_price() << ", magazin: "
       << shopping.get_shop_name();
    return os;
}

string Shopping::string_delimiter(char delimiter) {
    string articles;
    for (int i = 0; i < string_list.size() - 1; i++)
        articles += string_list[i] + '-';
    articles += string_list.back();
    return client_name + delimiter + client_address + delimiter + articles + delimiter + to_string(price) + delimiter +
            shop_name;
}
