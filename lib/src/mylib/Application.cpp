#include <mylib/Application.hpp>

#include <mylib/Log.hpp>
#include "sqlite3.h"
#include "sqlite_orm/sqlite_orm.h"

using namespace sqlite_orm;

Application::Application() {
    LOG_INFO("Start Application");
    this->Init();
}

Application::~Application() {
    LOG_INFO("End Application");
}

struct User {
  int id;
  std::string name;
};

int Application::Init() {
    // Створення сховища даних
    auto storage = make_storage("test.sqlite",
                                make_table("users",
                                            make_column("id", &User::id, primary_key()),
                                            make_column("name", &User::name)));
    // Створення таблиці "users"
    storage.sync_schema();

    // Створення користувача
    User user{1, "John Doe"};

    // Збереження користувача
    storage.replace(user);

    // Отримання користувача
    auto users = storage.get_all<User>();

    // Перевірка, чи є користувач
    if (users.empty()) {
        std::cout << "Користувач не знайдений" << std::endl;
    } else {
        std::cout << "Користувач знайдений: " << users[0].name << std::endl;
    }

    return 0;
}