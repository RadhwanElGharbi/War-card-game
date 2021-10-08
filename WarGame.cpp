#include <map>
#include <time.h>
#include "WarGame.h"
#include "RPSGame.h"

WarGame::WarGame()
{}

WarGame::~WarGame()
{}

void WarGame::Deck52Fill()
{
	suit = {"Spades", "Hearts", "Diamonds", "Clubs"}; //define the contents of suit
	cardTitle = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"}; // define the card titles
	for (int iterator = 1; iterator < 53; iterator++) //fills deck52 vector
	{
		deck52.push_back(iterator);
	}

	int cards_Iterator = 0;
	for (int iterator = 0; iterator < 13; iterator++)
	{
		for (int iterator2 = 0; iterator2 < 4; iterator2++) //Each rank is given a set of 4 suits and inserted into the map with the appropriate integer value
		{
			card = cardTitle[iterator] + " of " + suit[iterator2];
			cards.insert(make_pair(deck52[cards_Iterator], card));
			if (cards_Iterator < deck52.size()) //prevents from exceeding the range of deck52
			{
				cards_Iterator++;
			}
		}
	}

	//-------------- TEST - START --------------//
	/*for (const auto& elem : cards) //elements in cards are appropriate
	{
		std::cout << elem.first << " " << elem.second << std::endl;
	}*/
	//-------------- TEST - END --------------//
}

void WarGame::Shuffle_and_distribute()
{
	srand(time(0));
	int randomShuffle = rand() % 52 + 1;
	std::vector<int> randExclusions;
	randExclusions.clear();

	while (player1.size() < 26) //distribute cards randomly to player1
	{
		if(std::find(randExclusions.begin(), randExclusions.end(), randomShuffle) != randExclusions.end()) //check if card has already been picked out
		{}
		else
		{
			player1.push_back(randomShuffle);
			randExclusions.push_back(randomShuffle);
		}
		randomShuffle = rand() % 52 + 1;
	}

	while (player2.size() < 26) //distribute cards randomly to player2
	{
		if (std::find(randExclusions.begin(), randExclusions.end(), randomShuffle) != randExclusions.end()) //check if card has already been picked out from the deck
		{}
		else
		{
			player2.push_back(randomShuffle);
			randExclusions.push_back(randomShuffle);
		}
		randomShuffle = rand() % 52 + 1;
	}

	//-------------- TEST - START --------------//
	/*for (const auto& elem : player1)
	{
		std::cout << elem << " " << player1.size() << std::endl;
	}

	for (const auto& elem : player2)
	{
		std::cout << elem << " " << player2.size() << std::endl;
	}*/
	//-------------- TEST - START --------------//
	randExclusions.clear();
}

void WarGame::PickFour()
{
	srand(time(0));
	int randomPick1 = rand() % (player1.size() - 1);
	int randomPick2 = rand() % (player2.size() - 1);
	int temp_pick;
	while (player1_hand.size() < 4) //4 cards shift from the pile to the hand for both players
	{
		temp_pick = player1[randomPick1];
		player1.erase(player1.begin() + randomPick1);
		player1_hand.push_back(temp_pick);
		
		if ((player1.size()-1) == 0)
		{
			randomPick1 = 0;
		}
		else
		{
			randomPick1 = rand() % (player1.size() - 1);
		}
	}

	while (player2_hand.size() < 4)
	{
		temp_pick = player2[randomPick2];
		player2.erase(player2.begin() + randomPick2);
		player2_hand.push_back(temp_pick);

		if ((player2.size()-1) == 0)
		{
			randomPick2 = 0;
		}
		else
		{
			randomPick2 = rand() % (player2.size() - 1);
		}
	}

	//-------------- TEST - START --------------//
	
	/*for (const auto& elem : player1_hand)
	{
		std::cout << elem << " " << player1_hand.size() << std::endl;
	}

	for (const auto& elem : player2_hand)
	{
		std::cout << elem << " " << player2_hand.size() << std::endl;
	}

	for (const auto& elem : player1_hand)
	{
		std::cout << "DOWN DOWN DOWN" <<cards[elem] << std::endl;
		std::cout << elem << std::endl;
	}

	for (const auto& elem : player2_hand)
	{
		std::cout << "DOWN DOWN DOWN" << cards[elem] << std::endl;
		std::cout << elem << std::endl;
	}*/
	//-------------- TEST - END --------------//
}

