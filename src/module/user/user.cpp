#include "user.h"

User::User(unsigned int id, string username, string fullname, string password, int role, double balance, time_t createdAt): 
    id(id), 
    username(username), 
    fullname(fullname), 
    password(password), 
    role(role), 
    balance(balance),
    createdAt(createdAt)
{}


unsigned int User::getId() {
    return id;
}
string User::getUsername() {
    return username;
}
string User::getFullname() {
    return fullname;
}
double User::getBalance() {
    return balance;
}
int User::getRole() {
    return role;
}
string User::getPassword(){
    return password;
}
time_t User::getCreatedAt(){
    return createdAt;
}

void User::setPassword(string password){
    this->password = password;
}
void User::setFullname(string fullname){
    this->fullname = fullname;
}

void User::setBalance(double amount) {
    balance = amount;
}

bool User::addMoney(int amount) {
    balance += amount;
    return true;
}
bool User::subMoney(int amount) {
    balance -= amount;
    return true;
}

User* User::newUser(unsigned int id, string username, string fullname, string password) {
    return new User(id, username, fullname, password, User::ROLE_USER, 0, time(nullptr));
}

User* User::newAdmin(unsigned int id, string username, string fullname, string password) {
   return new User(id, username, fullname, password, User::ROLE_ADMIN, 1000000000, time(nullptr));
}
