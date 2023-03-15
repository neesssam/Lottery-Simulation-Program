# Lottery Simulation Program

This is a C++ program that simulates rolling dice for a lottery game. The program prompts the user to enter 5 numbers between 0 and 9 for their lottery ticket. It then generates 5 random numbers between 1 and 9 for the lottery. The program checks if any of the user's numbers match any of the lottery numbers and outputs the number of matches. It then outputs a message based on the number of matches.

The program uses the constants MIN_VALUE and MAX_VALUE to specify the minimum and maximum die values. It also uses the ARRAY_SIZE constant to specify the size of the arrays for the lottery numbers, user numbers, and matches. The program initializes the matches array to all zeros and uses the count variable to keep track of the number of matches.

The program uses the time() function to get the current system time and uses it to seed the random number generator with srand(). The program then uses rand() to generate random numbers between the minimum and maximum values for the lottery numbers.

The program uses nested for loops to check if any of the lottery numbers match any of the user numbers. If a match is found, the lottery number is added to the matches array and the count variable is incremented. The program uses a foundMatch boolean variable to keep track of whether any matches were found.

The program then outputs the matching numbers and a message based on the number of matches using if-else statements.

Overall, this program is a simple simulation of a lottery game and can be used as a starting point for more complex lottery simulations.
