/* 
	Kaulana Lee
	10-5-20 
	Skynet Wargames Assignment: This is supposed to detect a number's location on a grid and there are differnt functions that 
	the player can use to find the number's location 
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

// These are the Preprocessors Directives
using std::cout;
using std::endl;
using std::cin;

bool again = true;
char runAgain;

int main()
{
	while (again)
	{
		srand(static_cast<unsigned int>(time(0)));//seed random number generator
		int EnemyLocation = rand() % 64 + 1;

		int searchHigh = 64; // SearchHigh will be set to 64
		int searchLow = 1; // SearchLow will be set to 1

		int guess = (searchHigh - searchLow) / 2 + searchLow; //This is the equation for the guess

		int tries = 1; //This determine the number of tries you have

		int linearGuess = 1; // This starts the linear search at the beginning of the grid
		int linearTries = 1; // This counts how many times it tried the linear 
		int linearTriesEnd; // This stores the final correct linear search

		int randomGuess = rand() % 64 + 1; // This starts the random search
		int randomTries = 1; // This counts how many times it tried the random

		int inputGuess; // This starts the search when the player inputs a number
		int inputTries = 1; // This counts how many times the player guessed

		cout << "Belcome Bo Bynet" << endl;
		cout << "Barting Bearch Bof 8 by 8 Brid." << endl;
		cout << "Right location: " << EnemyLocation << endl;
		cout << "------------------------------" << endl;

		cout << "User input based search." << endl;
		cout << "Please input a prediction for enemy location (a number 1-64)." << endl;
		cout << "Your predictions: ";
		cin >> inputGuess;
		cout << "------------------------" << endl;

		// This is the user input search
		while (inputGuess != EnemyLocation)
		{
			cout << "Your prediction: " << inputGuess << endl;
			cout << "But the enemy was not located there." << endl;
			cout << "Please input a new prediction for enemy location (a number 1-64)" << endl;
			cin >> inputGuess;

			++inputTries;
			cout << "-------------------" << endl;
		} 


		// This is the random search
		do
		{
			randomGuess = rand() % 64 + 1;
			++randomTries;
		} while (randomGuess != EnemyLocation);

		// This is the Linear Search
		for (linearGuess; linearGuess < 65; ++linearGuess)
		{
			if (linearGuess == EnemyLocation)
			{
				linearTriesEnd = linearTries;
			}

			++linearTries;
		}

		// This is the Binary Search
		do {
			if (guess < EnemyLocation)
			{
				searchLow = guess + 1; // This adds 1 to your guess
				guess = (searchHigh - searchLow) / 2 + searchLow; // This makes a new low by cutting it in half
				++tries;
			}

			else
			{
				searchHigh = guess - 1; // This minuses 1 from your guess
				guess = (searchHigh - searchLow) / 2 + searchLow; //This makes a new high by cutting it in half 
				++tries;
			}
		} while (guess != EnemyLocation);

		cout << "Search complete." << endl;
		cout << "Enemy found at position " << EnemyLocation << "." << endl;
		cout << "Binary search took " << tries << " preditctions to find enemy." << endl;

		cout << "Linear search took " << linearTriesEnd << " predictions to find enemy." << endl;

		cout << "Random search took " << randomTries << " predictions to find the enemy." << endl;

		cout << "User input search took " << inputTries << " predictions to find the enemy." << endl;

		// Asking the player if they want to run the code again
		cout << "------------------------" << endl;
		cout << "Would you like to run this program again? (Y/N) " << endl;
		cin >> runAgain;
		cout << "------------------------" << endl;

		// This will not run the program again if you tell it anything other than 'Y'
		if (runAgain != 'Y')
		{
			again = false;
		}
	}

	return 0;
}