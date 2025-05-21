#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <openssl/md5.h>
#include <iomanip>
#include <ctime>
#include <termios.h>
#include <unistd.h>


using namespace std;

namespace utils {
    string GetHiddenInput(const string& prompt = "Password: ") {
        cout << prompt;


        // Xóa dấu newline còn sót lại trong bộ đệm
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        termios oldt, newt;
        string password;
    
        // Lấy terminal hiện tại
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
    
        // Tắt chế độ echo
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
        getline(cin, password);
    
        // Khôi phục lại trạng thái terminal cũ
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
        return password;
    }


    void InputRegister(string& username, string& fullname, string& password) {
        cout << "Username: ";
        cin >> username;
        cout << "Fullname: ";
        getline(cin, fullname);
        cin.ignore();
        password = GetHiddenInput();
    }

    void InputLogin(string& username, string& password) {
        cout << "Username: ";
        cin >> username;
        password = GetHiddenInput("Password: ");
    }


    string md5(const string& input) {
        unsigned char result[MD5_DIGEST_LENGTH];
        MD5((const unsigned char*)input.c_str(), input.size(), result);

        ostringstream sout;
        sout << hex << setfill('0');
        for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
            sout << setw(2) << static_cast<int>(result[i]);
        return sout.str();
    }

    string date_time(time_t timestamp) {
        stringstream ss;
        tm* tm_time = localtime(&timestamp); // chuyển sang dạng cục bộ

        ss << put_time(tm_time, "%Y-%m-%d %H:%M:%S");  // định dạng: YYYY-MM-DD HH:MM:SS
        return ss.str();
    }

   
}


namespace uuid {
    static random_device              rd;
    static mt19937                    gen(rd());
    static uniform_int_distribution<> dis(0, 15);
    static uniform_int_distribution<> dis2(8, 11);

    string generate_uuid_v4() {
        stringstream ss;
        int i;
        ss << hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };
        return ss.str();
    }
}


