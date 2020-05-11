#include "Tests/Tester.h"
#include "Domain/Food.h"
#include "Domain/Shopping.h"
#include "Domain/User.h"
#include "Repository/TemplateRepository.h"
#include "Repository/TemplateFileRepo.h"
#include "Service/Service.h"
#include "UI/Console.h"

int what_file() {
    while (true) {
        cout << endl
             << "Citeste datele din fisierele:\n"
             << "1. CSV\n"
             << "2. Txt\n"
             << "Optiunea: ";
        int option;
        cin >> option;
        if (option == 1 or option == 2)
            return option;
        else
            cout << "\nOptiune inexistenta! Reincercati!";
    }
}

int main() {
    Tester tester;
    cout << "Executare teste...\n";
    tester.test_all();
    cout << "Totul pare ok!\n";

    int option = what_file();
    if (option == 1) {
        TemplateRepository<User> *user_repo = new TemplateFileRepo<User>("users.csv", ',');
        ((TemplateFileRepo<User> *) user_repo)->read_file();
        TemplateRepository<Food> *food_repo = new TemplateFileRepo<Food>("foods.csv", ',');
        ((TemplateFileRepo<Food> *) food_repo)->read_file();
        TemplateRepository<Shopping> *shopping_repo = new TemplateFileRepo<Shopping>("shopping.csv",
                                                                                     ',');
        ((TemplateFileRepo<Shopping> *) shopping_repo)->read_file();

        Service service(user_repo, food_repo, shopping_repo);

        Console console(service);
        console.run_console();
    } else {
        TemplateRepository<User> *user_repo = new TemplateFileRepo<User>("users.txt", ' ');
        ((TemplateFileRepo<User> *) user_repo)->read_file();
        TemplateRepository<Food> *food_repo = new TemplateFileRepo<Food>("foods.txt", ' ');
        ((TemplateFileRepo<Food> *) food_repo)->read_file();
        TemplateRepository<Shopping> *shopping_repo = new TemplateFileRepo<Shopping>("shopping.txt",
                                                                                     ' ');
        ((TemplateFileRepo<Shopping> *) shopping_repo)->read_file();
        Service service(user_repo, food_repo, shopping_repo);
        Console console(service);
        console.run_console();
    }
    return 0;
}
