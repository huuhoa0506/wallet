#include "app.h"
#include "common/utils.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

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
    app.setup();
    app.run();
}
