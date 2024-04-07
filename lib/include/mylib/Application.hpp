/*#include <iostream>

#include <string>

#include <memory>

#include <mylib/Database.hpp>

class Application {

private:
    int Init();
public:
    Application();

    int webHelloWorld();

    virtual ~Application();

};*/

#include <iostream>
#include <memory>

#include <mylib/Database.hpp>
#include <mylib/WebPageInterface.hpp>

class Application {
public:
    static Application& getInstance() {
        static Application instance;
        return instance;
    }

    void Run();

    Application(const Application&) = delete;
    void operator=(const Application&) = delete;

    virtual ~Application();
private:
    Application();

    int Init();
    int Destructor();

private:
    std::unique_ptr<Database> m_db;
    std::unique_ptr<WebPageInterface> m_WpgIntf;
};