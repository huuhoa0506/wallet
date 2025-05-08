#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define WALLET_EXPORT __declspec(dllexport)
#else
  #define WALLET_EXPORT
#endif

<<<<<<< HEAD
=======
WALLET_EXPORT void run();
>>>>>>> 8ff7fea (Init)
WALLET_EXPORT void wallet();
WALLET_EXPORT void wallet_print_vector(const std::vector<std::string> &strings);
