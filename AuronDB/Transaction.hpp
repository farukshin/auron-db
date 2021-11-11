#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "AuronDB.h"

namespace auron
{

    class Transaction : public auron::AuronDB
    {
    public:
        Status Commit()
        {
            ;
        }
    };

} // namespace auron

#endif // TRANSACTION_HPP
