#include <iostream>
#include <sstream>
#include "common/notfound-exception.h"
#include "common/utils.h"
#include "auth.h"

using namespace std;

bool Auth::login (string username, string password) {

    User *user;
    try
    {
        user = userRepo->findByUsername(username);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    
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
        User *newUser = User::newUser(id, username, fullname, utils::md5(password));

        userRepo->save(newUser);
        currentUser = newUser;
        return true;
    }
};

bool Auth::changePassword(string oldPassword, string newPassword) {
    if(verifyPassword(currentUser, oldPassword)) {
        currentUser->setPassword(utils::md5(newPassword));
        userRepo->save(currentUser);
        return true;
    }

    return false;
}


void Auth::showCurrentUser() {
    cout <<"Tên đăng nhập: " << currentUser->getUsername() << endl 
         << "Tên: " << currentUser->getFullname() << endl
         << "Role: " << currentUser->getRole() << endl
         << "Số dư: " << currentUser->getBalance() << endl
         << "Ngày tạo: " << currentUser->getCreatedAt() << endl ;
};


bool Auth::verifyPassword(User *user, string password) {
    return user->getPassword() == utils::md5(password);
}


bool Auth::isLoggedIn() {
    return currentUser;
}

User* Auth::getAuthUser() {
    return currentUser;
}

bool Auth::updateProfile(string fullname) {
    currentUser->setFullname(fullname);
    userRepo->save(currentUser);
    return true;
}

bool Auth::isAdmin() {
    return currentUser->getRole() == User::ROLE_ADMIN;
}

bool Auth::logout() {
    currentUser = nullptr;
    return true;
}