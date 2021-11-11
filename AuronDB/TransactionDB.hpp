#ifndef TRANSACTIONDB_HPP
#define TRANSACTIONDB_HPP

#include "AuronDB.h"
#include "Transaction.h"

namespace auron
{
    enum IsolationLevel
    {
        ReadUncommitted,
        ReadCommitted,
        RepeatableRead,
        Serializable
    };

    class TransactionDB : public auron::AuronDB
    {
    public:
        Transaction *BeginTransaction(auron::IsolationLevel lev)
        {
            ;
        }
    };

} // namespace auron

#endif // TRANSACTIONDB_HPP
