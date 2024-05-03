#include "financialreport.h"
#include <iostream>

FinancialReport::FinancialReport(TransactionFile& transactionFile) : transactionFile(transactionFile) {
    // Constructor implementation, if needed
}
//the report is generated with the total expenses, total income and is calculated as part of the report depending on the type (positive for income, negative for expense)
void FinancialReport::generateReport() {
    totalExpenses = 0.0;
    totalIncome = 0.0;
    const auto& transactions = transactionFile.getTransactions();
if (!&transactionFile) {
        std::cerr << "Error: TransactionFile pointer is null." << std::endl;
        return;
    }
    // Iterate through transactions in the transaction file
    for (const auto& [id, transaction] : transactions) {
        if (transaction.getType() == TransactionType::Expense) {
            totalExpenses += transaction.getAmount();
        } else if (transaction.getType() == TransactionType::Income) {
            totalIncome += transaction.getAmount();
        }
    }

    // Calculate net profit
    double netProfit = totalIncome - totalExpenses;

    // Output the financial report
    std::cout << "Financial Report:" << std::endl;
    std::cout << "Total Income: $" << totalIncome << std::endl;
    std::cout << "Total Expenses: $" << totalExpenses << std::endl;
    std::cout << "Net Profit: $" << netProfit << std::endl;
}
void FinancialReport::writeReportToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file << "Financial Report:" << std::endl;
    file << "Total Income: $" << totalIncome << std::endl;
    file << "Total Expenses: $" << totalExpenses << std::endl;
    file << "Net Profit: $" << netProfit << std::endl;

    file.close();
}
