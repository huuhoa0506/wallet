#include <iostream>
#include "common/notfound-exception.h"
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

bool Auth::registerAccount(string username, string fullname, string password) {

    try
    {
        userRepo->findByUsername(username);
        return false;
    }
    catch(const NotfoundException& e)
    {
        unsigned int id = userRepo->nextID();
        User *newUser = new User(id, username, fullname, password);

        userRepo->save(newUser);
        currentUser = newUser;
        return true;
    }
};


void Auth::showCurrentUser() {
    cout <<"Username: " << currentUser->getUsername() << endl << "Fullname: " << currentUser->getFullname() << endl ;
};


bool Auth::verifyPassword(User *user, string password) {
    return user->getPassword() == password;
}


bool Auth::isLoggedIn() {
    return currentUser;
}