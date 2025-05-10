#include <vector>
#include "user.h"

using namespace std;

class UserRepository {

unsigned int incrementing = 0;

vector<User*> users;

public:
    UserRepository();
    User* findByUsername(string username);
    bool save(User *user);
    unsigned int nextID();
};