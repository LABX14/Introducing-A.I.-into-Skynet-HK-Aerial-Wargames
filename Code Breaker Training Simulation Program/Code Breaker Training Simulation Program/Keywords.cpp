/* 
Kaulana Lee
10/17/20
Assignment: Keywords - Building Code Breaker Training Simulation Program for CIA Recruits
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool repeat = true;
char input; 

int main()
{
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"Kaulana", "Project Lead and Design Lead for Escape Room AR"},
        {"Darin", "Programming Lead for Escape Room AR"},
        {"Jake", "Scrum Master for Escape Room AR"},
        {"Raul", "Artist and Designer on Escape Room AR"},
        {"Vanessa", "Designer and Programmer on Escape Room AR"},
        {"Quentin", "Designer on Escape Room AR"},
        {"Lyndsey", "Art Lead on Escape Room AR"},
        {"Alina", "Artist on Escape Room AR"},
        {"Takota", "Programmer on Escape Room AR"},
        {"William", "Master's student on Escape Room AR"}
    };

    while (repeat) {
        srand(static_cast<unsigned int>(time(0)));
        int attempts = 1;
        int hintsUsed = 0;
        int wordList = 3;
        int endAttempts;
        string playerGuess;

        cout << "Welcome to Escape Room AR Name Jumble \n";
        cout << "Figure out who it is.\n";
        cout << "Enter 'hint' for a hint.\n";
        cout << "Enter 'quit' to quit the game.\n";

        for (int k = 0; k < wordList; ++k) {
            //This will pick a random name and hint from the list
            int choice = (rand() % NUM_WORDS);
            int nameNumber = k + 1;
            string word = WORDS[choice][WORD];
            string hint = WORDS[choice][HINT];

            //This will mix up the chosen word
            string jumble = word;
            int length = jumble.size();
            for (int i = 0; i < length; ++i)
            {
                int index1 = (rand() % length);
                int index2 = (rand() % length);
                char temp = jumble[index1];
                jumble[index1] = jumble[index2];
                jumble[index2] = temp;
            }

            cout << "\nName Number " << nameNumber << ": " << jumble;
            cout << "\nAttempt " << attempts << ": ";

            //This will tell the player the number of attempts they took
            cin >> playerGuess;
            ++attempts;

            while (playerGuess != word) {
                //This will give the hint to the player
                if (playerGuess == "hint") {
                    cout << "\nHere's a hint for that name, the role that person has on the team." << endl;
                    cout << hint;
                    ++hintsUsed;

                    cout << "\nWhat is your new guess?";
                    cout << "\nAttempt Number " << attempts << ": ";
                    cin >> playerGuess;
                }

                // This will quit the word jumble 
                else if (playerGuess == "quit")
                {
                    k = wordList;
                    break;
                }

                else 
                {
                    cout << "\n\nThat isn't right way to spell that person's name.";
                    cout << "\nPlease try again.";
                    cout << "\nAttempt " << attempts << ": ";
                    cin >> playerGuess;
                    ++attempts;
                }
            }

            if (playerGuess == word)
            {
                cout << "\nThat's right!. On to the next name.";
            }
        }

        endAttempts = attempts - 1;

        if (playerGuess == "quit")
        {
            cout << "\nYou chose to quit this round.";
            cout << "\nIf you want to start over with a new set of names, enter 'Y'.";
            cout << "\nOtherwise enter 'N' to fully quit the game.  Your Choice: ";
            cin >> input;
        }

        else
        {
            cout << "\nCongratulations! You unscrambled each name!";
            cout << "\nIt took you " << endAttempts << " attempts to solve them.";
            cout << "\nWould you like to play again? Enter Y/N: ";
            cin >> input;
        }

        // This will quit the game
        if (input != 'Y') 
        {
            repeat = false;
        }
    }

    return 0;
}