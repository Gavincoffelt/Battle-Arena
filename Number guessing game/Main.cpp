 #include <iostream>
using namespace std;

int main() {
	char UI = 'q';
	int numOfGuesses = 0;
	int max = 1000;
	int min = 1;
	int guess = 500;
	char resetUI;
	bool correctAnswer = true;
	bool endGame = false;
	cout << "Welcome to Number Guesser, please pick a number between " << min << " and " << max << endl;
	do {
		char UI = 'q';
		int numOfGuesses = 0;
		int max = 1000;
		int min = 1;
		int guess = 500;
		char resetUI;
		do {
			cout << "Is your Number higher or lower than " << guess << endl;
			cout << "Press U for Higher, Press L for lower, Press R if the number is your Number" << endl;
			cin >> UI;

			if (UI == 'U' || UI == 'u') {
				min = guess;
				guess = ((max - min) / 2 + min);
				numOfGuesses++;
			}
			else if (UI == 'L' || UI == 'l') {
				max = guess;
				guess = ((max - min) / 2 + min);
				numOfGuesses++;
			}
			else if (UI == 'R' || UI == 'r') {
				correctAnswer = false;
			}
			if (numOfGuesses == 10) {
				cout << "Maximum number of guesses reached." << endl;
				correctAnswer = false;
			}
			if (numOfGuesses == 10) {
				cout << "Would you Like to Play Again? Y/N" << endl;
				cin >> resetUI;
				if (resetUI == 'Y' || resetUI == 'y') {
					correctAnswer = true;
					numOfGuesses = 0;
				}
				if (resetUI == 'N' || resetUI == 'n') {
					cout << "Thank you for playing!" << endl;
					endGame = true;
				}
			}
		} while (correctAnswer == true);
		if (correctAnswer == false, numOfGuesses <= 10) {
			cout << "The computer found your number! It was " << guess << "! Would you like to Play again? Y/N" << endl;
			cin >> resetUI;
			if (resetUI == 'Y' || resetUI == 'y') {
				correctAnswer = true;
				numOfGuesses = 0;
			}
			if (resetUI == 'N' || resetUI == 'n') {
				cout << "Thank you for playing!" << endl;
				endGame = true;
			}
		}
	} while (endGame == false);
}   