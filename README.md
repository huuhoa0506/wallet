# wallet

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
