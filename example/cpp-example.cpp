#include <iostream>
#include <string>
#include "../AuronDB/AuronDB"

int main()
{
    auron::AuronDB db;
    db.insert("key1", "abc");

    std::string value;
    auron::Status s = db.getValue("key1", value);
    if (s.ok())
        std::cout << value << "\n";

    s = db.getValue("key333", value);
    if (s.ok())
        std::cout << value << "\n";
    else
        std::cout << "key 'key333' is not exists"
                  << "\n";

    return 0;
}
