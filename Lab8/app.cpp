#include "Tests/Tester.h"
#include "Domain/Food.h"
#include "Domain/Shopping.h"
#include "Domain/User.h"
#include "Repository/TemplateRepository.h"
#include "Repository/TemplateFileRepo.h"
#include "Service/Service.h"
#include "UI/Console.h"

int main() {
    Tester tester;
    cout << "\nExecutare teste...\n";
    tester.test_all();
    cout << "Totul pare ok!\n";
    //auto *user_repo = new TemplateRepository<User>();
    TemplateRepository<User> *user_repo = new TemplateFileRepo<User>("users.txt", ' ');
    ((TemplateFileRepo<User> *) user_repo)->read_file();
    TemplateRepository<Food> *food_repo = new TemplateFileRepo<Food>("foods.txt", ' ');
    ((TemplateFileRepo<Food> *) food_repo)->read_file();
    TemplateRepository<Shopping> *shopping_repo = new TemplateFileRepo<Shopping>("shopping.txt", ' ');
    ((TemplateFileRepo<Shopping> *) shopping_repo)->read_file();

    Service service(user_repo, food_repo, shopping_repo);
    Console console(service);
    console.run_console();

    return 0;
}
