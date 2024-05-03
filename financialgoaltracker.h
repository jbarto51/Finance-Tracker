#ifndef FINANCIALGOALTRACKER_H
#define FINANCIALGOALTRACKER_H

#include <vector>
#include <string>
#include "financialgoal.h"  // Include the header where FinancialGoal is defined

class FinancialGoalTracker {
public:
    void addGoal(const FinancialGoal& goal);
    void updateGoalProgress(const std::string& goalName, double amount);
    void displayGoals() const;
    void writeGoalsToFile(const std::string& filename) const;
private:
    std::vector<FinancialGoal> goals;
};

#endif // FINANCIALGOALTRACKER_H

