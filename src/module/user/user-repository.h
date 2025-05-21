#pragma once

#include <vector>
#include "user.h"

using namespace std;

class UserRepository {

unsigned int incrementing = 0;
static UserRepository* instance;
vector<User*> users;
UserRepository();
public:
    User* findByUsername(string username);
    bool save(User *user);
    unsigned int nextID();
    static UserRepository* getInstance();
    const vector<User*> getAll();
};