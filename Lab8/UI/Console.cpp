#include "Console.h"
#include "../ValidationException.h"
#include <iostream>
using namespace std;

Console::Console() = default;

Console::Console(Service &service) {
    this->service = service;
}

Console::~Console() = default;

bool Console::login() {
    string user_name, password;
    cout << "\nUtilizator: ";
    cin >> user_name;
    cout << "Parola: ";
    cin >> password;
    user.set_name(user_name);
    user.set_password(password);
    return service.login(user);
}

void Console::logout() {
    user.set_name(""), user.set_password("");
}

void Console::add_user() {
    string user_name, password;
    cout << "\nNume utilizator: ";
    cin >> user_name;
    cout << "Parola: ";
    cin >> password;
    service.add_user(user_name, password);
    cout << "Cont creat\n";
}

void Console::add_order() {
    cout << endl
         << "Tipul comenzii:\n"
         << "1. Food\n"
         << "2. Shopping\n"
         << "Optiunea: ";
    int option;
    cin >> option;
    switch (option) {
        case 1: {
            add_food();
            break;
        }
        case 2: {
            add_shopping();
            break;
        }
        default: cout << "\nOptiune inexistenta! Reincercati!";
    }
}

void Console::add_food() {
    string client_name, client_address, s;
    vector<string> preparations_list;
    int n, price;
    cout << "\nNume client: ";
    cin >> client_name;
    cout << "Adresa client(fara spatii): ";
    cin >> client_address;
    cout << "Numarul de preparate: ";
    cin >> n;
    while (n == 0) {
        cout << "Lista trebuie sa contina minim un element!\n"
             << "Numarul de preparate: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++) {
        cout << "Preparat " << i + 1 << ": ";
        cin >> s;
        preparations_list.push_back(s);
    }
    cout << "Pret total: ";
    cin >> price;
    try {
        service.add_food(client_name, client_address, preparations_list, price);
        cout << "Comanda adaugata";
    }
    catch (ValidationException &exception) {
        cout << exception.get_message();
    }
}

void Console::add_shopping() {
    string client_name, client_address, s, shop_name;
    vector<string> shopping_list;
    int n, price;
    cout << "\nNume client: ";
    cin >> client_name;
    cout << "Adresa client(fara spatii): ";
    cin >> client_address;
    cout << "Numarul de cumparaturi: ";
    cin >> n;
    while (n == 0) {
        cout << "Lista trebuie sa contina minim un element!\n"
             << "Numarul de preparate: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++) {
        cout << "Obiect " << i + 1 << ": ";
        cin >> s;
        shopping_list.push_back(s);
    }
    cout << "Pret total: ";
    cin >> price;
    cout << "Nume magazin: ";
    cin >> shop_name;
    try {
        service.add_shopping(client_name, client_address, shopping_list, price, shop_name);
        cout << "Comanda adaugata";
    }
    catch (ValidationException &exception) {
        cout << exception.get_message();
    }
}

//void Console::remove_order() {
//    int position;
//    cout << "Delete application from position:";
//    cin >> position;
//    service.delete_application(position - 1);
//    cout << "Application deleted\n";
//}

void Console::show_foods(vector<Food> foods) {
    for (int i = 0; i < foods.size(); i++)
        cout << endl << i + 1 << ". " << foods[i];
}

void Console::show_shopping(vector<Shopping> shopping) {
    for (int i = 0; i < shopping.size(); i++)
        cout << endl << i + 1 << ". " << shopping[i];
}

void Console::show_orders(const vector<Food> &foods, const vector<Shopping> &shopping) {
    int i = 0;
    for (const auto &food:foods)
        cout << endl << ++i << ". " << food;
    for (const auto &sh:shopping)
        cout << endl << ++i << ". " << sh;
}

void Console::show_orders_by_client() {
    string client_name;
    cout << "Client: ";
    cin >> client_name;
    vector<Food> foods;
    vector<Shopping> shopping;
    service.orders_by_client(client_name, foods, shopping);
    show_orders(foods, shopping);
}

void Console::menu() {
    bool work = true;
    while (work) {
        cout << "\n\n"
             << "1. Adaugare comanda\n"
             //             << "2. Stergere comanda\n"
             << "2. Cautare dupa client\n"
             << "3. Afisati toate comenzile\n"
             << "4. Afisati comenzile de tip mancare\n"
             << "5. Afisati comenzile de tip shopping\n"
             << "6. Log-out\n"
             << "Optiunea: ";
        int option;
        cin >> option;
        switch (option) {
            case 1: {
                add_order();
                break;
            }
            case 2: {
                show_orders_by_client();
                break;
            }
            case 3: {
                vector<Food> foods = service.get_all_foods();
                vector<Shopping> shopping = service.get_all_shopping();
                show_orders(foods, shopping);
                break;
            }
            case 4: {
                vector<Food> foods = service.get_all_foods();
                show_foods(foods);
                break;
            }
            case 5: {
                vector<Shopping> shopping = service.get_all_shopping();
                show_shopping(shopping);
                break;
            }
            case 6: {
                logout();
                work = false;
                break;
            }
            default: cout << "\nOptiune inexistenta! Reincercati!";
        }
    }
}

void Console::run_console() {
    bool work = true;
    while (work) {
        cout << "\n"
             << "1. Log-in\n"
             << "2. Creare cont\n"
             << "3. Iesire\n"
             << "Optiunea: ";
        int option;
        cin >> option;
        switch (option) {
            case 1: {
                if (login()) {
                    cout << "Logare reusita";
                    menu();
                } else {
                    cout << "Utilizator sau parola gresita! Reincercati!\n";
                    break;
                }
                break;
            }
            case 2: {
                add_user();
                break;
            }
            case 3: {
                work = false;
                break;
            }
            default: cout << "\nOptiune inexistenta! Reincercati!";
        }
    }
}
