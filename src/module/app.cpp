#include <iostream>
#include <fstream>
#include <app.h>
#include <common/utils.h>
#include "auth/otp-manager.h"


using namespace std;


const int SHOW_PROFILE = 1;
const int UPDATE_PROFILE = 2;
const int CHANGE_PASSWORD = 3;
const int TRANSFER_MONEY = 4;
const int HISTORY = 5;
const int ADMIN = 6;
const int LOGOUT = 7;
const int EXIT_APP = 8;



void showMenu() {
    // show menu
    cout << endl<< endl<< endl;
    cout <<"----------------------------------"<< endl;
    cout << "1. Hiển thị thông tin người dùng." << endl;
    cout << "2. Cập nhật thông tin người dùng." << endl;
    cout << "3. Đổi mật khẩu." << endl;
    cout << "4. Chuyển tiền." << endl;
    cout << "5. Lịch sử giao dịch" << endl;
    cout << "6. Quản trị" << endl;
    cout << "7. Đăng xuất" << endl;
    cout << "8. Thoát" << endl;
    cout <<"----------------------------------"<< endl;
}

void inputOption(int& option) {
    cout << "Nhập tuỳ chọn: ";
    cin >> option;
    cout << endl;
}

void inputPassword(string& oldPassword, string& newPassword) {
    cout << "Mật khẩu hiện tại:"; cin >> oldPassword;
    cout << "Mật khẩu mới:"; cin >> newPassword;
}

void inputTransfer(string& receiver, string& amount) {
    cout << "Người nhận: "; cin >> receiver;
    cin.ignore();
    cout << "Số tiền: "; getline(cin, amount);
}


void App::run() {

    do {
        //Kiểm tra trạng thái xác thực của tài khoản, bao gồm đăng nhập và đăng ký tài khoản
        //hàm này cho phép đăng nhập sai không quá 3 lần
        if(!auth->isLoggedIn()) {
            authenticate();
        }

        // Hiển thị menu
        showMenu();

        int option;

        inputOption(option);

        switch(option) {
            case SHOW_PROFILE: {

                auth->showCurrentUser();

                break;
            }
            case UPDATE_PROFILE: {

                User* authUser = auth->getAuthUser();
                string fullname;
                cin.ignore();
                cout << "Tên đầy đủ:";getline(cin, fullname);
                auth->updateProfile(fullname);
                break;
            }
            case CHANGE_PASSWORD: {

                string oldPassword, newPassword;

                inputPassword(oldPassword, newPassword);

                while(!auth->changePassword(oldPassword, newPassword)) {
                    cout << "Mật khẩu hiện tại chưa đúng" << endl;
                    inputPassword(oldPassword, newPassword);
                }

                break;
            }
            case TRANSFER_MONEY: {
                string receiver;
                string sender = auth->getAuthUser()->getUsername();
                string amount;
                inputTransfer(receiver, amount);

                OTPManager& otpManager = OTPManager::getInstance();
                std::string otp = otpManager.createOTP(sender);
                std::cout << "OTP sent to user: " << otp << std::endl;

                // Nhập mã từ người dùng
                std::string input;
                std::cout << "Nhập mã OTP: ";
                std::cin >> input;
                
                // Xác minh OTP
                if (otpManager.verifyOTP(sender, input)) {
                    std::cout << "OTP hợp lệ. Truy cập được cho hoa.\n";
                } else {
                    std::cout << "OTP sai hoặc hết hạn.\n";
                    break;
                }
                
                if(!transManager->transfer(sender, receiver, stod(amount))) {
                    cerr << "Chuyển tiền thất bại. \n";
                } else {
                    cout << "Chuyển tiền thành công. \n";
                }

                break;
            }
            case HISTORY: {

                vector<Transaction*> trans = transManager->historyOfUser(auth->getAuthUser()->getUsername());


                int colWidth = 20;

                cout << left << setw(40) << "ID";
                cout << left << setw(colWidth) << "Sender";
                cout << left << setw(colWidth) << "Receiver";
                cout << left << setw(colWidth) << "Amount";
                cout << left << setw(colWidth) << "Time";
                cout << "\n";

                for (const auto& tran : trans) {
                    cout << left << setw(40) << tran->getId();
                    cout << left << setw(colWidth) << tran->getSender();
                    cout << left << setw(colWidth) << tran->getReceiver();
                    cout << left << setw(colWidth) << tran->getAmount();
                    cout << left << setw(colWidth) << utils::date_time(tran->getCreatedAt());
                    cout << "\n";
                }

                break;
            }
            case ADMIN: {
                runAsAdmin();
                break;
            }
            case LOGOUT: {
                auth->logout();
                break;
            }
            case EXIT_APP: 
            default: 
            {
                exit(0);
            }
        }
    } while(true);
};


