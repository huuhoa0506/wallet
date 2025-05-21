#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "user-repository.h"
#include "common/notfound-exception.h"


using namespace std;

string storage = "storage/data/users.csv";

bool safe_open(std::fstream &fs, const std::string &filename,
               std::ios::openmode mode = std::ios::in | std::ios::out) {
    fs.open(filename, mode);
    if (!fs.is_open()) {
        // Nếu mở thất bại (do file không tồn tại), tạo file mới
        std::ofstream create_file(filename);
        if (!create_file) return false; // Không tạo được file
        create_file.close();
        fs.open(filename, mode); // Mở lại sau khi tạo
    }
    return fs.is_open();
}


void readFromFile(vector<User*>& users) {
    fstream in;

    safe_open(in, storage, ios::in);
    
    

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
        getline(ss, token, ',');
        int role = stoi(token);
        getline(ss, token, ',');
        double balance(stod(token));
        getline(ss, token, ',');
        time_t createdAt(stol(token));
        users.push_back(new User(id, username, fullname, password, role, balance, createdAt));
    }
    in.close();

}


void writeToFile(const vector<User*>& users) {
    fstream out;
    safe_open(out, storage, ios::out);
    for (User* user : users) {
        out << user->getId() << "," << user->getUsername() << "," << user->getFullname() << "," << user->getPassword() << "," << user->getRole() <<"," << fixed << std::setprecision(2)<< user->getBalance() <<"," << user->getCreatedAt() <<"\n";
    }
    out.close();
}


UserRepository::UserRepository(){
   readFromFile(users);
   incrementing=users.size();
};

UserRepository* UserRepository::getInstance() {
    if(instance == nullptr) {
        instance = new UserRepository();
    }
    return instance;
}

User* UserRepository::findByUsername(string username) {

    for(User* u : this->users) {
        if (u->getUsername() == username) {
            return u;
        } 
    }

    throw NotfoundException("User not found!");
}

bool UserRepository::save(User* user) {
    
    try
    {
        findByUsername(user->getUsername());
    }
    catch(const NotfoundException& e)
    {
        users.push_back(user);
    }

    writeToFile(users);

    return true;
}

unsigned int UserRepository::nextID() {
    return ++incrementing;
}


const vector<User*> UserRepository::getAll() {
    return users;
}