#include <iostream>
#include <memory>
#include <string>
#include "../AuronDB/AuronDB.h"

int main()
{
    auto dbptr = std::make_unique<auron::AuronDB>();
    dbptr->insert("key1", "abc");
    dbptr->insert("key2", "def");

    std::string value;
    auron::Status s = dbptr->getValue("key1", value);
    if (s.ok())
        std::cout << value << "\n";

    return 0;
}
