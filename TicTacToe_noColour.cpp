#include <iostream>

using namespace std;

int isBlank[10];

void showBoard(char tab[3][3])
{
	cout << '\n';
	for (int i = 0; i < 3; i++)
	{
		cout << "          " << "|" << " ";
		for (int k = 0; k < 3; k++)
		{
			if (tab[i][k] == 'O')cout << tab[i][k] << " ";
			else if (tab[i][k] == 'X')cout << tab[i][k] << " ";
			else cout << tab[i][k] << " ";
		}
		cout << "|\n";
	}
	cout << '\n';
}
void nextMove()
{
	cout << "\n------------------------------------------------------------------------\n";
}

void yourMove(int XorO)
{
	if (XorO % 2 == 0)
	{
		cout << "Pick a field from 1 - 9 for an O" << ":" << " ";
	}
	else if (XorO % 2 != 0)
	{
		cout << "Pick a field from 1 - 9 for an X" << ":" << " ";
	}
}

bool winX(char tab[3][3])
{
	// "---"
	     if (tab[0][0] == 'X' && tab[0][1] == 'X' && tab[0][2] == 'X')return 1;
	else if (tab[1][0] == 'X' && tab[1][1] == 'X' && tab[1][2] == 'X')return 1;
	else if (tab[2][0] == 'X' && tab[2][1] == 'X' && tab[2][2] == 'X')return 1;
	// "|"
	else if (tab[0][0] == 'X' && tab[1][0] == 'X' && tab[2][0] == 'X')return 1;
	else if (tab[0][1] == 'X' && tab[1][1] == 'X' && tab[2][1] == 'X')return 1;
	else if (tab[0][2] == 'X' && tab[1][2] == 'X' && tab[2][2] == 'X')return 1;
	// "\"
	else if (tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X')return 1;
	else if (tab[0][2] == 'X' && tab[1][1] == 'X' && tab[2][0] == 'X')return 1;

	else return 0;
}
bool winO(char tab[3][3])
{
	// "---"
	     if (tab[0][0] == 'O' && tab[0][1] == 'O' && tab[0][2] == 'O')return 1;
	else if (tab[1][0] == 'O' && tab[1][1] == 'O' && tab[1][2] == 'O')return 1;
	else if (tab[2][0] == 'O' && tab[2][1] == 'O' && tab[2][2] == 'O')return 1;
	// "|"
	else if (tab[0][0] == 'O' && tab[1][0] == 'O' && tab[2][0] == 'O')return 1;
	else if (tab[0][1] == 'O' && tab[1][1] == 'O' && tab[2][1] == 'O')return 1;
	else if (tab[0][2] == 'O' && tab[1][2] == 'O' && tab[2][2] == 'O')return 1;
	// "\"
	else if (tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O')return 1;
	else if (tab[0][2] == 'O' && tab[1][1] == 'O' && tab[2][0] == 'O')return 1;

	else return 0;
}

void moveSwap(char tab[3][3], int XorO, int move)
{
	if (XorO % 2 == 0)
	{
		     if (move == 1)tab[0][0] = 'O';
		else if (move == 2)tab[0][1] = 'O';
		else if (move == 3)tab[0][2] = 'O';
		else if (move == 4)tab[1][0] = 'O';
		else if (move == 5)tab[1][1] = 'O';
		else if (move == 6)tab[1][2] = 'O';
		else if (move == 7)tab[2][0] = 'O';
		else if (move == 8)tab[2][1] = 'O';
		else if (move == 9)tab[2][2] = 'O';
	}
	if (XorO % 2 != 0)
	{
		     if (move == 1)tab[0][0] = 'X';
		else if (move == 2)tab[0][1] = 'X';
		else if (move == 3)tab[0][2] = 'X';
		else if (move == 4)tab[1][0] = 'X';
		else if (move == 5)tab[1][1] = 'X';
		else if (move == 6)tab[1][2] = 'X';
		else if (move == 7)tab[2][0] = 'X';
		else if (move == 8)tab[2][1] = 'X';
		else if (move == 9)tab[2][2] = 'X';
	}
}

int main()
{
	char board[3][3] = {
					 { '1','2','3' },
					 { '4','5','6' },
					 { '7','8','9' },
	};
	int move, XorO = 0;
	for (int i = 0; i < 9; i++)
	{
		showBoard(board);
		yourMove(XorO);
		while (cin >> move)
		{
			if (move < 1 || move > 9) cout << "Pick a field from 1 - 9!\n" << " ";
			else if (isBlank[move] == 1) cout << "This field is taken!\n" << " ";
			else break;
		}
		isBlank[move] = 1;
		moveSwap(board, XorO, move);
		XorO++;

		if (winX(board) == 1)
		{
			showBoard(board);
			nextMove();
			cout << " \n" << "X" << " WINS!\n";
			break;
		}
		else if (winO(board) == 1)
		{
			showBoard(board);
			nextMove();
			cout << " \n" << "O" << " WINS!\n";
			break;
		}

		nextMove();
	}
	if (winX(board) != 1 && winO(board) != 1)cout << "\nIt's a " << "DRAW!\n";

}
