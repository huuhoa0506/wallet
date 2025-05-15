#include "app.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void InputLogin(string& username, string& password) {
    cout << "Username: ";
    cin >> username;
    cout << endl;
    cout << "Password: ";
    cin >> password;
}

void InputRegister(string& username, string& fullname, string& password) {
    cout << "Username: ";
    cin >> username;
    cout << "Fullname: ";
    cin.ignore();
    getline(cin, fullname);
    cout << "Password: ";
    cin >> password;
}

int main() {

    #ifdef _WIN32
        // Thiết lập bảng mã UTF-8 cho console output và input
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    int attemps = 0;
    UserRepository* userRepo;
    Auth* auth = new Auth(userRepo =new UserRepository());

    while(!auth->isLoggedIn()) {
        int option;
        const int LOGIN = 1;
        const int REGISTER = 2;
        cout << "1. Đăng nhập" << endl;
        cout << "2. Đăng ký" << endl;
        cout << "Thoát ấn phím bất kỳ" << endl;
        cin>>option;
        switch(option) {
            case LOGIN: {
                string username, password;
                InputLogin(username, password);
                while(!auth->login(username, password)) {
                    attemps++;
                    cout << "Username or password incorrent!" << endl;
            
                    InputLogin(username, password);
                    if(attemps == 3) exit(1);
                }
                break;
            }
            case REGISTER: {
                string username, fullname, password;
                InputRegister(username, fullname, password);
                while(!auth->registerAccount(username, fullname, password)) {
                    attemps++;
                    cout << "The username was exits!" << endl;
            
                    InputRegister(username, fullname, password);
                    if(attemps == 3) exit(1);
                }
                break;
            }
        } 
    }
   
    App app(auth);

    app.run();
}
