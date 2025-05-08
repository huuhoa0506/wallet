#include "user-repository.h"

User* UserRepository::findByUsername(string username) {
    return new User("hoanh", "Nguyen Huu Hoa", "password");
}