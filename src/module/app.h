#pragma once

#include "auth/auth.h"
#include "user/transaction-manager.h"
#include "user/transaction-repository.h"

const double TOTOAL_SYSTEM_AMOUNT = 100000000000

class App {
    Auth* auth;
    TransactionManager* transManager;
public:
    App(Auth* auth, TransactionManager* transManager): auth(auth), transManager(transManager){};
    void run();
    void showCurrentUser();
    void runAsAdmin();
    void authenticate();
    void setup();
};
