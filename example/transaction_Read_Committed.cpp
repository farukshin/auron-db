#include <iostream>
#include <string>
#include <cassert>
#include "../AuronDB/AuronDB.h"
#include "../AuronDB/Transaction.h"
#include "../AuronDB/TransactionDB.h"

int main()
{
    auron::TransactionDB *db = new auron::TransactionDB;
    std::string value;

    ///////////////////////////////////
    // Isolation Level - Read Committed
    ///////////////////////////////////
    auron::Transaction *tran1 = db->BeginTransaction(auron::IsolationLevel::ReadCommitted);
    assert(tran1);

    auron::Status s = tran1->getValue("key1", value);
    assert(!s.ok() && s.isNotFound());

    s = tran1->insert("key1", "value1");
    assert(s.ok());

    s = db->getValue("key1", value);
    assert(s.isNotFound());

    s = db->insert("key2", "value2");
    assert(s.ok());

    s = db->insert("key1", "val11"); // todo
    assert(!s.ok());

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
