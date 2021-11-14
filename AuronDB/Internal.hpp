#ifndef INTERNAL_HPP
#define INTERNAL_HPP

namespace auron
{
    enum IsolationLevel
    {
        ReadUncommitted,
        ReadCommitted,
        RepeatableRead,
        Serializable
    };

    enum LockType
    {
        S,
        X
    };

} // namespace auron

#endif // INTERNAL_HPP
