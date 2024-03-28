#include <mylib/Application.hpp>

// sudo apt-get install libsqlite3-dev

int main(int argc, char** argv) {

    auto app = std::make_unique<Application>();

    app->webHelloWorld();

    std::cin.get();

    return 0;
}