#pragma once

#include "auth/auth.h"

class App {
    Auth* auth;
public:
    App(Auth* auth): auth(auth){};
    void run();
    void showCurrentUser();
};

