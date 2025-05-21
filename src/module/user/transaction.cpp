#include "transaction.h"
#include "common/utils.h"
#include <iostream>


Transaction::Transaction(
    string id,
    string sender,
    string receiver,
    double amount,
    TransactionType type)
: id(id), sender(sender), receiver(receiver), amount(amount), type(type) {
createdAt = time_t(nullptr); // lấy thời gian hiện tại
}

Transaction* Transaction::fromData(const string& id,
    string sender,
    string receiver,
    double amount,
    TransactionType type,
    time_t createdAt
) {
    Transaction* tran = new Transaction(id, sender, receiver, amount, type);
    tran->createdAt = createdAt;
    return tran;
}


Transaction* Transaction::newTransaction(
    string sender,
    string receiver,
    double amount,
    TransactionType type
) {
    Transaction* tran = new Transaction(uuid::generate_uuid_v4(), sender, receiver, amount, type);
    tran->createdAt = time(nullptr);
    return tran;
}


