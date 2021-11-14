#ifndef TRANSACTIONDB_HPP
#define TRANSACTIONDB_HPP

#include "AuronDB.h"
#include "string"
#include "map"
//#include "list"
#include "set"
#include "climits"
#include "Transaction.h"

namespace auron
{
    class TransactionDB : public auron::AuronDB
    {
    private:
        std::map<std::string, std::map<auron::LockType, std::set<auron::Transaction *>>> locks;
        std::set<auron::Transaction *> transactions;
        long long tranID = 0;

        long long getNextTranID()
        {
            return tranID == LLONG_MAX ? 0 : ++tranID;
        }

    public:
        Transaction *BeginTransaction(auron::IsolationLevel lev)
        {
            Transaction *tr = new Transaction(getNextTranID(), lev, this);
            transactions.insert(tr);
            return tr;
        }

        void clearLocksOfTransaction(Transaction *tran)
        {
            for (auto _lock : tran->getLocks())
            {
                auto _type = _lock.first;
                auto _key = _lock.second;
                if (!locks.count(_key) || !locks[_key].count(_type))
                    continue;
                locks[_key][_type].erase(tran);
            }
        }

        Status updNewVal(Transaction *tran)
        {
            for (auto _d : tran->getNewVals())
            {
                auto _key = _d.first;
                auto _val = _d.second;
                setKV(_key, _val);
            };

            Status s(true);
            return s;
        }

        Status commitTransaction(Transaction *tran)
        {
            Status s = updNewVal(tran);
            clearLocksOfTransaction(tran);
            transactions.erase(tran);

            return s;
        }

        void rollbackTransaction(Transaction *tran)
        {
            clearLocksOfTransaction(tran);
            transactions.erase(tran);
        }

        Status setXLock(std::string key, auron::Transaction *tran)
        {
            ;
        }

        Status setSLock(std::string key, auron::Transaction *tran)
        {
            ;
        }
        Status unsetSLock(std::string key, auron::Transaction *tran)
        {
            ;
        }
    };

} // namespace auron

#endif // TRANSACTIONDB_HPP
