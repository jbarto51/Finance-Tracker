#initializing compiling with the correct standard and for debugging
CXXFLAGS = -Wall -g -std=c++17

#compile all files into finance_tracker
all: finance_tracker

# Compile main.o from main.cpp
main.o: main.cpp transaction.h transactionfile.h financialreport.h financialgoaltracker.h financialgoal.h
	g++ $(CXXFLAGS) -c main.cpp -o main.o

# Compile transaction.o from transaction.cpp
transaction.o: transaction.cpp transaction.h
	g++ $(CXXFLAGS) -c transaction.cpp -o transaction.o

# Compile transactionfile.o from transactionfile.cpp
transactionfile.o: transactionfile.cpp transactionfile.h transaction.h
	g++ $(CXXFLAGS) -c transactionfile.cpp -o transactionfile.o

# Compile financialreport.o from financialreport.cpp
financialreport.o: financialreport.cpp financialreport.h transactionfile.h
	g++ $(CXXFLAGS) -c financialreport.cpp -o financialreport.o

# Compile financialgoal.o from financialgoal.cpp
financialgoal.o: financialgoal.cpp financialgoal.h
	g++ $(CXXFLAGS) -c financialgoal.cpp -o financialgoal.o

# Compile financialgoaltracker.o from financialgoaltracker.cpp
financialgoaltracker.o: financialgoaltracker.cpp financialgoaltracker.h financialgoal.h
	g++ $(CXXFLAGS) -c financialgoaltracker.cpp -o financialgoaltracker.o

# Link object files to create the executable finance_tracker
finance_tracker: main.o transaction.o transactionfile.o financialreport.o financialgoal.o financialgoaltracker.o
	g++ $(CXXFLAGS) main.o transaction.o transactionfile.o financialreport.o financialgoal.o financialgoaltracker.o -o finance_tracker

# clean to remove .o files to recompile the code

clean:
	rm -f *.o finance_tracker

