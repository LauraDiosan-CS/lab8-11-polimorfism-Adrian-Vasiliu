#include "Tester.h"
#include "../Domain/Order.h"
#include "../Domain/Food.h"
#include "../Domain/Shopping.h"
#include "../Domain/User.h"
#include "../Repository/TemplateRepository.h"
#include "../Service/Service.h"
#include "../UI/Console.h"
#include <cassert>

void Tester::test_Food() {
    vector<string> preparation_list;
    Food food("", "", preparation_list, 0);
    assert(food.get_client_name().empty());
    assert(food.get_client_address().empty());
    assert(food.get_string_list().empty());
    assert(food.get_price() == 0);

    preparation_list.emplace_back("preparation1");
    preparation_list.emplace_back("preparation2");
    Food food1("Client1", "address1", preparation_list, 5);
    assert(food1.get_client_name() == "Client1");
    assert(food1.get_client_address() == "address1");
    assert(food1.get_string_list() == preparation_list);
    assert(food1.get_price() == 5);

    Food food2("Client2,address2,preparation1-preparation2,15", ',');
    assert(food2.get_client_name() == "Client2");
    assert(food2.get_client_address() == "address2");
    assert(food2.get_string_list() == preparation_list);
    assert(food2.get_price() == 15);
}

void Tester::test_Shopping() {
    vector<string> preparation_list;

    Shopping shopping("", "", preparation_list, 0, "");
    assert(shopping.get_client_name().empty());
    assert(shopping.get_client_address().empty());
    assert(shopping.get_string_list().empty());
    assert(shopping.get_price() == 0);

    preparation_list.emplace_back("preparation1");
    preparation_list.emplace_back("preparation2");

    Shopping shopping1("Client1", "address1", preparation_list, 5, "Shop1");
    assert(shopping1.get_client_name() == "Client1");
    assert(shopping1.get_client_address() == "address1");
    assert(shopping1.get_string_list() == preparation_list);
    assert(shopping1.get_price() == 5);
    assert(shopping1.get_shop_name() == "Shop1");

    Shopping shopping2("Client2,address2,preparation1-preparation2,15,Shop2", ',');
    assert(shopping2.get_client_name() == "Client2");
    assert(shopping2.get_client_address() == "address2");
    assert(shopping2.get_string_list() == preparation_list);
    assert(shopping2.get_price() == 15);
    assert(shopping2.get_shop_name() == "Shop2");
}

void Tester::test_User() {
    User user("", "");
    assert(user.get_name().empty());
    assert(user.get_password().empty());

    User user1("User1", "password1");
    assert(user1.get_name() == "User1");
    assert(user1.get_password() == "password1");

    User user2("User2,password2", ',');
    assert(user2.get_name() == "User2");
    assert(user2.get_password() == "password2");
}

void Tester::test_TemplateRepository() {
    auto *food_repo = new TemplateRepository<Food>();
    vector<string> preparation_list;
    preparation_list.emplace_back("preparation1");
    preparation_list.emplace_back("preparation2");

    Food food1("Client1", "address1", preparation_list, 5);
    food_repo->add(food1);
    int position = food_repo->get_position(food1);
    assert(position == 0);
    Food food = food_repo->get_item(0);
    assert(food.get_client_name() == "Client1");
    assert(food.get_client_address() == "address1");
    assert(food.get_string_list() == preparation_list);
    assert(food.get_price() == 5);

    assert(food_repo->get_size() == 1);
    food_repo->remove(food1);
    assert(food_repo->get_size() == 0);
}

void Tester::test_all() {
    test_Food();
    test_Shopping();
    test_User();
    test_TemplateRepository();
}
