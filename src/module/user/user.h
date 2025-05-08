#include <string>

using namespace std;

class User {
    string fullname;
    string username;
    string password;
public:
    User(string username, string fullname, string password);
    string getUsername();
    string getFullname();
    string getPassword();
    void setPassword(string password);
};