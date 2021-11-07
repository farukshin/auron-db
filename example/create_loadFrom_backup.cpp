#include <iostream>
#include <string>
#include "../AuronDB/AuronDB.h"

int main()
{
    auron::AuronDB *db = new auron::AuronDB;
    db->insert("key1", "abc");
    db->insert("key2", "def");
    db->insert("key3", "azx");
    auto fl = db->backup("./backup.arn");
    delete db;

    auron::AuronDB *db2 = new auron::AuronDB;
    auto fl2 = db2->loadFromBackup("./backup.arn");
    std::string value;
    auron::Status op = db2->getValue("key2", value);
    if (op.ok())
        std::cout << value << "\n";
    else
        std::cout << "error load from backup\n";
    delete db2;

    return 0;
}
