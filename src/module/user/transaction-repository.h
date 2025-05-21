#pragma once

#include "transaction.h"

class TransactionRepository
{
private:
    vector<Transaction*> transactions;
    static TransactionRepository* instance;
    TransactionRepository();
public:
    
    ~TransactionRepository();
    vector<Transaction*> const findByUsername(string username);
    Transaction* findById(string id);
    static TransactionRepository* getInstance();
    bool save(Transaction *tran);
};

