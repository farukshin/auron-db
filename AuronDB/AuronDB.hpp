#ifndef AURONDB_HPP
#define AURONDB_HPP

#include <string>
#include <map>

class AuronDB {
public:
    std::map<std::string, std::string> mp;

    void insert(std::string key, std::string value) {
        mp[key] = value;
    }

    bool isExists(std::string key) {
        return mp.count(key);
    }

    std::string getValue(std::string key) {
        return isExists(key) ? mp[key] : "";
    }
};

#endif
