#include <iostream>
#include <array>
#include <functional>
#include "Board.h"

char getInput();
void displayBoard(const Board& b);

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
	// Check for failed extraction
	if (!std::cin) // If the previous extraction failed
	{
		if (std::cin.eof()) // If the stream was closed
		{
			std::exit(0); // Shut down the program now
		}

		// Let's handle the failure
		std::cin.clear(); // Put us back in 'normal' operation mode
		ignoreLine();     // And remove the bad input

		return true;
	}

	return false;
}



char getInput()
{
	while (true)
	{
		char input{};
		std::cout << "Enter your next action or press 'q' to quit: ";
		std::cin >> input;

		if (clearFailedExtraction())
		{
			std::cout << "Oops, that input is invalid.  Please try again.\n";
			continue;
		}
		ignoreLine(); // Remove any extraneous input
		return input;
	}
}

void playGame()
{
	std::cout << "Welcome to 15 Puzzle Game !\n\n";
	Board b{};
	bool play{ true };
	while (play)
	{
		displayBoard(b);
		char input{ getInput() };
		if (input == 'q')
		{
			play = false;
			continue;
		}

		b.getRelativeZero(input);
		b.swap(input);

		if (b.winCondition())
		{
			play = false;
			continue;
		}
	}
	std::cout << "Thanks for playing !";
}

int main()
{
	Board b{};
	playGame();

	return 0;
}