void WarGame::DisplayHandP1()
{
	int assignedID = 0;

	std::cout << "\nPlayer 1. Your hand contains the following cards:" << std::endl;
	for (const auto& elem : player1_hand)
	{
		std::cout << cards[elem] << " ID " << "[" << assignedID << "]" << std::endl;
		assignedID++;
	}
}

void WarGame::DisplayHandP2()
{
	int assignedID = 0;

	std::cout << "\nPlayer 2. Your hand contains the following cards:" << std::endl;
	for (const auto& elem : player2_hand)
	{
		std::cout << cards[elem] << " ID " << "[" << assignedID << "]" << std::endl;
		assignedID++;
	}
}

void WarGame::HandChoiceP1()
{
	DisplayHandP1();
	std::vector<int> tempVec; //create temporary vector
	int tempint0, tempint1, tempint2, tempint3; //create temporary integers

	std::cout << "\nChoose the order in which to play them:" << std::endl;
	std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3; //prompt user to input choices

	if (tempint0 > 3 || tempint1 > 3 || tempint2 > 3 || tempint3 > 3 || tempint0 < 0 || tempint1 < 0 || tempint2 < 0 || tempint3 < 0)
	{
		std::cout << "\nYou entered a number outside the range! Please try again:" << "\n" << std::endl;
		DisplayHandP1();
		std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3;
	}

	tempVec.push_back(player1_hand[tempint0]); //fill tempVec with the values in the corresponding index of the player's hand
	tempVec.push_back(player1_hand[tempint1]); 
	tempVec.push_back(player1_hand[tempint2]); 
	tempVec.push_back(player1_hand[tempint3]); 

	while (FindVecDuplicate(tempVec)) //while duplicates exist prompt user repeatedly
	{
		tempVec.clear();
		std::cout << "\nYou entered a duplicate number! Try again: " << "\n" << std::endl;
		DisplayHandP1();
		std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3;
		while (tempint0 > 3 || tempint1 > 3 || tempint2 > 3 || tempint3 > 3 || tempint0 < 0 || tempint1 < 0 || tempint2 < 0 || tempint3 < 0)
		{
			std::cout << "\nYou entered a number outside the range! Please try again:" << "\n" << std::endl;
			DisplayHandP1();
			std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3;
		}
		tempVec.push_back(player1_hand[tempint0]); //fill tempVec with the values in the corresponding index of the player's hand
		tempVec.push_back(player1_hand[tempint1]);
		tempVec.push_back(player1_hand[tempint2]);
		tempVec.push_back(player1_hand[tempint3]);
	}

	player1_hand.clear(); //clear original vector

	player1_hand.push_back(tempVec[0]); //fill original vector with the new ordered values
	player1_hand.push_back(tempVec[1]);
	player1_hand.push_back(tempVec[2]);
	player1_hand.push_back(tempVec[3]);

	tempVec.clear(); //reset tempVec for future iterations

	//-------------- TEST - START --------------//
	/*for (const auto& elem : player1_hand)
	{
		std::cout << cards[elem] << std::endl;
	}*/
	//-------------- TEST - END --------------//
}

