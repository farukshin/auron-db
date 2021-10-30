## Использование в C++

```
#include "../AuronDB/AuronDB"

AuronDB* db = new AuronDB;
db->insert("key1", "abc");
db->insert("key2", "def");
std::string value;
Status s = dbptr->getValue("key1", value);
if (s.ok())
    std::cout << value << "\n";

auto fl = db->backup("./backup.arn");
delete db;


// восстановление из бэкапа
AuronDB* db2 = new AuronDB;
auto fl2 = db2->loadFromBackup("./backup.arn");
s = dbptr->getValue("key2", value);
if (s.ok())
    std::cout << value << "\n";
delete db2;

```
