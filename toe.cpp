// Lab 1:  Tic-tac-toe game - This program makes a board of any size given by the user and can make a tic tac toe game. It can determine the winner and decide if the move is valid or not
// Vansh Joshi
// Used Dr. Scott's notes to understand how to check for wins
// https://web.eecs.utk.edu/~semrich/cs202-24/labs/1/
// Used Ashley's video to help understand how to make the board and to check for wins
// https://www.youtube.com/watch?v=9CiI9yLf3D4

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	int size;

	cout << "Enter game board size: ";
	cin >> size;

	//Creates the board
	char board[size][size];
	
	//populate board with empty space and display board
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = '-';
			cout << ' ' << board[i][j] << ' ';
		}
		cout << endl;
	} 
	
	int turn = 0;
	char player_sign = ' ';
	
	//determine whose turn it is
		while (turn < (size*size)) {
			if (turn % 2 == 0) {
				player_sign = 'X';			
			} else {
				player_sign = 'O';
		}
		
		int row = 0;
		int column = 0;
		
		cout << "Player " << player_sign << " Enter row: ";
		cin >> row;
		
		//correct for the indexing
		row--;
		
		cout << "Player " << player_sign << " Enter column: ";
		cin >> column;
		
		column--;
		

		//Check to see if spot is open
		if (board[row][column] == 'X' || board[row][column] == 'O') {
			cout << "This spot has been taken. Please choose again." << endl;
			continue;
		}
		
		//Check to see if the move is within the board
		if (row < 0 || row >= size) {
			cout << "Invaild move. Try again." << endl;
			continue;
		} else if (column < 0 || column >= size) {
			cout << "Invaild move. Try again." << endl;
			continue;
		}
		
		//Places the player's mark on the board
		board[row][column] = player_sign;	
			
		
		for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
				cout << ' ' << board[i][j] << ' ';
			}
			cout << endl;
		}
	
	int run;

	//check for horizontal wins
	for (int i = 0; i < size; i++) {
		run = 1;
		for (int j = 1; j < size; j++) {
			
			//Checks to see is the symbol is the same and not empty
			if (board[i][j] == board[i][j-1] && board[i][j] != '-') {
				run++;

				if (run == size) {
					cout << board[i][j] << " wins" << endl;
					return 0;
				}
			} else {
				run = 1;
			}
		}
	}

	//check for veritcal wins
	for (int i = 0; i < size; i++) {
		run = 1;
		for (int j = 1; j < size; j++) {
			if (board[j][i] == board[j-1][i] && board[j][i] != '-') {
				run++;

				if (run == size) {
					cout << board[i][j] << " wins" << endl;
					return 0;
				}
			} else {
				run = 1;
			}
		}
	}

	//check for left diagonal wins
	run = 1;
	for (int i = 1; i < size; i++) {
		if (board[i][i] == board[i-1][i-1] && board[i][i] != '-') {
			run++;

			if (run == size) {
				cout << board[i][i] << " wins" << endl;
				return 0;
			}
		} else {
			run = 1;
		}

	}

	//check for right diagonal wins
	run = 1;
	for (int i = 1; i < size; i++) {
		if (board[i][size-i-1] == board[i-1][size-i] && board[i][size-i-1] != '-') {
			run++;

			if (run == size) {
				cout << board[i][size-i-1] << " wins" << endl;
				return 0;
			}
		} else {
			run = 1;
		}
	}
		turn++;
	}
	//If the conditions don't pass then it is a tie
	cout << "Tie" << endl;


	return 0;

}

