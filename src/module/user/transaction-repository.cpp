#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "transaction-repository.h"
#include "common/notfound-exception.h"

void readFromFile(vector<Transaction*>& transactions) {
    ifstream in("storage/data/transactions.csv");
    
    if(!in) {
        throw runtime_error("Could not open the file");
    }

    transactions.clear();

    string line;
    while(getline(in, line)) {
        istringstream ss(line);
        string token;
        getline(ss, token, ',');
        string id = token;
        getline(ss, token, ',');
        string sender = token;
        getline(ss, token, ',');
        string receiver = token;
        getline(ss, token, ',');
        double amount = stod(token);
        getline(ss, token, ',');
        TransactionType type = static_cast<TransactionType>(stoi(token));
        getline(ss, token, ',');
        time_t createdAt(stol(token));
        transactions.push_back(Transaction::fromData(id, sender, receiver, amount, type, createdAt));
    }
    in.close();

}


void writeToFile(const vector<Transaction*>& transactions) {
    ofstream out("storage/data/transactions.csv");
    for (Transaction* tran : transactions) {
        out << tran->getId() << "," << tran->getSender() << "," << tran->getReceiver() << ","<< std::fixed << std::setprecision(2) << tran->getAmount() << "," << static_cast<int>(tran->getType()) << "," << tran->getCreatedAt() << "\n";
    }
    out.close();
}

TransactionRepository* TransactionRepository::instance = nullptr;

TransactionRepository* TransactionRepository::getInstance() {
    if(instance == nullptr) {
        instance = new TransactionRepository();
    }
    return instance;
}

TransactionRepository::TransactionRepository(/* args */)
{
    readFromFile(transactions);
}

TransactionRepository::~TransactionRepository()
{
}

Transaction* TransactionRepository::findById(string id) {

    for(Transaction* tran: transactions) {
        if(tran->getId() == id) {
            return tran;
        }
    }

    throw NotfoundException("Transaction not found!");
}

bool TransactionRepository::save(Transaction* tran)
{


    try
    {
        findById(tran->getId());
    }
    catch(const NotfoundException& e)
    {

        transactions.push_back(tran);
    }

    writeToFile(transactions);

    return true;
}