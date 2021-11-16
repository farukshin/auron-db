#include <iostream>
#include <string>
#include <cassert>
#include "../AuronDB/AuronDB.h"

int main()
{
    auron::AuronDB *db = new auron::AuronDB;
    db->insert("key1", "abc");
    db->insert("key2", "def");
    db->insert("key3", "azx");
    auron::Status s = db->backup("./backup.arn");
    delete db;

    auron::AuronDB *db2 = new auron::AuronDB;
    auto fl2 = db2->loadFromBackup("./backup.arn");
    std::string value;
    s = db2->getValue("key2", value);
    assert(s.ok() && value == "def");
    delete db2;

    return 0;
}
