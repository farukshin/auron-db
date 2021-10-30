#ifndef AURONDB_HPP
#define AURONDB_HPP

#include <string>
#include <map>
//#include <filesystem>
#include <iostream>
#include <fstream>
#include "c_plus_plus_serializer.h"

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

    std::string getValue(std::string key) {
        return isExists(key) ? mp[key] : "";
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
