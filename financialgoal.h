//initialize the class header file
#ifndef FINANCIALGOAL_H
#define FINANCIALGOAL_H
#include <string>
class FinancialGoal {
//define private variables for the name, target and current amounts, progress, and the deadline for the goal
private:
    std::string name;
    double targetAmount;
    double currentAmount;
    double progress;
    std::string deadline;
//define the public functions used in the class, including the getters and setters
public:
    std::string getName() const;
    double getTargetAmount() const;
    std::string getDeadline() const;
    double getCurrentAmount() const;
    double getProgress() const;
    FinancialGoal(const std::string& name = "", double targetAmount = 0.0, const std::string& deadline = "");
    void setProgress(double newProgress);
    bool isCompleted() const;
    
};
#endif
