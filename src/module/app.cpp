#include <iostream>
#include <app.h>


using namespace std;


const int SHOW_PROFILE = 1;
const int UPDATE_PROFILE = 2;
const int CHANGE_PASSWORD = 3;
const int TRANSFER_MONEY = 4;
const int EXIT_APP = 5;

void App::run() {


    bool isRuning = true;

    do {

        // show menu
        cout << endl;
        cout << "1. Hiển thị thông tin người dùng." << endl;
        cout << "2. Cập nhật thông tin người dùng." << endl;
        cout << "3. Đổi mật khẩu." << endl;
        cout << "4. Chuyển tiền." << endl;
        cout << "5. Thoát" << endl;

        int option;
        cout << "Nhập tuỳ chọn: ";
        cin >> option;
        cout << endl;

        switch(option) {
            case SHOW_PROFILE: {

                auth->showCurrentUser();

                break;
            }
            case UPDATE_PROFILE: {

                cout << "Thực hiện cập nhật thông tin người dùng" << endl;

                break;
            }
            case CHANGE_PASSWORD: {

                cout << "Thực hiện đổi mật khẩu" << endl;

                break;
            }
            case TRANSFER_MONEY: {

                cout << "Chuyển tiền" << endl;

                break;
            }
            case EXIT_APP: 
            default: 
            {
                isRuning = false;
            }
        }
    } while(isRuning);
};



