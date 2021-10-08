#ifndef WarGame_h
#define WarGame_h

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <array>

class WarGame
{
public:
	WarGame(); //constructor
	~WarGame(); //destructor

	void Deck52Fill();
	void Shuffle_and_distribute();
	void PickFour();
	void DisplayHandP1();
	void DisplayHandP2();
	bool FindVecDuplicate(std::vector<int>);
	void HandChoiceP1();
	void HandChoiceP2();
	void RoundWinP1(int indeck);
	void RoundWinP2(int indeck);
	void RoyaleRoundWinP1();
	void RoyaleRoundWinP2();
	void ClearHands();
	void CompareAndWinner();
	void RoyaleRound();
	void DiscardtoMainP1();
	void DiscardtoMainP2();
	void ResetAll();
	void GameWinP1();
	void GameWinP2();

public:
	void FullGame();


	std::vector<int> player1, player2; //2 vector objects that will contain contents from the map.

private:
	std::vector<std::string> suit; //suit
	std::vector<int> deck52; //standard 52 card deck
	std::vector<std::string> cardTitle;
	std::string card; //full title of the card
	std::map <const int, const std::string> cards; //create map 'cards' with ID and integer value


private:
	std::vector<int> player1_hand, player2_hand;
	std::vector<int> player1_discard_pile, player2_discard_pile;
	int roundPoints_player1, roundPoints_player2;
};

#endif