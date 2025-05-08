#include "wallet.h"
#include <vector>
#include <string>

int main() {
    wallet();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    wallet_print_vector(vec);
}