void App::runAsAdmin() {

    const int USER_LIST = 1;
    const int CREATE_ACCOUNT = 2;
    const int UPDATE_PROFILE = 3;
    const int EXIT = 4;

    bool isRuning = true;

    UserRepository* userRepo = UserRepository::getInstance();

    if(auth->isAdmin()) {
        while(isRuning) {

            // show menu
            cout << endl;
            cout <<"-------------Administrator--------"<< endl;
            cout << "1. Danh sách nhóm." << endl;
            cout << "2. Tạo tài khoản." << endl;
            cout << "3. Cập nhật profile." << endl;
            cout << "4. Thoát" << endl;
            cout <<"----------------------------------"<< endl;
            int option;
            cout << "Nhập tuỳ chọn: ";
            cin >> option;
            cout << endl;
    
            switch(option) {
                case USER_LIST: {
                    
                    vector<User*> users = userRepo->getAll();
                    // Đặt độ rộng cột
                    int colWidth = 15;

                    cout << left << setw(10) << "ID";
                    cout << left << setw(colWidth) << "Username";
                    cout << left << setw(colWidth) << "Fullname";
                    cout << left << setw(colWidth) << "Role";
                    cout << left << setw(colWidth) << "Balance";
                    cout << left << setw(colWidth) << "Registered";
                    cout << "\n";

                    for (const auto& user : users) {
                        cout << left << setw(10) << user->getId();
                        cout << left << setw(colWidth) << user->getUsername();
                        cout << left << setw(colWidth) << user->getFullname();
                        cout << left << setw(colWidth) << user->getRole();
                        cout << left << setw(colWidth) << user->getBalance();
                        cout << left << setw(colWidth) << utils::date_time(user->getCreatedAt());
                        cout << "\n";
                    }
    
                    break;
                }
                case CREATE_ACCOUNT: {
                    string username, fullname, password;
                    utils::InputRegister(username, fullname, password);
                    cout << "-----------Tạo tài khoản----------" << endl;
                    unsigned int id  = userRepo->nextID();
                    User* user = User::newUser(id, username, fullname, utils::md5(password));
                    userRepo->save(user);
                    break;
                }
                case UPDATE_PROFILE: {
    
                    cout << "Cập nhật tài khoản: ";
    
                    break;
                }
                case EXIT: 
                default: 
                {
                    isRuning = false;
                }
            }
        }
    } else {
        cerr << "Bạn không có quyền truy cập mục này! \n";
    }
    

}

void App::authenticate() {

    int attemps = 0;

    while(!auth->isLoggedIn()) {
        int option;
        const int LOGIN = 1;
        const int REGISTER = 2;
        cout << "1. Đăng nhập" << endl;
        cout << "2. Đăng ký" << endl;
        cin>>option;
        switch(option) {
            case LOGIN: {
                string username, password;
                utils::InputLogin(username, password);
                while(!auth->login(username, password)) {
                    attemps++;
                    cout << "Sai username hoặc mật khẩu!" << endl;
            
                    utils::InputLogin(username, password);
                    if(attemps == 3) exit(0);
                }
                break;
            }
            case REGISTER: {
                string username, fullname, password;
                utils::InputRegister(username, fullname, password);
                while(!auth->registerAccount(username, fullname, password)) {
                    attemps++;
                    cout << "Username có thể đã tồn tại!" << endl;
            
                    utils::InputRegister(username, fullname, password);
                    if(attemps == 3) exit(0);
                }
                break;
            }
        } 
    }
}

void App::setup() {
    if (!filesystem::exists("storage/data")) {
        
        filesystem::create_directories("storage/data");
        string userdata = "storage/data/users.csv";
        string transdata = "storage/data/transactions.csv";
        string filename = "storage/data/config.txt";

        std::fstream userfile(userdata, std::ios::out);
        std::fstream tranfile(transdata, std::ios::out);
        std::fstream config(filename, std::ios::out);

        userfile.close();
        tranfile.close();
        config.close();

        UserRepository* userRepo = UserRepository::getInstance();
        User* user = User::newAdmin(1, "system", "System", utils::md5("admin"));
        userRepo->save(user);
    }

}
