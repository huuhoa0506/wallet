#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


class NotfoundException : public exception {
    string mes;
public:
    explicit NotfoundException(string mes): mes(mes) {}

    const char* what() const noexcept override {
        return mes.c_str();
    }
};