#pragma once

#include <ctime>
#include <string>
#include "transaction.h"

using namespace std;


class User {
    unsigned int id;
    string username;
    string fullname;
    string password;
    double balance;
    time_t createdAt;
    int role;
public:
    static const int ROLE_ADMIN = 1;
    static const int ROLE_USER = 2;
    User(unsigned int id, string username, string fullname, string password, int role, double balance, time_t createdAt);
    unsigned int getId();
    string getUsername();
    string getFullname();
    string getPassword();
    time_t getCreatedAt();
    double getBalance();
    int getRole();
    void setPassword(string password);
    void setFullname(string fullname);
    void setBalance(double amount);
    bool addMoney(int money);
    bool subMoney(int money);

    static User* newUser(unsigned int id, string username, string fullname, string password);
    static User* newAdmin(unsigned int id, string username, string fullname, string password);

};