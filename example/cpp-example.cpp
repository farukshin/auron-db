#include <iostream>
#include "../AuronDB/AuronDB"

int main() {
    AuronDB db;
    db.insert("key1", "abc");
    db.insert("key2", "def");
    db.insert("key3", "azx");
    std::cout
        << "key1 = " << db.getValue("key1") << "\n"
        << "key2 = " << db.getValue("key2") << "\n"
        << "key3 = " << db.getValue("key3") << "\n"
        << "key5 = " << db.getValue("key5") << "\n"
        << "key 'key5' is exist: " << (db.isExists("key5") ? "yes" : "no") << "\n";

    return 0;
}
