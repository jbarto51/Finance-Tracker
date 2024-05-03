//define header file and include headers needed for functions
#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

#include <map>
#include <string>
#include <vector>
#include "transaction.h"
#include <iostream>
//define budget structure with category and amount
struct Budget {
    std::string category;
    double amount;
};
class TransactionFile {
private:
//private variables are defined
    std::map<int, Transaction> transactions;
    std::string filename;
    int lastId;
    std::vector<Budget> budgets;
    std::string startDate;
    std::string endDate;
    enum class SortField { ID, Amount, Date };
    SortField sortField;
public:
//public functions, including getters and setters are set up
    TransactionFile(const std::string& filename);
    bool exists() const;
    void add(Transaction& transaction);
    void save() const;
    std::vector<int> search(const std::string& query) const;
    void generateFinancialReport() const;
    void deleteTransaction(int id);
    const std::map<int, Transaction>& getTransactions() const;
    void addBudget(const Budget& budget);
    void updateBudget(const std::string& category, double newAmount);
    double getTotalBudget() const;
    void displayBudgets() const;
    void update(int id, const Transaction& newTransaction);
    std::vector<Transaction> searchByCategory(const std::string& category) const;
    void setDateRange(const std::string& startDate, const std::string& endDate);
    void setSortField(SortField sortField);
    void displayAll() const;
    void setFilename(const std::string& filename);
    bool loadFromFile();
    void saveToFile() const;
    void writeBudgetsToFile(const std::string& filename) const;
};

#endif

