cmake_minimum_required(VERSION 3.15)
project(wallet CXX)


find_package(OpenSSL REQUIRED)


add_executable(
        wallet 
        src/module/common/notfound-exception.h
        src/module/app.cpp 
        src/module/user/user.cpp 
        src/module/user/user-repository.cpp
        src/module/auth/auth.cpp 
        src/wallet.cpp 
        src/main.cpp
)


target_link_libraries(wallet PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_include_directories(wallet PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/module
    PRIVATE ${OPENSSL_INCLUDE_DIR}
    
)



install(TARGETS wallet DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
