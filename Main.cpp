#include "WarGame.h"

void main()
{
	WarGame* newWarGame = new WarGame();
	bool continuePlaying = true;
	std::string answer;

	std::cout << "Welcome to the all new improved War Game!" << std::endl;
	std::cout << "Unlike the original game, here you get to pick 4 cards, see their contents and choose the order in which to play them. \n You and your opponent will then engage in individual battles based on the order in which you chose the cards.\n The winner of each battle takes both cards and puts them in his discard pile. \n When your hand has less than 4 cards, your discard pile will be mixed with your hand and you will be able to play with those. \n The game finishes when one player has less than 4 cards in his main hand and discard pile combined. \n Occasionally, a Royale Round will be initiated.\n Just as in a regular round, in Royale Round you get to pick the order in which to play 4 cards. Instead of taking the cards of each battle won, the player who won most of those 4 battles will take all the cards.\n Meaning if you win 3 out of the 4 battles, you get to take all 8 cards and put them in the discard pile." << std::endl;

	while (continuePlaying == true)
	{
		newWarGame->FullGame();
		for (;;) {
			std::cin.clear();
			std::cout << "Play a new game?" << std::endl;
			std::cin >> answer;

			if (!answer.compare("Yes") || !answer.compare("yes")) {
				break;
			}

			if (!answer.compare("No") || !answer.compare("no")) {
				continuePlaying = false;
				break;
			}

			else {
				std::cout << "Please enter a valid answer.\n";
			}

		}
	}
	std::cout << "Goodbye!" << std::endl;
}