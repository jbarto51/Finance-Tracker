//include the header files and the headers needed for the functions
#include "transaction.h"
#include "transactionfile.h"
#include <fstream>
#include <iostream>
#include <algorithm>

//TransactionFile is defined for filename and last id
TransactionFile::TransactionFile(const std::string& filename) : filename(filename), lastId(0) {}

//check if it exists
bool TransactionFile::exists() const {
    return true;
}
// function to add transactions to report
void TransactionFile::add(Transaction& transaction) {
    lastId++;
    transaction.setId(lastId);
    transactions[lastId] = transaction;
}
//function to delete a transaction
void TransactionFile::deleteTransaction(int id) {
	auto it = transactions.find(id);
	if (it != transactions.end()) {
		transactions.erase(it);
		std::cout<< "Transaction ID " << id << " deleted successfully.\n";
	} else {
		std::cout << "Transaction ID " << id << " not found.\n";
}
}
//function to save a transaction to a file
void TransactionFile::save() const {
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    for (auto it = transactions.begin(); it != transactions.end(); it++) {
        file << " \1 " << it->first << " \2 " << it->second.getAmount() << " \2 " << it->second.getCategory()
             << " \2 " << it->second.getDescription() << " \3\n ";
    }
    file.close();
}
//function to search for a transaction and print the results
std::vector<int> TransactionFile::search(const std::string& query) const {
    std::vector<int> results;
    return results;
}
//function to display all transactions
void TransactionFile::displayAll() const {
    for (const auto& [id, transaction] : transactions) {
        std::cout << "Transaction ID: " << transaction.getId() << std::endl;
        std::cout << "Amount: $" << transaction.getAmount() << std::endl;
        std::cout << "Category: " << transaction.getCategory() << std::endl;
        std::cout << "Description: " << transaction.getDescription() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}
//function to generate fincnaical report using expenses as a negative number and income as positive
void TransactionFile::generateFinancialReport() const {
    double totalExpenses = 0.0;
    double totalIncome = 0.0;

    for (const auto& [id, transaction] : transactions) {
        if (transaction.getType() == TransactionType::Expense) {
            totalExpenses += transaction.getAmount();
        } else if (transaction.getType() == TransactionType::Income){
            totalIncome += transaction.getAmount();
        }
    }

    double netProfit = totalIncome - totalExpenses;

    std::cout << "Financial Report:" << std::endl;
    std::cout << "Total Income: $" << totalIncome << std::endl;
    std::cout << "Total Expenses: $" << totalExpenses << std::endl;
    std::cout << "Net Profit: $" << netProfit << std::endl;
}
//getter for transactions
const std::map<int, Transaction>& TransactionFile::getTransactions() const {
    return transactions;
}
//function to update a transaction based on id
void TransactionFile::update(int id, const Transaction& newTransaction) {
    auto it = transactions.find(id);
    if (it != transactions.end()) {
        transactions[id] = newTransaction;
	Transaction& existingTransaction = it->second;
        existingTransaction.setAmount(newTransaction.getAmount());
        existingTransaction.setDescription(newTransaction.getDescription());
        existingTransaction.setCategory(newTransaction.getCategory());
	 existingTransaction.setType(newTransaction.getType());
        std::cout << "Transaction updated successfully.\n";
    } else {
        std::cout << "Transaction ID " << id << " not found.\n";
    }
}
//function to search for all transactions belonging to a category
std::vector<Transaction> TransactionFile::searchByCategory(const std::string& category) const {
    std::vector<Transaction> results;
    for (const auto& [id, transaction] : transactions) {
        if (transaction.getCategory() == category) {
            results.push_back(transaction);
        }
    }
    return results;
}
//function to add a budget
void TransactionFile::addBudget(const Budget& budget) {
        budgets.push_back(budget);
    }
//function to get the total budget
double TransactionFile::getTotalBudget() const {
        double totalBudget = 0.0;
        for (const auto& budget : budgets) {
            totalBudget += budget.amount;
        }
        return totalBudget;
    }
//function to display all budgets
void TransactionFile::displayBudgets() const {
        std::cout << "Budgets:\n";
        for (const auto& budget : budgets) {
            std::cout << "Category: " << budget.category << ", Amount: $" << budget.amount << std::endl;
        }
    }
//function to update an existing budget
void TransactionFile::updateBudget(const std::string& category, double newAmount) {
    for (auto& budget : budgets) {
        if (budget.category == category) {
            budget.amount = newAmount;
            std::cout << "Budget for category " << category << " updated successfully.\n";
            return;  // Exit the function after updating
        }
    }
    std::cout << "Budget for category " << category << " not found.\n";
}
//function to set a date range
void TransactionFile::setDateRange(const std::string& startDate, const std::string& endDate) {
    this->startDate = startDate;
    this->endDate = endDate;
}
//function to set a field to sort
void TransactionFile::setSortField(SortField sortField) {
    this->sortField = sortField;
}

void TransactionFile::setFilename(const std::string& filename) {
    this->filename = filename;
}

bool TransactionFile::loadFromFile() {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    // Read data from file and populate transactions

    file.close();
    return true;
}

void TransactionFile::saveToFile() const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Write transactions to file

    file.close();
}
//write budgets to file
void TransactionFile::writeBudgetsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file << "Budgets:" << std::endl;
    for (const auto& budget : budgets) {
        file << "Category: " << budget.category << ", Amount: $" << budget.amount << std::endl;
    }

    file.close();
}

