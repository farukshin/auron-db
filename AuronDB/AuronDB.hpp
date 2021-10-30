#ifndef AURONDB_HPP
#define AURONDB_HPP

#include <string>
#include <map>
//#include <filesystem>
#include <iostream>
#include <fstream>
#include "c_plus_plus_serializer.h"

class Status {
private:
    bool okey = false;

public:
    Status(bool _ok) { okey = _ok; };
    ~Status() {};

    bool ok() {
        return okey;
    }
};

class AuronDB {
private:
    std::map<std::string, std::string> mp;

public:
    AuronDB() {}
    ~AuronDB() {}

    void insert(std::string key, std::string value) {
        mp[key] = value;
    }

    bool isExists(std::string key) {
        return mp.count(key);
    }

    Status getValue(std::string key, std::string& value) {
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

    bool backup(std::string file) {
        std::ofstream out(file, std::ios::binary | std::ios::out);
        out << bits(mp);
        return true;
    }

    bool loadFromBackup(std::string file) {
        std::ifstream in(file, std::ios::binary | std::ios::in);
        mp.clear();
        in >> bits(mp);
        return true;
    }
};

#endif
