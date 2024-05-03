//define the header file and header files needed
#ifndef FINANCIALREPORT_H
#define FINANCIALREPORT_H
#include <iostream>
#include <fstream>
#include "transactionfile.h"

class FinancialReport {
public:
    // Constructor for the financial report
    FinancialReport(TransactionFile& transactionFile);

    // Function to generate a financial report is called
    void generateReport();
    void writeReportToFile(const std::string& filename)const;
// transaction file is referenced
private:
    TransactionFile& transactionFile;
    double totalIncome;
    double totalExpenses;
    double netProfit;
};

#endif