void WarGame::HandChoiceP2()
{
	DisplayHandP2();
	std::vector<int> tempVec; //create temporary vector
	int tempint0, tempint1, tempint2, tempint3; //create temporary integers

	std::cout << "\nChoose the order in which to play them:" << std::endl;
	std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3; //prompt user to input choices
	
	while (tempint0 > 3 || tempint1 > 3 || tempint2 > 3 || tempint3 > 3 || tempint0 < 0 || tempint1 < 0 || tempint2 < 0 || tempint3 < 0)
	{
		std::cout << "\nYou entered a number outside the range! Please try again:" << "\n" << std::endl;
		DisplayHandP2();
		std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3;
	}



	tempVec.push_back(player2_hand[tempint0]); //fill tempVec with the values in the corresponding index of the player's hand
	tempVec.push_back(player2_hand[tempint1]);
	tempVec.push_back(player2_hand[tempint2]);
	tempVec.push_back(player2_hand[tempint3]);

	while (FindVecDuplicate(tempVec)) //while duplicates exist prompt user repeatedly
	{
		tempVec.clear();
		std::cout << "\nYou entered a duplicate number! Try again: " << "\n" << std::endl;
		DisplayHandP2();
		std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3;
		while (tempint0 > 3 || tempint1 > 3 || tempint2 > 3 || tempint3 > 3 || tempint0 < 0 || tempint1 < 0 || tempint2 < 0 || tempint3 < 0)
		{
			std::cout << "\nYou entered a number outside the range! Please try again:" << "\n" << std::endl;
			DisplayHandP2();
			std::cin >> tempint0 >> tempint1 >> tempint2 >> tempint3;
		}
		tempVec.push_back(player2_hand[tempint0]); //fill tempVec with the values in the corresponding index of the player's hand
		tempVec.push_back(player2_hand[tempint1]);
		tempVec.push_back(player2_hand[tempint2]);
		tempVec.push_back(player2_hand[tempint3]);
	}

	player2_hand.clear(); //clear original vector

	player2_hand.push_back(tempVec[0]); //fill original vector with the new ordered values
	player2_hand.push_back(tempVec[1]);
	player2_hand.push_back(tempVec[2]);
	player2_hand.push_back(tempVec[3]);

	tempVec.clear(); //reset tempVec for future iterations

	//-------------- TEST - START --------------//
	/*for (const auto& elem : player2_hand)
	{
		std::cout << cards[elem] << std::endl;
	}*/
	//-------------- TEST - END --------------//
}

bool WarGame::FindVecDuplicate(std::vector<int> vectur)
{
	bool isDuplicate = false;

	// Create a map to store the frequency of each element in vector
	std::map<int, int> countMap;
	// Iterate over the vector and store the frequency of each element in map
	for (auto& elem : vectur)
	{
		auto result = countMap.insert(std::pair<int, int>(elem, 1));
		if (result.second == false)
			result.first->second++;
	}

	for (auto& elem : countMap)
	{
		// If frequency count is greater than 1 then its a duplicate element
		if (elem.second > 1)
		{
			isDuplicate = true;
			break;
		}
	}
	countMap.clear();

	return isDuplicate;
}

void WarGame::CompareAndWinner()
{
	for (int iterator = 0; iterator < 4; iterator++)
	{
		if (player1_hand[iterator] > player2_hand[iterator]) //Player 1 wins battle
		{
			RoundWinP1(iterator);
			std::cout << "Player 1 has won battle " << iterator + 1 << "!" << std::endl;
		}

		else //Player 2 wins battle
		{
			RoundWinP2(iterator);
			std::cout << "Player 2 has won battle " << iterator + 1 << "!" << std::endl;
		}
	}
	ClearHands();

	std::cout << "\nPlayer 1 has " << player1.size() << " cards in his main deck and " << player1_discard_pile.size() << " cards in his discard pile." << std::endl;
	std::cout << "Player 2 has " << player2.size() << " cards in his main deck and " << player2_discard_pile.size() << " cards in his discard pile.\n" << std::endl;
}

void WarGame::RoundWinP1(int indeck)
{
	player1_discard_pile.push_back(player1_hand[indeck]);
	player1_discard_pile.push_back(player2_hand[indeck]);
}

void WarGame::RoundWinP2(int indeck)
{
	player2_discard_pile.push_back(player1_hand[indeck]);
	player2_discard_pile.push_back(player2_hand[indeck]);
}

void WarGame::RoyaleRoundWinP1()
{
	for (int iterator = 0; iterator < 4; iterator++)
	{
		player1_discard_pile.push_back(player1_hand[iterator]);
		player1_discard_pile.push_back(player2_hand[iterator]);
	}
}

void WarGame::RoyaleRoundWinP2()
{
	for (int iterator = 0; iterator < 4; iterator++)
	{
		player2_discard_pile.push_back(player1_hand[iterator]);
		player2_discard_pile.push_back(player2_hand[iterator]);
	}
}

void WarGame::ClearHands()
{
	player1_hand.clear();
	player2_hand.clear();
}

