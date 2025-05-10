#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "user-repository.h"
#include "common/notfound-exception.h"


using namespace std;

string storage = "storage/data/users.csv";


void readFromFile(string filename, vector<User*>& users) {
    ifstream in("storage/data/users.csv");
    
    if(!in) {
        throw runtime_error("Could not open the file");
    }

    users.clear();

    string line;
    while(getline(in, line)) {
        istringstream ss(line);
        string token;
        getline(ss, token, ',');
        int id = stoi(token);
        getline(ss, token, ',');
        string username = token;
        getline(ss, token, ',');
        string fullname = token;
        getline(ss, token, ',');
        string password = token;   
        users.push_back(new User(id, username, fullname, password));
    }
    in.close();

}


void writeToFile(string filename, const vector<User*>& users) {
    ofstream out(filename);
    for (User* user : users) {
        out << user->getId() << "," << user->getUsername() << "," << user->getFullname() << "," << user->getPassword() << "\n";
    }
    out.close();
}


UserRepository::UserRepository(){
   readFromFile(storage, users);
   incrementing=users.size();
};

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

    writeToFile(storage, users);

    return true;
}

unsigned int UserRepository::nextID() {
    return ++incrementing;
}