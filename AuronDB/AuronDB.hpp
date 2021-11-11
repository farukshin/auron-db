#ifndef AURONDB_HPP
#define AURONDB_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "c_plus_plus_serializer.h"

namespace auron
{
    class Status
    {
    private:
        bool okey = false;
        long long bit = 0;

        void set_bit(long long &num, unsigned int pos)
        {
            num |= 1 << pos;
        }

        enum StatusParam
        {
            NotFound = 1
        };

    public:
        Status(bool _ok)
        {
            okey = _ok;
        };
        ~Status(){};

        bool ok()
        {
            return okey;
        }

        bool isNotFound()
        {
            return bit & (1LL << StatusParam::NotFound);
        }

        void setIsNotFound()
        {
            set_bit(bit, StatusParam::NotFound);
        }
    };

    class AuronDB
    {
    private:
        std::map<std::string, std::string> mp;

    public:
        AuronDB() {}
        ~AuronDB() {}

        Status open(std::string path)
        {
            ;
        }

        Status insert(std::string key, std::string value)
        {
            mp[key] = value;
            Status status(true);
            return status;
        }

        bool isExists(std::string key)
        {
            return mp.count(key);
        }

        Status getValue(std::string key, std::string &value)
        {
            if (isExists(key))
            {
                value = mp[key];
                Status status(true);
                return status;
            }
            else
            {
                Status status(false);
                return status;
            }
        }

        bool backup(std::string file)
        {
            std::ofstream out(file, std::ios::binary | std::ios::out);
            out << bits(mp);
            return true;
        }

        bool loadFromBackup(std::string file)
        {
            std::ifstream in(file, std::ios::binary | std::ios::in);
            mp.clear();
            in >> bits(mp);
            return true;
        }
    };

} // namespace auron

#endif // AURONDB_HPP
