#include "Console.h"
#include <iostream>
using namespace std;

Console::Console() = default;

Console::Console(Service &service) {
    this->service = service;
}

Console::~Console() = default;

int Console::login() {
    string u, p;
    user.set_name(u);
    user.set_password(p);
    cout << endl << "Utilizator: ";
    cin >> u;
    cout << "Parola:";
    cin >> p;
    return service.login(u, p);
}

void Console::logout() {
    service.logout(user.get_name(), user.get_password());
}

//void Console::add_order() {
//    char name_string[50];
//    int memory_kb, status = 0;
//    cout << "Name: ";
//    cin >> name_string;
//    char *name = name_string;
//    cout << "Memory (in KB): ";
//    cin >> memory_kb;
//    service.add_order(name, memory_kb, status);
//}
//
//void Console::remove_order() {
//    int position;
//    cout << "Delete application from position:";
//    cin >> position;
//    service.delete_application(position - 1);
//    cout << "Application deleted\n";
//}
//
//void Console::update_order() {
//    int position;
//    cout << "Update application from position:";
//    cin >> position;
//    char name_string[50];
//    int memory_kb, status;
//    cout << "Name: ";
//    cin >> name_string;
//    char *name = name_string;
//    cout << "Memory (in KB): ";
//    cin >> memory_kb;
//    cout << "Status (1=RAM or 2=swap): ";
//    cin >> status;
//    service.update_application(position - 1, name, memory_kb, status);
//    cout << "Application updated\n";
//}

void Console::show_foods() {
    vector<Food> foods = service.get_all_foods();
    for (int i = 0; i < foods.size(); i++)
        cout << i + 1 << ". " << foods[i] << endl;
}

void Console::show_shopping() {
    vector<Shopping> shopping = service.get_all_shopping();
    for (int i = 0; i < shopping.size(); i++)
        cout << i + 1 << ". " << shopping[i] << endl;
}

void Console::show_all() {
    vector<Food> foods = service.get_all_foods();
    vector<Shopping> shopping = service.get_all_shopping();
    int i = 0;
    for (const auto &food:foods)
        cout << ++i << ". " << food << endl;
    for (const auto &sh:shopping)
        cout << ++i << ". " << sh << endl;
}

void Console::run_console() {
    bool work = true;
    int rez = login();
    if (rez != -1) {
        while (work) {
            cout << "\n\n"
                 //                 << "1. Adaugare comanda\n"
                 //                 << "2. Stergere comanda\n"
                 //                 << "3. Actualizeaza comanda\n"
                 << "1. Afisati toate comenzile\n"
                 << "2. Afisati comenzile de tip mancare\n"
                 << "3. Afisati comenzile de tip shopping\n"
                 << "4. Iesire\n"
                 << "\nOptiune: ";
            int option;
            cin >> option;
            switch (option) {
                case 1: {
                    show_all();
                    break;
                }
                case 2: {
                    show_foods();
                    break;
                }
                case 3: {
                    show_shopping();
                    break;
                }
                case 4: {
                    logout();
                    work = false;
                }
            }
        }
    } else cout << "Autentificare esuata..." << endl;
}
