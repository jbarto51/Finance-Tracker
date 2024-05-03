//include the header file for the class and the other headers needed for the functions
#include "financialgoaltracker.h"
#include <vector>
#include <string>  
#include <iostream>
#include <fstream>
//function to add a financial goal
void FinancialGoalTracker::addGoal(const FinancialGoal& goal) {
    goals.push_back(goal);
}
// function to update goalprogress and set a new amount
void FinancialGoalTracker::updateGoalProgress(const std::string& goalName, double amount) {
    for (auto& goal : goals) {
        if (goal.getName() == goalName) {
            goal.setProgress(amount);
            break;
        }
    }
}
//function to display all goals defined by the user with the goal name, target amount, deadline to completion, current amount, and current progress as a percentage
void FinancialGoalTracker::displayGoals() const {
    for (const auto& goal : goals) {
        std::cout << "Goal Name: " << goal.getName() << std::endl;
        std::cout << "Target Amount: $" << goal.getTargetAmount() << std::endl;
        std::cout << "Deadline: " << goal.getDeadline() << std::endl;
        std::cout << "Current Amount: $" << goal.getCurrentAmount() << std::endl;
        std::cout << "Progress: " << goal.getProgress() * 100 << "% completed" << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}
void FinancialGoalTracker::writeGoalsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& goal : goals) {
        file << "Goal Name: " << goal.getName() << std::endl;
        file << "Target Amount: $" << goal.getTargetAmount() << std::endl;
        file << "Deadline: " << goal.getDeadline() << std::endl;
        file << "Current Amount: $" << goal.getCurrentAmount() << std::endl;
        file << "Progress: " << goal.getProgress() * 100 << "% completed" << std::endl;
        file << "--------------------------" << std::endl;
    }

    file.close();
}

