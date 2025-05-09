#include <iostream>
#include "auth.h"

using namespace std;

bool Auth::login (string username, string password) {
    User *user = userRepo->findByUsername(username);

    if(verifyPassword(user, password)) {
        currentUser = user;
        return true;
    }
    return false;
};


void Auth::showCurrentUser() {
    cout <<"Username: " << currentUser->getUsername() << endl << "Fullname: " << currentUser->getFullname() << endl ;
};


bool Auth::verifyPassword(User *user, string password) {
    return user->getPassword() == password;
}