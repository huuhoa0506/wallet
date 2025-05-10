#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/md5.h>
#include "common/notfound-exception.h"
#include "auth.h"

using namespace std;


string md5(const string& input) {
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((const unsigned char*)input.c_str(), input.size(), result);

    ostringstream sout;
    sout << hex << setfill('0');
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
        sout << setw(2) << static_cast<int>(result[i]);
    return sout.str();
}




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
        User *newUser = new User(id, username, fullname, md5(password));

        userRepo->save(newUser);
        currentUser = newUser;
        return true;
    }
};

bool Auth::changePassword(string oldPassword, string newPassword) {
    if(verifyPassword(currentUser, oldPassword)) {
        currentUser->setPassword(md5(newPassword));
        userRepo->save(currentUser);
        return true;
    }

    return false;
}


void Auth::showCurrentUser() {
    cout <<"Username: " << currentUser->getUsername() << endl << "Fullname: " << currentUser->getFullname() << endl ;
};


bool Auth::verifyPassword(User *user, string password) {
    return user->getPassword() == md5(password);
}


bool Auth::isLoggedIn() {
    return currentUser;
}