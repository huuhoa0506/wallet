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
    UserRepository* userRepo;
    Auth* auth = new Auth(userRepo =new UserRepository());

    userRepo->save(new User(1,"hoanh", "Nguyen Hoa", "password"));

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
}
