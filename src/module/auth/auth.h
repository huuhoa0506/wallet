#include "user/user-repository.h"
#include <string>

using namespace std;

class Auth {
    UserRepository* userRepo;
    User* currentUser;
public:
    Auth(UserRepository* userRepo): userRepo(userRepo){};
    bool login(string username, string password);
    bool logout();
    bool registerAccount(string username, string fullname, string password);
    bool changePassword(string oldPassword, string newPassword);
    void showCurrentUser();
    bool verifyPassword(User *user, string password);
    bool isLoggedIn();
    User* getAuthUser();
    bool updateProfile(string fullname);
    bool isAdmin();
};

