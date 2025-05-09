#include <iostream>
#include <fstream>
#include "user-repository.h"
#include "common/notfound-exception.cpp"


using namespace std;


User* UserRepository::findByUsername(string username) {

    for(auto u : this->users) {
        if (u->getUsername() == username) return u;
    }

    throw NotfoundException("User not found!");
}

bool UserRepository::save(User* user) {
    
    try
    {
        User* user = findByUsername(user->getUsername());
    }
    catch(const NotfoundException& e)
    {
        users.push_back(user);
    }

    ofstream out("storage/data/users.csv");
    for (User* user : users) {
        out << user->getId() << "," << user->getUsername() << "," << user->getFullname() << "," << user->getPassword() << "\n";
    }
    out.close();

    return true;
}