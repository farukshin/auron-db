#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include "../AuronDB/AuronDB.h"

int main()
{
    auto dbptr = std::make_unique<auron::AuronDB>();
    dbptr->insert("key1", "abc");
    dbptr->insert("key2", "def");

    std::string value;
    auron::Status s = dbptr->getValue("key1", value);
    assert(s.ok() && value == "abc");

    return 0;
}
