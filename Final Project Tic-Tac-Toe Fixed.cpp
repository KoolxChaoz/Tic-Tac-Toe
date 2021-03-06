// Final Project Tic-Tac-Toe Fixed.cpp : Defines the entry point for the console application.
// 3x3 Tic-Tac-Toe game that is played by 2 players.

#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <string>
using namespace std;

char board[9] = { '1','2','3','4','5','6','7','8','9' };
string player = "X";
string stop = "n";
void Get(string name1, string name2);
void Inputs(int input, string name1, string name2);

void CreateBoard() 
{
	system("CLS");
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
	cout << "___________\n";
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
	cout << "___________\n";
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
	//Creates the game board.
}

bool CheckWinner()
{
	// Checks for row wins. 
	if (board[0] == board[1] && board[1] == board[2]) return true;
	else if (board[3] == board[4] && board[4] == board[5]) return true;
	else if (board[6] == board[7] && board[7] == board[8]) return true;

	// Checks for column wins.
	else if (board[0] == board[3] && board[3] == board[6]) return true;
	else if (board[1] == board[4] && board[4] == board[7]) return true;
	else if (board[2] == board[5] && board[5] == board[8]) return true;

	// Checks for diagonal wins. 
	else if (board[0] == board[4] && board[4] == board[8]) return true;
	else if (board[2] == board[4] && board[4] == board[6]) return true; 

	// Checks for ties.
	if (board[0] == board[1] && board[1] == board[2] && board[2] == board[3] && board[3] == board[4] && board[4] == board[5] && board[5] == board[6] && board[6] == board[7] && board[7] == board[8]) return true;

	else return false;
}

void Inputs(int input, string name1, string name2)
{
	if (input - 1  < 0 || input - 1 > 10 ) 
	{
		cout << "Invalid position! Try again with a value of 1-9. \n";
		Get(name1, name2);
	}
	else if (board[input - 1] == 'X' || board[input - 1] == 'O') {
		cout << "Position is already taken! Try again with another value of 1-9. \n";
		Get(name1, name2);
	}//Incorrect values and values already used will not work and only numbers 1-9 will function properly.
	else {
		if (player == "X")
		{
			board[input - 1] = 'X';
			CreateBoard();
			bool winner = CheckWinner();
			if (winner == false)
			{
				player = "O";
			}
			else
			{
				stop = "y";
				system("CLS");
				cout << player << " Wins!!" << endl;
			}
		}
		else if (player == "O")
		{
			board[input - 1] = 'O';
			CreateBoard();
			bool winner = CheckWinner();
			if (winner == false)
			{
				player = "X";
			}
			else
			{
				stop = "y";
				system("CLS");
				cout << player << " Wins!!" << endl;
			}
		}
		// Input system for X and O.
	}
}

void Get(string name1, string name2) 
{
	if (stop == "y") 
	{
		cout << "Congratulations!" << endl;
	}
	else {
		if (player == "X") 
		{
			cout << name1 << ", enter your position!" << endl;
			string position;
			getline(cin, position);
			int positionInt;
			positionInt = stoi(position);
			Inputs(positionInt, name1, name2);
			Get(name1, name2);
		} //Position input for Player 1(X).
		else if (player == "O") 
		{
			cout << name2 << ", enter your position!" << endl;
			string position;
			getline(cin, position);
			int positionInt;
			positionInt = stoi(position);
			Inputs(positionInt, name1, name2);
			Get(name1, name2);
		} //Position input for Player 2(O).
	}
}

int main()
{
	cout << "Welcome Player(s) to Tic-Tac-Toe!!" << endl;
	Sleep(1200);
	system("CLS");
	cout << "Player 1, enter your name: " << endl;
	string name1;
	getline(cin, name1);
	if (name1 == "") {
		name1 = "Player 1";
	} //If no name is entered, default is used.
	cout << "Hello, " << name1 << " you are X!" << endl;
	Sleep(1500);
	system("CLS");
	cout << "Player 2, enter your name: " << endl;
	string name2;
	getline(cin, name2);
	if (name2 == "") {
		name2 = "Player 2";
	} //If no name is entered, default 2 is used.
	cout << "Hello, " << name2 << " you are O!" << endl;
	Sleep(1500);
	system("CLS");
	cout << "Good Luck " << name1 << " and " << name2 << ", may be the best player win!" << endl;
	Sleep(2000);
	//Introduction for Players 1 and 2.
	system("CLS");
	cout << "3" << endl;
	Sleep(1000);
	cout << "2" << endl;
	Sleep(1000);
	cout << "1" << endl;
	Sleep(1000);
	cout << "GO!!" << endl;
	Sleep(500);
	// Countdown by 3 seconds.
	CreateBoard(); //Game Board is created.
	Get(name1, name2);
	// Initial inputs for Player 1 and Player 2.
	return 0;
}
