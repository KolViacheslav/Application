#include <mylib/Application.hpp>

#include <mylib/Log.hpp>

Application::Application() {
    LOG_INFO("Start Application");
}

Application::~Application() {
    LOG_INFO("End Application");
}