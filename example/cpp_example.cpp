#include <iostream>
#include <string>
#include <cassert>
#include "../AuronDB/AuronDB.h"

int main()
{
    auron::AuronDB db;
    std::string value;

    db.insert("key1", "abc");

    auron::Status s = db.getValue("key1", value);
    assert(s.ok() && value == "abc");

    s = db.getValue("key333", value);
    assert(!s.ok() && s.isNotFound());

    return 0;
}
