//include all header files 
#include <iostream>
#include "transaction.h"
#include "transactionfile.h"
#include "financialgoal.h"
#include "financialgoaltracker.h"
#include "financialreport.h"
int main() {

    TransactionFile transactionFile("transactions.txt");
	//intialize variables and text file if needed
    
     int choice;
     int id;
     FinancialGoalTracker goalTracker;
     FinancialReport report(transactionFile);
     //menu for choices for the menu
     do {
        std::cout << "\nFinance Tracker Menu:\n";
        std::cout << "1. Add Transaction\n";
        std::cout << "2. View All Transactions\n";
        std::cout << "3. Generate Financial Report\n";
	std::cout << "4. Delete a Transaction\n";
	std::cout << "5. Update a Transaction\n";
	std::cout << "6. Search for a Transaction by Category\n";
	std::cout << "7. Add Budget\n";
	std::cout << "8. Display Budgets\n";
	std::cout << "9. Add Financial Goal\n";
        std::cout << "10. Update Financial Goal Progress\n";
        std::cout << "11. Display Financial Goals\n";
	std::cout << "12. Exit\n";
        std::cout << "Enter your choice (1-12): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
		// the user can add a transaction here with an ID, amount, category, description, and type of transaction which is added to the file/report
	        double amount;
                std::string category;
                std::string description;
		int typeInt;

		std::cout << "Enter transaction ID: ";
		std::cin >> id;
                std::cout << "Enter transaction amount: ";
                std::cin >> amount;
                std::cout << "Enter transaction category: ";
                std::cin >> category;
                std::cout << "Enter transaction description: ";
		std::cin.ignore(); // Ignore newline character from previous input
		std::getline(std::cin, description);
		std::cout << "Enter transaction type (0 for Expense, 1 for Income: ";
		std::cin >> typeInt;

		TransactionType type = static_cast<TransactionType>(typeInt);

                Transaction transaction(id, amount, category, description, type);
                transactionFile.add(transaction);

                std::cout << "Transaction added successfully.\n";
                break;
            }
	// all transactions are displayed
            case 2: {
                transactionFile.displayAll();
                break;
            }
	// financial report is generated
            case 3: {
                report.generateReport();
		report.writeReportToFile("financial_report.txt");
                break;
            }
	// user can delete a transaction by inputting its id
            case 4: {
    		//int deleteId;
    		std::cout << "Enter the ID of the transaction you want to delete: ";
    		std::cin >> id;
    		transactionFile.deleteTransaction(id);
    		break;
	}
	// user can update a transaction they added already by id with new information
	    case 5: {
    		int updateId;
   	 	std::cout << "Enter the ID of the transaction you want to update: ";
    		std::cin >> updateId;
     // Get new details for the updated transaction
    		double newAmount;
    		std::string newCategory;
    		std::string newDescription;
    		int newTypeInt;

    		std::cout << "Enter new transaction amount: ";
    		std::cin >> newAmount;
    		std::cout << "Enter new transaction category: ";
    		std::cin >> newCategory;
    		std::cout << "Enter new transaction description: ";
    		std::cin.ignore(); // Ignore newline character from previous input
    		std::getline(std::cin, newDescription); //get line based on new description
    		std::cout << "Enter new transaction type (0 for Expense, 1 for Income): ";
    		std::cin >> newTypeInt;

    		TransactionType newType = static_cast<TransactionType>(newTypeInt);

    // Create a new Transaction object with the updated details
    		Transaction updatedTransaction(updateId, newAmount, newCategory, newDescription, newType);

    // Call the update method in TransactionFile to update the transaction
    		transactionFile.update(updateId, updatedTransaction);
    		break;
	}
	//search for all transactions by their category
	case 6: {
    		std::string searchCategory;
    		std::cout << "Enter the category to search for: ";
    		std::cin >> searchCategory;

    // Call the searchByCategory method in TransactionFile to get matching transactions
    		std::vector<Transaction> searchResults = transactionFile.searchByCategory(searchCategory);

    // Display the search results
    		for (const auto& result : searchResults) {
        		std::cout << "Transaction ID: " << result.getId() << std::endl;
        		std::cout << "Amount: $" << result.getAmount() << std::endl;
        		std::cout << "Category: " << result.getCategory() << std::endl;
        		std::cout << "Description: " << result.getDescription() << std::endl;
        		std::cout << "--------------------------" << std::endl;
    		}
    		break;
	}
	//Add a budget with category and amount
	case 7: {
    // Add budget functionality
    		Budget newBudget;
    		std::cout << "Enter budget category: ";
    		std::cin >> newBudget.category;
    		std::cout << "Enter budget amount: ";
    		std::cin >> newBudget.amount;

    		transactionFile.addBudget(newBudget);
    		std::cout << "Budget added successfully.\n";
    		break;
	}
	//display all budgets the user created
	case 8: {
    		transactionFile.displayBudgets();
		transactionFile.writeBudgetsToFile("budgets.txt");
    		break;
	}
	//add a finacial goal with a name, amount, and deadline
	case 9: {
                
                std::string name;
                double targetAmount;
                std::string deadline;

                std::cout << "Enter goal name: ";
                std::cin.ignore(); // Ignore newline character from previous input
                std::getline(std::cin, name);
                std::cout << "Enter target amount: ";
                std::cin >> targetAmount;
                std::cout << "Enter deadline (MM-DD-YYYY): ";
                std::cin.ignore(); // Ignore newline character from previous input
                std::getline(std::cin, deadline); //get line from deadline string

                FinancialGoal goal(name, targetAmount, deadline);
                goalTracker.addGoal(goal);
                std::cout << "Financial goal added successfully.\n";
                break;
            }
        //update the progress of the financial goal
	case 10: {
                
                std::string goalName;
                double progressAmount;

                std::cout << "Enter goal name to update progress: ";
                std::cin.ignore(); // Ignore newline character from previous input
                std::getline(std::cin, goalName); //getline from goal name
                std::cout << "Enter progress amount (as decimal amount like 0.4 for 40%): ";
                std::cin >> progressAmount;
		
                if (progressAmount >= 0.0 && progressAmount <= 1.0) {
        		goalTracker.updateGoalProgress(goalName, progressAmount);
    		} else {
        		std::cout << "Invalid progress amount. Please enter a decimal between 0 and 1." << std::endl;
    		}
                break;
            }
        //display all financial goals
	case 11: {
                // Display Financial Goals
                goalTracker.displayGoals();
		goalTracker.writeGoalsToFile("financial_goals.txt");
                break;
		 }
	//exit program (if number inputted is not between 1 and 12, the user is told the choice is invalid)
	case 12: {
		std::cout << "Exiting program.\n";
        	break;
        	}
		default:
		std::cout << "Invalid choice. Please enter a number between 1 and 12.\n";
        	}
    	} while (choice != 12);

    	return 0;
}

