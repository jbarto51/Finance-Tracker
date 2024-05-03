//import the header file
#include "financialgoal.h"
//setting up FinancialGoal in the class and the variables needed, including the name of the goal, the amount required, and the deadline
FinancialGoal::FinancialGoal(const std::string& name, double targetAmount, const std::string& deadline)
    : name(name), targetAmount(targetAmount), currentAmount(0.0), progress(0.0), deadline(deadline) {}
//return the name of the goal
std::string FinancialGoal::getName() const {
    return name;
}
//return the amount requried for the goal
double FinancialGoal::getTargetAmount() const {
    return targetAmount;
}
//return the the deadline for the goal
std::string FinancialGoal::getDeadline() const {
    return deadline;
}
//return the current amount of money saved for the goal
double FinancialGoal::getCurrentAmount() const {
    return currentAmount;
}
//return the progress the user is at with their goal
double FinancialGoal::getProgress() const {
    return progress;
}
//set the progress percentage complete for the goal
void FinancialGoal::setProgress(double newProgress) {
    // Ensure newProgress is within the range 0 and 1
    if (newProgress >= 0.0 && newProgress <= 1.0) {
        progress = newProgress;
        // Update currentAmount based on progress and targetAmount
        currentAmount = progress * targetAmount;
    }
}