void WarGame::RoyaleRound()
{
	roundPoints_player1 = 0;
	roundPoints_player2 = 0;

	for (int iterator = 0; iterator < 4; iterator++)
	{
		if (player1_hand[iterator] > player2_hand[iterator]) //player1 wins the specific card battle
		{
			roundPoints_player1++;
		}
		else //player2 wins the specific card battle
		{
			roundPoints_player2++;
		}
	}

	if (roundPoints_player1 > roundPoints_player2)
	{
		std::cout << "Player 1 wins Royale Round!" << std::endl;
		RoyaleRoundWinP1();
	}
	else if (roundPoints_player1 < roundPoints_player2)
	{
		std::cout << "Player 2 wins Royale Round!" << std::endl;
		RoyaleRoundWinP2();
	}
	else
	{
		std::cout << "It's a tie! Play a game of Rock Paper Scissors to decide the ultimate winner!\n" << std::endl;
		RPSGame* newRPSGame = new RPSGame();
		int whoWon = newRPSGame->RockPaperScissors();
		if (whoWon == 1)
		{
			RoyaleRoundWinP1();
		}
		else if (whoWon == 2)
		{
			RoyaleRoundWinP2();
		}
	}

	ClearHands();

	std::cout << "\nPlayer 1 has " << player1.size() << " cards in his main deck and " << player1_discard_pile.size() << " cards in his discard pile." << std::endl;
	std::cout << "Player 2 has " << player2.size() << " cards in his main deck and " << player2_discard_pile.size() << " cards in his discard pile.\n" << std::endl;
}

void WarGame::DiscardtoMainP1()
{
	for(const auto& elem : player1_discard_pile)
	{
		player1.push_back(elem);
	}
	player1_discard_pile.clear();
}

void WarGame::DiscardtoMainP2()
{
	for (const auto& elem : player2_discard_pile)
	{
		player2.push_back(elem);
	}
	player2_discard_pile.clear();
}

void WarGame::ResetAll()
{
	player1.clear();
	player2.clear();
	player1_discard_pile.clear();
	player2_discard_pile.clear();
	player1_hand.clear();
	player2_hand.clear();
}

void WarGame::GameWinP1()
{
	std::cout << "Player 2's main and discard decks have less than 4 cards!" << std::endl;
	std::cout << "Player 1 wins the game!" << std::endl;
	ResetAll();
}

void WarGame::GameWinP2()
{
	std::cout << "Player 1's main and discard decks have less than 4 cards!" << std::endl;
	std::cout << "Player 2 wins the game!" << std::endl;
	ResetAll();
}

void WarGame::FullGame()
{
	Deck52Fill();

	int royaleRoundChance = rand() % 5;
	bool gameFinished = false;

	Shuffle_and_distribute();
	PickFour();
	HandChoiceP1();
	HandChoiceP2();
	CompareAndWinner();

	while (gameFinished == false)
	{
		royaleRoundChance = rand() % 5;
		if (player1.size() < 4 && player1_discard_pile.size() > 0) //Player 1 has less than 4 cards but has cards in discard pile
		{
			std::cout << "**Player 1's deck has less than 4 cards!**" << std::endl;
			DiscardtoMainP1();
			std::cout << "**Player 1's discard deck has been shuffled and mixed with his main deck.**" << std::endl;
			std::cout << "**Player 1 now has " << player1.size() << " cards in his main deck.**\n" << std::endl;
		}

		if (player2.size() < 4 && player2_discard_pile.size() > 0) //Player 2 has less than 4 cards but has cards in discard pile
		{
			std::cout << "**Player 2's deck has less than 4 cards!**" << std::endl;
			DiscardtoMainP2();
			std::cout << "**Player 2's discard deck has been shuffled and mixed with his main deck." << std::endl;
			std::cout << "**Player 2 now has " << player2.size() << " cards in his main deck.**\n" << std::endl;
		}

		if ((player1.size() < 4 && player1_discard_pile.size() == 0)) //Player 1 has less than 4 cards and no cards in discard pile
		{
			gameFinished = true;
			GameWinP2();
			break;
		}

		if ((player2.size() < 4 && player2_discard_pile.size() == 0)) //Player 2 has less than 4 cards and no cards in discard pile
		{
			gameFinished = true;
			GameWinP1();
			break;
		}

		PickFour();
		if (royaleRoundChance == 3)
		{
			std::cout << "\n=============ROYALE ROUND=============\n" << std::endl;
			HandChoiceP1();
			HandChoiceP2();
			RoyaleRound();
		}
		else
		{
			HandChoiceP1();
			HandChoiceP2();
			CompareAndWinner();
		}
	}
}