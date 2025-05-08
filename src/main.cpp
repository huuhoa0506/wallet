<<<<<<< HEAD
#include "wallet.h"
#include <vector>
#include <string>

int main() {
    wallet();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    wallet_print_vector(vec);
=======
#include "app.h"
#include <iostream>


using namespace std;

void InputAccountInfo(string& username, string& password) {
    cout << "Username: ";
    cin >> username;
    cout << endl;
    cout << "Password: ";
    cin >> password;
}

int main() {
    
    int attemps = 0;

    Auth* auth = new Auth(new UserRepository);

    string username, password;

    InputAccountInfo(username, password);
   
    while(!auth->login(username, password)) {
        attemps++;
        cout << "Username or password incorrent!" << endl;

        InputAccountInfo(username, password);
        if(attemps == 3) exit(1);
    }
    
    App app(auth);

    app.run();
>>>>>>> 8ff7fea (Init)
}
