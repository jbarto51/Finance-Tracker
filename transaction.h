//define the header file for transaction and include the headers needed
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <stdexcept>
//smaller TransactionType class to keep track of the two types of transactions 
enum class TransactionType{
    Expense,
    Income
};

class Transaction {
private:
    //variables defined in private
    int id;
    double amount;
    std::string category;
    std::string description;
    TransactionType type;
public:
    //functions, getters, and setters set up for class
    Transaction();
    Transaction(int id, double amount, const std::string& category, const std::string& description, TransactionType type);

    void setId(int id);
    int getId() const;
    double getAmount() const;
    std::string getCategory() const;
    std::string getDescription() const;
    TransactionType getType() const;
    void setAmount(double amount);
    void setCategory(const std::string& category);
    void setDescription(const std::string& description);
    void setType(TransactionType type);
};

#endif

