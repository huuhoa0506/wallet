#include <iostream>
#include "auth.h"

using namespace std;

bool Auth::login (string username, string password) {
    User *user = userRepo->findByUsername(username);
    currentUser = user;
    return true;
};


void Auth::showCurrentUser() {
    cout <<"Username: " << currentUser->getUsername() << endl << "Fullname: " << currentUser->getFullname() << endl ;
};