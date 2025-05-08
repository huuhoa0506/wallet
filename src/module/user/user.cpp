#include "user.h"

User::User(string username, string fullname, string password): username(username), fullname(fullname), password(password){}
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