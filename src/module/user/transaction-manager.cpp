
#include <stdexcept>
#include "transaction-manager.h"
#include "transaction-repository.h"

using namespace std;

TransactionManager::TransactionManager(UserRepository* userRepo, TransactionRepository* transRepo): userRepo(userRepo), transRepo(transRepo)
{

}

bool TransactionManager::transfer(string fromUsername, string toUsername, double amount) {

    User* fromUser;
    User* toUser;

    double fromBalance = fromUser->getBalance();
    double toBalance = toUser->getBalance();

    try
    {
        fromUser = userRepo->findByUsername(fromUsername);
        toUser = userRepo->findByUsername(toUsername);
        fromBalance = fromUser->getBalance();
        toBalance = toUser->getBalance();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    try
    {
        if(fromUser->getBalance() >= amount) {

            fromUser->subMoney(amount);
            toUser->addMoney(amount);

            userRepo->save(fromUser);
            userRepo->save(toUser);

            Transaction* tran = Transaction::newTransaction(
                fromUser->getUsername(), 
                toUser->getUsername(), 
                amount, 
                TransactionType::TRANSFER
            );

            transRepo->save(tran);

            return true;
        } else {
            throw runtime_error("Số dư không đủ");
        }

        return true;
    }
    catch(const exception& e)
    {

        fromUser->setBalance(fromBalance);
        fromUser->setBalance(toBalance);

        cerr << e.what() << '\n';
        return false;
    }
    
}