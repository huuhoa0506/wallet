#include "user.h"

using namespace std;

class UserRepository {
public:
    User* findByUsername(string username);
};