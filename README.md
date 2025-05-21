●	Giới thiệu dự án: # wallet - Hệ thống đăng nhập và đăng ký tài khoản và quản lý ví điểm thưởng
●	Các thành viên tham gia dự án:
+ Nguyễn Hữu Hòa(Trưởng nhóm)
+ Nguyễn Vũ Thắng
+ Nguyễn Quốc Cường
+ Phạm Vương Mạnh
 (công việc cụ thể để sau khi nhóm trưởng giới thiệu và Demo đến từng phần của mỗi người)

●	Phân tích chi tiết:...

●	Cách tải chương trình, dịch chương trình, các tập tin:
**Điều kiện**
***Cài đặt conan 2 ***


**Install**
`conan install . --build=missing`

`cmake -B build -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release`

`cmake --build build`

**Chạy App:**
***Chạy dòng lệnh sau tại thư mục gốc sau khi build***
`build/wallet`

C++ project

●	Mô tả cách chạy chương trình:

● Tài liệu đã tham khảo: 
+ Lập trình C++ cơ bản và nâng cao https://cplusplus.com/, https://en.cppreference.com/w/.
+ Quản lý OTP và xác thực: CPP_OTP GitHub – sinh mã OTP bằng C++, COTP GitHub – thư viện tạo và kiểm tra OTP.
+ Khái niệm cơ bản về OTP: https://authy.com/what-is-a-one-time-password-otp/.
+ Nguyên lý ACID trong hệ thống tài chính:https://200lab.io/blog/acid-la-gi/
+ Tham khảo về quản lý ví & giao dịch:https://www.geeksforgeeks.org/e-wallet-management-system/
