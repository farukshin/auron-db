#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

namespace auron
{
    enum IsolationLevel
    {
        ReadUncommitted,
        ReadCommitted,
        RepeatableRead,
        Serializable
    };

    class Transaction
    {
    };

} // namespace auron

#endif // TRANSACTION_HPP
