#pragma once

#include "auth/auth.h"
#include "user/transaction-manager.h"
#include "user/transaction-repository.h"

class App {
    Auth* auth;
    TransactionManager* transManager;
public:
    App(Auth* auth, TransactionManager* transManager): auth(auth), transManager(transManager){};
    void run();
    void showCurrentUser();
    void runAsAdmin();
    void authenticate();
};

