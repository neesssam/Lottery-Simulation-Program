// This program simulates rolling dice.
#include <iostream>
#include <cstdlib>     
#include <ctime>       
using namespace std;

// Function to generate random numbers
void generateNumbers(int lottery[], int user[], int ARRAY_SIZE, int MIN_VALUE, int MAX_VALUE) {

	// Get the user input
	cout << "Enter " << ARRAY_SIZE << " numbers between " << MIN_VALUE << "-" << MAX_VALUE << " for your lottery ticket (separated by spaces): ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cin >> user[i];
		//check for invalid input
		if (user[i] < MIN_VALUE || user[i] > MAX_VALUE) {
			cout << "Invalid input. Please enter a number between " << MIN_VALUE << "-" << MAX_VALUE << endl;
			cin >> user[i];
		}
	}
	cout << endl;

	// Generate the random numbers
	for (int i = 0; i < ARRAY_SIZE; i++) {
		lottery[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	}

	// Display the lottery and user numbers
	cout << "Lottery numbers: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << lottery[i] << " ";
	}
	cout << endl;

	cout << "User numbers: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << user[i] << " ";
	}
	cout << endl;
}

// Function to check lottery results and output message 
void checkLotteryResults(int count) {
	switch (count) {
	case 5:
		cout << "You got 5 matches: You won the jackpot!";
		break;
	case 4:
		cout << "You got 4 matches: You won $10,000!";
		break;
	case 3:
		cout << "You got 3 matches: You won $100!";
		break;
	case 2:
		cout << "You got 2 matches: You won $10!";
		break;
	case 1:
		cout << "You got 1 match: You won $1!";
		break;
	default:	
		cout << "You got no matches. You did not win anything. Better luck next time!";
		break;
	}
}

// Function to check for matching digits
void checkMatchingDigits(int lottery[], int user[], int ARRAY_SIZE, int matches[], int& count, bool& foundMatch) {
	// Check for matching digits
	for (int i = 0; i < ARRAY_SIZE; i++) {
		foundMatch = false;
		for (int j = 0; j < ARRAY_SIZE; j++) {
			if (lottery[i] == user[j] && !foundMatch) {
				matches[count] = lottery[i];
				count++;
				foundMatch = true;
			}
		}
	}
}

// function to output matching digits
void outputMatchingDigits(int user[], int matches[], int ARRAY_SIZE, int count) {
	cout << "Matching numbers (if any): ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		bool isMatch = false;
		for (int j = 0; j < count; j++) {
			if (user[i] == matches[j]) {
				isMatch = true;
				break;
			}
		}
		if (isMatch) {
			cout << user[i] << " ";
		}
		else {
			cout << "X ";
		}
	}
	cout << endl;	
}


int main()
{
	// Constants
	const int MIN_VALUE = 1;   // Minimum die value
	const int MAX_VALUE = 9;   // Maximum die value
	const int ARRAY_SIZE = 5;

	// Variables
	int matches[5]{}; // To count the matching digits
	int count = 0; // To count the number of times the loop is executed
	int lottery[ARRAY_SIZE]{};
	int user[ARRAY_SIZE]{};
	bool foundMatch = false;

	// Get the system time.
	unsigned seed = time(0); //  Ensures that the random number generator produces different random numbers each time the program is run

	// Seed the random number generator.
	srand(seed); // regenerates random numbers each time the code is run

	// Call the functions
	generateNumbers(lottery, user, ARRAY_SIZE, MIN_VALUE, MAX_VALUE);
	checkMatchingDigits(lottery, user, ARRAY_SIZE, matches, count, foundMatch);
	outputMatchingDigits(user, matches, ARRAY_SIZE, count);
	checkLotteryResults(count);

	return 0;
}
