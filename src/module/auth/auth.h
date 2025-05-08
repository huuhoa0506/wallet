#include "user/user-repository.h"
#include <string>

using namespace std;

class Auth {
    UserRepository* userRepo;
    User* currentUser;
public:
    Auth(UserRepository* userRepo): userRepo(userRepo){};
    bool login(string username, string password);
    void showCurrentUser();
};

