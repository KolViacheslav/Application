#include <mylib/Application.hpp>

// sudo apt-get install libsqlite3-dev

int main(int argc, char** argv) {
    Application& app = Application::getInstance();

    app.Run();
    
    return 0;
}