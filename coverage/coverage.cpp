#include <iostream>
#include <string>
#include <cassert>
#include "../AuronDB/AuronDB"

int main()
{
    auron::AuronDB *db = new auron::AuronDB;
    db->insert("key1", "abc");
    db->insert("key2", "def");
    db->insert("key3", "azx");
    bool res = db->backup("./backup.arn");
    assert(res);
    delete db;

    auron::AuronDB *db2 = new auron::AuronDB;
    bool res2 = db2->loadFromBackup("./backup.arn");
    assert(res2);
    std::string value;
    auron::Status op = db2->getValue("key2", value);
    assert(op.ok());
    std::cout << value << "\n";

    delete db2;

    return 0;
}
