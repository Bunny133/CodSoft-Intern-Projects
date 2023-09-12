#include <iostream>
#include <conio.h>

using namespace std;

void printInputMatrix();
void printBoard();
void oWon();
void xWON();
int addMark();
int check();
int Options();
int NewOptions();
void printHeader();
void Gameloop();

char board[3][3] = {' ', ' ', ' ',
					' ', ' ', ' ',
					' ', ' ', ' '};
int turn = 1;
char mark = 'O';
int input;

int main()
{
	system("cls");
	Gameloop();
	return 0;
}

void Gameloop()
{
	printHeader();
	int choice = Options();

	do
	{

		if (choice == 1)
		{
			int won = 0;
			int validInput = 0;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					board[i][j] = ' ';
				}
			}
			turn = 1;
			mark = '0';

			for (int i = 0; i < 9; i++)
			{
				system("cls");
				printInputMatrix();
				printBoard();
				if (turn)
					cout << "Player 1 Turn (Symbol: O)" << endl;
				else
					cout << "Player 2 Turn (Symbol: X)" << endl;

				cout << "Enter Input from Input Matrix: ";
				cin >> input;
				while (input < 0 || input > 9)
				{
					cout << "Invalid Input. Please Re-Enter input: ";
					cin >> input;
				}
				if (turn)
					mark = 'O';
				else
					mark = 'X';

				validInput = addMark();
				if (!validInput)
				{
					i--;
					continue;
				}
				won = check();
				if (won)
				{
					system("cls");
					printBoard();
					if (turn)
					{
						oWon();
						choice = Options();
					}
					else
					{
						xWON();
						choice = Options();
					}
					getch();
					break;
					Options();
				}
				if (i == 8)
				{
					system("cls");
					printBoard();
					cout << endl
						 << "*** MATCH DRAW ***";
				}

				turn = !turn;
			}
		}
	} while (choice != 2);
}

void printHeader()
{

	cout << "         __________________ _______   _________ _______  _______   _________ _______  _______ " << endl;
	cout << "         \\__   __/\\__   __/(  ____ \\  \\__   __/(  ___  )(  ____ \\  \\__   __/(  ___  )(  ____ \\" << endl;
	cout << "            ) (      ) (   | (    \\/     ) )   | (   ) || (    \\/     ) (   | (   ) || (    \\/" << endl;
	cout << "            | |      | |   | |           | |   | (___) || |           | |   | |   | || (__    " << endl;
	cout << "            | |      | |   | |           | |   |  ___  || |           | |   | |   | ||  __)   " << endl;
	cout << "            | |      | |   | |           | |   | (   ) || |           | |   | |   | || (      " << endl;
	cout << "            | |   ___) (___| (____/\\     | |   | )   ( || (____/\\     | |   | (___) || (____/\\" << endl;
	cout << "            )_(   \\_______/(_______/     )_(   |/     \\|(_______/     )_(   (_______)(_______/" << endl;
	cout << endl
		 << endl;
}

int Options()
{
	int option;
	cout << "                                       1. Start The Game" << endl;
	cout << "                                       2. Exit The Game" << endl;
	cin >> option;
	return option;
}

void oWon()
{
	cout << endl
		 << endl;
	cout << "                                               _______             _______  _       " << endl;
	cout << "                                              (  ___  )  |\\     /|(  ___  )( (    /|" << endl;
	cout << "                                              | (   ) |  | )   ( || (   ) ||  \\  ( |" << endl;
	cout << "                                              | |   | |  | | _ | || |   | ||   \\ | |" << endl;
	cout << "                                              | |   | |  | |( )| || |   | || (\\ \\) |" << endl;
	cout << "                                              | |   | |  | || || || |   | || | \\   |" << endl;
	cout << "                                              | (___) |  | () () || (___) || )  \\  |" << endl;
	cout << "                                              (_______)  (_______)(_______)|/    )_)" << endl
		 << endl;
}
void xWON()
{
	cout << endl
		 << endl;
	cout << "                                                              _______      " << endl;
	cout << "                                         |\\     /|  |\\     /|(  ___  )( (    /|" << endl;
	cout << "                                         ( \\   / )  | )   ( || (   ) ||  \\  ( |" << endl;
	cout << "                                          \\ (_) /   | | _ | || |   | ||   \\ | |" << endl;
	cout << "                                           ) _ (    | |( )| || |   | || (\\ \\) |" << endl;
	cout << "                                          / ( ) \\   | || || || |   | || | \\   |" << endl;
	cout << "                                         ( /   \\ )  | () () || (___) || )  \\  |" << endl;
	cout << "                                         |/     \\|  (_______)(_______)|/    )_)" << endl
		 << endl;
}

void printInputMatrix()
{
	cout << endl
		 << endl
		 << "INPUT MATRIX" << endl;
	cout << " 1 | 2 | 3 " << endl;
	cout << "------------" << endl;
	cout << " 4 | 5 | 6 " << endl;
	cout << "------------" << endl;
	cout << " 7 | 8 | 9 " << endl
		 << endl
		 << endl;
}
void printBoard()
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
	cout << "------------" << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
	cout << "------------" << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl
		 << endl
		 << endl;
}
int addMark()
{
	for (int i = 0, k = 1; i < 3; i++)
	{
		for (int j = 0; j < 3; j++, k++)
		{
			if (k == input)
				if (board[i][j] == ' ')
				{
					board[i][j] = mark;
					return 1;
				}
				else
				{
					cout << "Invalid Input";
					getch();
					return 0;
				}
		}
	}
}
int check()
{

	if (board[0][0] == mark && board[0][1] == mark && board[0][2] == mark)
		return 1;
	if (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark)
		return 1;
	if (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark)
		return 1;
	if (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark)
		return 1;
	if (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark)
		return 1;
	if (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark)
		return 1;
	if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
		return 1;
	if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
		return 1;

	return 0;
}
