// This program simulates rolling dice.
#include <iostream>
#include <cstdlib>     
#include <ctime>       
using namespace std;

int main()
{
	// Constants
	const int MIN_VALUE = 1;   // Minimum die value
	const int MAX_VALUE = 9;   // Maximum die value
	const int ARRAY_SIZE = 5;



	// Variables
	int matches[5]{};// To count the matching digits 
	int count = 0; // To count the number of times the loop is executed
	int lottery[ARRAY_SIZE]{};
	int user[ARRAY_SIZE]{};
	bool foundMatch = false;

	// Get the system time.
	unsigned seed = time(0); //  Ensures that the random number generator produces different random numbers each time the program is run

	// Seed the random number generator.
	srand(seed); // regenterates random numbers each time the code is run







	// Get the user input
	cout << "Enter 5 numbers between 0-9 for your lottery ticket: (separated by spaces): ";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cin >> user[i];
	}
		cout << endl;
	// Generate the random numbers
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
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



	//Check for matching digits
	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int j = 0; j < ARRAY_SIZE; j++) {
			if (lottery[i] == user[j]) {
				matches[count] = lottery[i];
				count++;
				foundMatch = true;
			


				
			}
		}
	}
	cout << endl;

	// Output matching digits

	cout << "Matching numbers (if any): ";
	for (int i = 0; i < count; i++) {
		cout << matches[i] << " ";
	}

	cout << endl;

	// Output the message based on the number of matches
	if (count == 5) {
		cout << "You got 5 matches: You won the jackpot!";
	}
	else if (count == 4) {
		cout << "You got 4 matches: You won $10,000!";
	}
	else if (count == 3) {
		cout << "You got 3 matches: You won $100!";
	}
	else if (count == 2) {
		cout << "You got 2 matches: You won $10!";
	}
	else if (count == 1) {
		cout << "You got 1 match: You won $1!";
	}
	else {
		cout << "You got no matches. You did not win anything. Better luck next time!";
	}
	
return 0;


}
