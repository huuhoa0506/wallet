#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <random>
#include <sstream>

namespace utils {
    void InputRegister(string& username, string& fullname, string& password);
    void InputLogin(string& username, string& password);
    string md5(const string& input);


    string date_time(time_t timestamp);
}


namespace uuid {
    string generate_uuid_v4();
}

#endif


