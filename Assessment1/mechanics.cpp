#include <iostream>
using namespace std;
// Prints Tic Tac Toe board.
char board[3][3]{ { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } };
// bool decides if game is over or not.
bool gameOver = false;
bool tieGame = false;
// Tie counter
int tieCount;
// Provides all conditions to win for Player one or Player two.
void winconditions();
// Prompts player ones turn
void playerOneSelection();
//Prompts player twos turn
void playerTwoSelection();
// Reselection after invalid input Player 1
void playeronereselect();
//Reselection after invalid input Player 2
void playertworeselection();
void gameBase() {
		cout << "+-----+-----+-----+" << endl;

		cout << "|  " << board[0][0] << "  |  " << board[0][1] << "  |  " <<board[0][2]<<  "  |" << endl;
		cout << "+-----+-----+-----+" << endl;

		cout << "|  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |" << endl;

		cout << "+-----+-----+-----+" << endl;

		cout << "|  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |" << endl;
		cout << "+-----+-----+-----+" << endl;
		
		}
void resetboard() {
	char board[3][3]{ { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } };
	cout << "+-----+-----+-----+" << endl;

	cout << "|  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |" << endl;
	cout << "+-----+-----+-----+" << endl;

	cout << "|  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |" << endl;

	cout << "+-----+-----+-----+" << endl;

	cout << "|  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |" << endl;
	cout << "+-----+-----+-----+" << endl;

}
// Begins Game Loop and Player Ones Selection

	void playerOneSelection() {
	int player1selection;
		cout << "Player One Place an X on the map!" << endl;
		tieCount++;
		cin >> player1selection;
		if (player1selection == 1 && board[0][0] == '1') {
			board[0][0] = 'X';
		}
		else if (player1selection == 2 && board[0][1] == '2') {
			board[0][1] = 'X';
		}
		else if (player1selection == 3 && board[0][2] == '3') {
			board[0][2] = 'X';
		}
		else if (player1selection == 4 && board[1][0] == '4') {
			board[1][0] = 'X';
		}
		else if (player1selection == 5 && board[1][1] == '5') {
			board[1][1] = 'X';
		}
		else if (player1selection == 6 && board[1][2] == '6') {
			board[1][2] = 'X';
		}
		else if (player1selection == 7 && board[2][0] == '7') {
			board[2][0] = 'X';
		}
		else if (player1selection == 8 && board[2][1] == '8') {
			board[2][1] = 'X';
		}
		else if (player1selection == 9 && board[2][2] == '9') {
			board[2][2] = 'X';
		}
		else {
			playeronereselect();
		}
		
		gameBase();
		winconditions();
		if (gameOver == true)
		{
			cout << "Player one has won the game!" << endl;
			cout << "Congratulations and Thanks for playing!" << endl;
			system("pause");
		}
		if (gameOver == false) {
			playerTwoSelection();
		}

	
}
	void playerTwoSelection() {
		
			int  player2selection;
			cout << "Player Two Place an O on the map!" << endl;
			tieCount++;
			cin >> player2selection;
			if (player2selection == 1 && board[0][0] == '1') {
				board[0][0] = 'O';
			}
			else if (player2selection == 2 && board[0][1] == '2') {
				board[0][1] = 'O';
			}
			else if (player2selection == 3 && board[0][2] == '3') {
				board[0][2] = 'O';
			}
			else if (player2selection == 4 && board[1][0] == '4') {
				board[1][0] = 'O';
			}
			else if (player2selection == 5 && board[1][1] == '5') {
				board[1][1] = 'O';
			}
			else if (player2selection == 6 && board[1][2] == '6') {
				board[1][2] = 'O';
			}
			else if (player2selection == 7 && board[2][0] == '7') {
				board[2][0] = 'O';
			}
			else if (player2selection == 8 && board[2][1] == '8') {
				board[2][1] = 'O';
			}
			else if (player2selection == 9 && board[2][2] == '9') {
				board[2][2] = 'O';
			}
			else
			{
				playertworeselection();
			}			
			gameBase();
			winconditions();
			if (gameOver == true) {
				cout << "Player Two Has Won the Game!" << endl;
				cout << "Congratulations and Thanks for playing!" << endl;
				system("pause");
			}
		if (gameOver == false) {

			playerOneSelection();

		}
	}
	

	
	void playeronereselect() {
		cout << "Invalid selection, please try again" << endl;
		gameBase();
		playerOneSelection();


	}
	void playertworeselection() {
		cout << "Invalid selection, Please Try Again" << endl;
		gameBase();
		playerTwoSelection();

	} 
	
	
	
	
	void winconditions() {
		if (board[0][0] != '1') {
			if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
				gameOver = true;
				
			}
			if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
				gameOver = true;
				
			}
		}
			if (board[1][1] != '5') {
				if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
					gameOver = true;
				
				}
				if (board[1][0] == board[1][1] && board[1][2] == board[1][1]) {
					gameOver = true;
					
				}
				if (board[2][0] == board[1][1] && board[0][2] == board[1][1]) {
					gameOver = true;
			
				}
				if (board[0][1] == board[1][1] && board[2][1] == board[1][1]) {
					gameOver = true;
				
				}
			}
			if (board[2][2] != '9') {
				if (board[2][2] == board[1][2] && board[2][2] == board[0][2]) {
					gameOver = true;
				
				}
				if (board[2][2] == board[2][0] && board[2][2] == board[2][1]) {
					gameOver = true;
				}
				}
			if (tieCount == 9 and gameOver == false){											
				cout << "Tie Game!" << endl;
				tieGame = true;
				}
}