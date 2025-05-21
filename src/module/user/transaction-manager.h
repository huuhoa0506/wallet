#include <string>
#include <iostream>
#include "user-repository.h"
#include "transaction-repository.h"

using namespace std;

class TransactionManager
{
private:
    UserRepository* userRepo;
    TransactionRepository* transRepo;
public:
    TransactionManager(UserRepository* userRepo, TransactionRepository* transRepo);
    ~TransactionManager();
    bool transfer(string fromUsername, string toUsername, double amount);
};


