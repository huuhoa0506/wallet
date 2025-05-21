#pragma once


struct OTPEntry {
    std::string code;      // Mã OTP
    bool verified;         // Đã xác thực hay chưa
    time_t createdAt;      // (Optional) thời gian tạo để kiểm tra timeout
};


class OTPManager
{
private:
    std::unordered_map<std::string, OTPEntry> otpStore;

    std::string generate_code(int length);
    OTPManager();
public:
   
    static OTPManager& getInstance() {
        static OTPManager instance; // only one instance
        return instance;
    }

    std::string createOTP(const std::string& username);

    bool verifyOTP(const std::string& username, const std::string& inputCode);

    bool isVerified(const std::string& username) const;

    // xóa copy & move
    OTPManager(const OTPManager&) = delete;
    void operator=(const OTPManager&) = delete;
};
