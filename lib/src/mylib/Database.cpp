#include <mylib/Database.hpp>
#include <mylib/Log.hpp>

#include <sqlite_orm/sqlite_orm.h>

using namespace sqlite_orm;



Database::Database() {
    this->Init();
}

int Database::Init() {
    static auto storage = make_storage(this->dbName,
        make_table("Administrator",
            make_column("id", &Admin::id, primary_key().autoincrement()),
            make_column("Surname", &Admin::Surname),
            make_column("Name", &Admin::Name),
            make_column("Email", &Admin::Email),
            make_column("Mobile", &Admin::Mobile)
        ),
        make_table("Interfaces",
            make_column("id", &Interface::id, primary_key().autoincrement()),
            make_column("Name", &Interface::Name),
            make_column("Subnet", &Interface::Subnet),
            make_column("Netmask", &Interface::Netmask)
        ),
        make_table("Subnets",
            make_column("id", &Subnet::id, primary_key().autoincrement()),
            make_column("id_Intf", &Subnet::id_Intf),
            make_column("Ip_addr", &Subnet::ip_addr),
            make_column("id_Device", &Subnet::id_device)
        ),
        make_table("Devices",
            make_column("id", &Device::id, primary_key().autoincrement()),
            make_column("Name", &Device::Name),
            make_column("MAC_addr", &Device::Mac_addr),
            make_column("Permit", &Device::Permit),
            make_column("Description", &Device::Description)
        )
    );

    storage.sync_schema(true);
    this->CheckDataBase();


    auto devices = storage.get_all<Device>();

    if(devices.empty()) {
        std::cout << "Device is empty\n";
    }
    else {
        for(auto device : devices) {
        std::cout << device.id << " " << device.Name << " " << device.Mac_addr << "\n";
        }
    }

    

    return 0;
}

Database::~Database() {
    this->Destructor();
}

int Database::Destructor() {
    return 0;
}

int Database::CheckDataBase() {
    

    return 0;
}