#include <string>

using namespace std;

class User {
    unsigned int id;
    string username;
    string fullname;
    string password;
public:
    User(unsigned int id, string username, string fullname, string password);
    unsigned int getId();
    string getUsername();
    string getFullname();
    string getPassword();
    void setPassword(string password);
};