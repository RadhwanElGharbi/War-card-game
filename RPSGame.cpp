#include <stdlib.h>
#include <time.h>
#include "RPSGame.h"

using namespace std;

int RPSGame::RockPaperScissors()
{
	WarGame* newWarGameInstance = new WarGame();
	srand(time(NULL));
	string answer, answer2;
	int userAnswer, userAnswer2;

	for (;;) {
		cin.clear();
		cout << "Player 1: rock, paper, or scissors? ";
		cin >> answer;

		if (!answer.compare("scissors") || !answer.compare("Scissors")) {
			userAnswer = 1;
			break;
		}

		if (!answer.compare("rock") || !answer.compare("Rock")) {
			userAnswer = 2;
			break;
		}

		if (!answer.compare("paper") || !answer.compare("Paper")) {
			userAnswer = 3;
			break;
		}

		else {
			cout << "Please enter a valid answer.\n";
		}

	} // infinite for loop to get user to enter valid answer

	for (;;) {
		cin.clear();
		cout << "Player 2: rock, paper, or scissors? ";
		cin >> answer2;

		if (!answer2.compare("scissors") || !answer2.compare("Scissors")) {
			userAnswer2 = 1;
			break;
		}

		if (!answer2.compare("rock") || !answer2.compare("Rock")) {
			userAnswer2 = 2;
			break;
		}

		if (!answer2.compare("paper") || !answer2.compare("Paper")) {
			userAnswer2 = 3;
			break;
		}

		else {
			cout << "Please enter a valid answer.\n";
		}

	} // infinite for loop to get user to enter valid answer

	if (userAnswer2 == 1) {
		if (userAnswer == 1) {
			cout << "It's a TIE! Play again." << std::endl;
			RockPaperScissors();
		}

		else if (userAnswer == 2) {
			cout << "Player 1 WINS!" << std::endl;
			return 1;
		}

		else if (userAnswer == 3) {
			cout << "Player 2 WINS!" << std::endl;
			return 2;
		}


	} // result if player2 chooses scissors

	else if (userAnswer2 == 2) {

		if (userAnswer == 1) {
			cout << "Player 2 WINS!" << std::endl;
			return 2;
		}

		else if (userAnswer == 2) {
			cout << "It's a TIE! Play again." << std::endl;
			RockPaperScissors();
		}

		else if (userAnswer == 3) {
			cout << "Player 1 WINS!" << std::endl;
			return 1;
		}

	}

	else if (userAnswer2 == 3) {

		if (userAnswer == 1) {
			cout << "Player 1 WINS!" << std::endl;
			return 1;
		}

		else if (userAnswer == 2) {
			cout << "Player 2 WINS!" << std::endl;
			return 2;
		}

		else if (userAnswer == 3) {
			cout << "It's a TIE! Play again." << std::endl;
			RockPaperScissors();
		}
	}
}