#include "app.h"
#include "common/utils.h"
#include <iostream>

using namespace std;

int main() {

    Auth* auth = new Auth(UserRepository::getInstance());
    App app(
        auth, 
        new TransactionManager(
            UserRepository::getInstance(), 
            TransactionRepository::getInstance()
        )
    );

    app.run();
}
