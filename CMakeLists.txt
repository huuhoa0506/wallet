cmake_minimum_required(VERSION 3.15)
project(wallet CXX)


add_executable(
        wallet 
        src/module/common/notfound-exception.cpp
        src/module/app.cpp 
        src/module/user/user.cpp 
        src/module/user/user-repository.cpp
        src/module/auth/auth.cpp 
        src/wallet.cpp 
        src/main.cpp
)

target_include_directories(wallet PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/module
    
)



install(TARGETS wallet DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
