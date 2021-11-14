#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "AuronDB.h"
#include "TransactionDB.h"

namespace auron
{

    class Transaction : public auron::AuronDB
    {
    private:
        std::vector<std::pair<auron::LockType, std::string>> t_locks;
        std::map<std::string, std::string> new_vals;
        auron::TransactionDB *db;
        auron::IsolationLevel isoLevel;
        long long id;

    public:
        Transaction(long long _id, auron::IsolationLevel _l, auron::TransactionDB *_db)
        {
            id = _id;
            isoLevel = _l;
            db = _db;
        }
        ~Transaction() {}

        std::vector<std::pair<auron::LockType, std::string>> getLocks()
        {
            return t_locks;
        }

        std::map<std::string, std::string> getNewVals()
        {
            return new_vals;
        }

        Status Commit()
        {
            Status s = db->commitTransaction(this);
            return s;
        }

        void Rollback()
        {
            db->rollbackTransaction(this);
        }

        Status getValue(std::string key, std::string &value)
        {
            Status s = db->setSLock(key, this);
            s = db->getValue(key, value);
            db->unsetSLock(key, this);

            return s;
        }

        Status insert(std::string key, std::string value)
        {
            Status s = db->setXLock(key, this);
            s = db->insert(key, value);
            return s;
        }
    };

} // namespace auron

#endif // TRANSACTION_HPP
