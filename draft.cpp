#include<iostream>
#include "LL.h"

using namespace std;

int main()
{
	//Counter will count the number of turns
	int counter = 0;
	int size = 7;

	//Player will swap at the end of each turn 
	bool Player = true;

	//If false player one will move 
	string P1= "Red player select a row: ";

	//If true player two will move 
	string P2 = "Blue player select a row:  ";


	//Creating an array of 7 linked lists
	LL<bool> board[7];

	
	for(int i =0 ; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
		board[0].headInsert(true);
		}
	}

	// board[3].tailInsert(true);
	// board[3].tailInsert(false);
	for(int i = 0; i < size; i ++)
	board[i].printLL(); 
	cout << "A B C D E F G " << endl; 


}