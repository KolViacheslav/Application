
/*#include <mylib/Application.hpp>



#include <mylib/Log.hpp>

#include "sqlite_orm/sqlite_orm.h"

#include <fastcgi++/request.hpp>
#include <fastcgi++/manager.hpp>

using namespace sqlite_orm;

class HelloWorld: public Fastcgipp::Request<wchar_t>
{
    //! [Request definition]
    //! [Response definition]
    bool response()
    {
        //! [Response definition]
        //! [HTTP header]
        out << L"Content-Type: text/html; charset=utf-8\r\n\r\n";
        //! [HTTP header]

        //! [Output]
        out <<
L"<!DOCTYPE html>\n"
L"<html>"
    L"<head>"
        L"<meta charset='utf-8' />"
        L"<title>fastcgi++: Hello World</title>"
    L"</head>"
    L"<body>"
        L"<p>"
            L"English: Hello World<br>"
            L"Russian: Привет мир<br>"
            L"Greek: Γεια σας κόσμο<br>"
            L"Chinese: 世界您好<br>"
            L"Japanese: 今日は世界<br>"
            L"Runic English?: ᚺᛖᛚᛟ ᚹᛟᛉᛚᛞ<br>"
        L"</p>"
    L"</body>"
L"</html>";
        //! [Output]

        //! [Return]
        return true;
    }
};


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

int Application::webHelloWorld() {
    Fastcgipp::Manager<HelloWorld> manager;
    //! [Manager]
    //! [Signals]
    manager.setupSignals();
    //! [Signals]
    //! [Listen]
    manager.listen();
    //! [Listen]
    //! [Start]
    manager.start();
    //! [Start]
    //! [Join]
    manager.join();

    return 0;
}*/

#include <mylib/Application.hpp>
#include <mylib/Log.hpp>




void Application::Run() {
    LOG_INFO("Start Running Application.");

    this->m_WpgIntf->ShowPage();

    LOG_INFO("Ending Running Application.");
}

Application::Application() {
    LOG_INFO("Start Constructor Application.");
    this->Init();

    LOG_INFO("Ending Constructor Application.");
}

int Application::Init() {
    LOG_INFO("Start Initialization Application.");

    this->m_db = std::make_unique<Database>();
    this->m_WpgIntf = std::make_unique<WebPageInterface>();

    LOG_INFO("Ending Initialization Application.");
    return 0;
}

Application::~Application() {
    this->Destructor();
}

int Application::Destructor() {
    LOG_INFO("Start Destruction Application.");


    LOG_INFO("Ending Destruction Application.");
    return 0;
}