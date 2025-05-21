#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "otp-manager.h"

using namespace std;


OTPManager::OTPManager(/* args */)
{
    srand(time(nullptr)); // Seed random
}

string OTPManager::generate_code(int length = 6) {
    string code;
    for (int i = 0; i < length; ++i) {
        code += to_string(rand() % 10);
    }
    return code;
}


string OTPManager::createOTP(const string& username) {
    string code = generate_code();
    otpStore[username] = OTPEntry{ code, false, time(nullptr) };
    return code;
}

bool OTPManager::verifyOTP(const string& username, const string& inputCode) {
    auto it = otpStore.find(username);
    if (it == otpStore.end()) return false;

    if (it->second.code == inputCode) {
        it->second.verified = true;
        // Sinh mã mới để tránh reuse
        createOTP(username);
        return true;
    } else {
        // Sai thì cũng tạo lại mã mới
        createOTP(username);
        return false;
    }
}

bool OTPManager::isVerified(const string& username) const {
    auto it = otpStore.find(username);
    return it != otpStore.end() && it->second.verified;
}
