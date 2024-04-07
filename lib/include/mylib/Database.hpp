#include <iostream>
#include <string>

class Database {
public:
    Database();
    Database(const Database&) = delete;
    Database(const Database&&) = delete;

    Database operator=(const Database&) = delete;
    Database operator=(const Database&&) = delete;

    virtual ~Database();
private:
    int Init();
    int Destructor();

    int CheckDataBase();

private:
    const std::string dbName = "DataBase.sqlite";

    struct Admin {
        int id;
        std::string Surname;
        std::string Name;
        std::string Email;
        std::string Mobile;
    };

    struct Interface {
        int id;
        std::string Name;
        std::string Subnet;
        std::string Netmask;
    };

    struct Subnet {
        int id;
        int id_Intf;
        std::string ip_addr;
        int id_device;
    };

    struct Device {
        int id;
        std::string Name;
        std::string Mac_addr;
        bool Permit;
        std::string Description;
    };
};