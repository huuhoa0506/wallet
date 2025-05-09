#include "user.h"

User::User(unsigned int id, string username, string fullname, string password): id(id), username(username), fullname(fullname), password(password){}

unsigned int User::getId() {
    return id;
}
string User::getUsername() {
    return username;
}
string User::getFullname() {
    return fullname;
}
string User::getPassword(){
    return password;
}
void User::setPassword(string password){
    this->password = password;
}