#include <mylib/WebPageInterface.hpp>
#include <mylib/Log.hpp>

#include <fastcgi++/request.hpp>
#include <fastcgi++/manager.hpp>

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

WebPageInterface::WebPageInterface() {
    this->Init();
}

int WebPageInterface::Init() {
    return 0;
}

WebPageInterface::~WebPageInterface() {
    this->Destructor();
}

int WebPageInterface::Destructor() {
    return 0;
}

int WebPageInterface::ShowPage() {
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
}