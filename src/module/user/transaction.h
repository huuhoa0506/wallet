#pragma once

#include <string>
#include <ctime>  // time_t
#include <iomanip>
#include <sstream>
 
using namespace std;

enum class TransactionType {
    TRANSFER = 1,
    DEPOSIT = 2,
    WITHDRAW = 3
};

class Transaction {
private:
    string id;
    string sender;
    string receiver;
    double amount;
    time_t createdAt;
    TransactionType type;

    // Constructor
    Transaction(const string id,
        string sender,
        string receiver,
        double amount,
        TransactionType type);

public:
    // Getters
    string getId() const { return id; }
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    double getAmount() const { return amount; }
    time_t getCreatedAt() const { return createdAt; }
    TransactionType getType() const { return type; }

    // Convert to string (for debug/log)
    string toString() const {
        ostringstream oss;
        oss << "Transaction[" << id << "] "
            << sender << " -> " << receiver
            << " | Amount: " << amount
            << " | Type: " << transactionTypeToString(type)
            << " | Time: " << asctime(localtime(&createdAt));
        return oss.str();
    }

    // Utility
    static string transactionTypeToString(TransactionType t) {
        switch (t) {
            case TransactionType::TRANSFER: return "TRANSFER";
            case TransactionType::DEPOSIT: return "DEPOSIT";
            case TransactionType::WITHDRAW: return "WITHDRAW";
            default: return "UNKNOWN";
        }
    }

    static Transaction* fromData(const string& id,
        string sender,
        string receiver,
        double amount,
        TransactionType type,
    time_t createdAt
    );

    static Transaction* newTransaction(
        string sender,
        string receiver,
        double amount,
        TransactionType type
    );

};