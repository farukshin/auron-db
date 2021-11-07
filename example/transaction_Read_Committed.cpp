#include <iostream>
#include <string>
#include <cassert>
#include "../AuronDB/AuronDB.h"
#include "../AuronDB/Transaction.h"

int main()
{
    auron::AuronDB *db = new auron::AuronDB;
    std::string value;

    ///////////////////////////////////
    // Isolation Level - Read Committed
    ///////////////////////////////////
    auron::Transaction *tran1 = db->BeginTransaction();
    assert(tran1);

    auron::Status status = tran1->getValue("key1", value);
    assert(status.isNotFound());

    s = tran1->insert("key1", "value1");
    assert(s.ok());

    s = db->getValue("key1", value);
    assert(s.IsNotFound());

    s = db->insert("key2", "value2");
    assert(s.ok());

    s = db->insert("key1", "val11"); // todo

    s = tran1->getValue("key2", value);
    assert(s.ok());
    assert(value == "value2");

    s = tran1->Commit();
    assert(s.ok());
    delete tran1;

    s = db->getValue("key1", value);
    assert(s.ok());
    assert(value == "value1");

    return 0;
}
