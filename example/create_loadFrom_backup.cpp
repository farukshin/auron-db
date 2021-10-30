#include <iostream>
#include <string>
#include "../AuronDB/AuronDB"

int main() {
    AuronDB* db = new AuronDB;
    db->insert("key1", "abc");
    db->insert("key2", "def");
    db->insert("key3", "azx");
    auto fl = db->backup("./backup.arn");
    delete db;

    AuronDB* db2 = new AuronDB;
    auto fl2 = db2->loadFromBackup("./backup.arn");
    std::string value;
    Status op = db2->getValue("key2", value);
    if (op.ok())
        std::cout << value << "\n";
    else
        std::cout << "error load from backup\n";
    delete db2;

    return 0;
}
