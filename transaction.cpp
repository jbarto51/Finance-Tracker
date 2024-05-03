// include the header file for transaction
#include "transaction.h"

//intialize the Transaction class with the id, amount, category, description, and type
Transaction::Transaction() : id(-1), amount(0.0), category(""), description(""), type(TransactionType::Expense) {}

//initialize the variables for the Transaction function within the class
Transaction::Transaction(int id, double amount, const std::string& category, const std::string& description, TransactionType type)
    : id(id), amount(amount), category(category), description(description), type(type) {}

//getters and setters for the variables in transaction
void Transaction::setId(int id) {
    this->id = id;
}

int Transaction::getId() const {
    return id;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getCategory() const {
    return category;
}

std::string Transaction::getDescription() const {
    return description;
}
TransactionType Transaction::getType() const {
    return type;
}
void Transaction::setAmount(double amount) {
	this->amount = amount;
    }

void Transaction::setCategory(const std::string& category) {
        this->category = category;
    }

void Transaction::setDescription(const std::string& description) {
        this->description = description;
    }

void Transaction::setType(TransactionType type) {
        this->type = type;
    }


