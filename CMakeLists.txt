cmake_minimum_required(VERSION 3.15)
project(wallet CXX)



add_executable(wallet src/wallet.cpp src/main.cpp)



install(TARGETS wallet DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
