/******************************************************************
Name: Marlon Alejandro
NSHE ID: 5002573038
Section: 1002
Assignment: 1
Description: Connect 4 Header
******************************************************************/

#include<iostream>
#include "LL.h"

using namespace std;

void boardPrint(LL<bool> board[], int size);
bool winCondition(LL<bool> board[], int size, int location);
bool vertical(LL<bool> board[], int size, int location);
bool horizontal(LL<bool> board[], int size, int location);
bool diagonalUp(LL<bool> board[], int size, int location);
bool diagonalDown(LL<bool> board[], int size, int location);

int main()
{
	int counter = 0;    // keeps track of the # of moves
	int size = 7;       // board dimensions
	int location;       // index of our linked list array
	bool gameStatus=true;   // game is running
	bool player;        //Red==true, Blue==false
    char column;        //user input that will be converted to location       

	//Red Payer prompt
	string P1= "Red player select a row: ";

	//blue player promt
	string P2 = "Blue player select a row: ";

	//Creating an array of 7 linked lists
	LL<bool> board[7];
    boardPrint(board,size); 
	while(gameStatus){
		do{
			player=true;
			cout << P1;
			cin >> column;
			column=toupper(column);

			switch(column){             // converts valid user input into location
				case 'A':
					location=0;
					break;
				case 'B':
					location=1;
					break;
				case 'C':
					location=2;
					break;
				case 'D':		
					location=3;
					break;
				case 'E':
					location=4;
					break;
				case 'F':
					location=5;
					break;
				case 'G':
					location=6;
					break;
				default: 
					location=9999;
					break;
			}
			if (location<0 ||location > size){      // invalid input
				cout << "Invalid Column\n";
				continue;
			}
			if(board[location].size() >=size){      // OOB condition
				cout << "Invalid Move\n";
				location=9999;
				continue;
			}
			board[location].tailInsert(player);     // inserts players last move
			boardPrint(board,size);                 // prints game board
		}while(location<0 ||location > size);

		if(winCondition(board, size, location)){    // checks winning conditions
			cout << "Red wins!"; 
			break;
		}

		counter++;
		if(counter>=49){                // tie condition
			cout << "Tie.\n";    // board is full
			break;
		}
		
		do{
			player=false;
			cout << P2 ;
			cin >> column;
			column=toupper(column);

			switch(column){             // converts valid user input into location
				case 'A':
					location=0;
					break;
				case 'B':
					location=1;
					break;
				case 'C':
					location=2;
					break;
				case 'D':		
					location=3;
					break;
				case 'E':
					location=4;
					break;
				case 'F':
					location=5;
					break;
				case 'G':
					location=6;
					break;
				default: 
					location=9999;
					break;
			}
			if (location<0 ||location > size){  // error: invalid input 
				cout << "Invalid Column\n";
				continue;
			}
			if(board[location].size()>=size){   // error: OOB condition
				cout << "Invalid Move\n";
				location=9999;
				continue;
			}
			board[location].tailInsert(player);   // places players last valid move  
			boardPrint(board,size);               // prints out board
		}while(location<0 ||location > size);
					
		if(winCondition(board, size, location)){    // checks winning conditions
			cout<<"Blue wins!";
			break;
		}

		counter++;
		if(counter>=49){                // tie condition 
			cout << "Tie.\n";    // board is full
			break;
		}

	}

	return 0;
}

bool vertical(LL<bool> board[], int size, int location){
	bool win=false;
	size_t counter=0;

	auto move = board[location].end();
	move--;	// move is not the last played move
	bool currentMove= *move;

	// check everything below or last move
	while(true){
		if(board[location].size()<4){
			break;
		}
		move--;
		if(*move!= currentMove){
			break;
		}
		counter++;
		if(counter==3){
			win=true;
			break;
		}
		
	}

	return win;
}

bool horizontal(LL<bool> board[], int size, int location){
	bool win=false;
	size_t counter=0;
	auto move = board[location].end();
	move--;	// move is not the last played move
	bool currentMove= *move;

	//check left
	for(int j=location-1; j>=0; j--){
		if(board[j].size()<board[location].size()){
			break;
		}
		auto boardScan=board[j].begin();

		for(int i=0; i<board[location].size()-1; i++){
			boardScan++;
		}	
		
		if(*boardScan== currentMove){

			++counter;
			if (counter==3){
				win=true;
				return win;
			}
			continue;
		} 
			break;
	}

	//check right
	for(int j=location+1; j<size; j++){
		if(board[j].size()<board[location].size()){
			break;
		}

		auto boardScan=board[j].begin();

		for(int i=0; i<board[location].size()-1; i++){
			boardScan++;
		}	
		
		if(*boardScan== currentMove){
			++counter;
			if (counter==3){
				win=true;
				return win;
			}
			continue;
		} 
		break;
	}
	return win;
}
	
	

bool diagonalUp(LL<bool> board[], int size, int location){
	bool win=false;
	size_t counter=0;
	auto move = board[location].end();
	move--;	// move is not the last played move
	bool currentMove= *move;
	int k = 0;

	//check down to the left
	for(int j=location-1; j>=0; j--){
		k++;
		if(board[j].isEmpty()){
			break;
		}
		if(board[j].size()<board[location].size()-k){

			break;
		}

		auto boardScan=board[j].begin();
		int newSize = static_cast<int> (board[location].size());
		
		for(int i=0; i<newSize-1-k; i++){
	
			boardScan++;
		}	

        if(newSize-1-k<0){
            break;
        }

		if(*boardScan== currentMove){
			counter++;
			if (counter==3){
				win=true;
				return win;
			}
			continue;
		} 
			break;
	}

    k=0;// reset displacement

	//check up to the right
	for(int j=location+1; j<size; j++){
		k++;
		if(board[j].isEmpty()){
			break;
		}
		if(board[j].size()<board[location].size()+k){
			break;
		}

		auto boardScan=board[j].begin();
		int newSize = static_cast<int> (board[location].size());
		
		for(int i=0; i<newSize-1+k; i++){
			boardScan++;
		}	

		if(*boardScan== currentMove){
			counter++;
			if (counter==3){
				win=true;
				return win;
			}
			continue;
		} 
		break;
	}
	return win;
}

bool diagonalDown(LL<bool> board[], int size, int location){
	bool win=false;
	size_t counter=0;
	auto move = board[location].end();
	move--;	// move is not the last played move
	bool currentMove= *move;
	int k = 0;

	//check up to the right
	for(int j=location-1; j>=0; j--){
		k++;
		if(board[j].isEmpty()){
			break;
		}
		if(board[j].size()<board[location].size()+k){

			break;
		}

		auto boardScan=board[j].begin();
		int newSize = static_cast<int> (board[location].size());
		
		for(int i=0; i<newSize-1+k; i++){
	
			boardScan++;
		}	

		if(*boardScan== currentMove){
			counter++;
			if (counter==3){
				win=true;
				return win;
			}
			continue;
		} 
		break;
	}

	k=0;    // reset displacement

    //check down to the right
	for(int j=location+1; j<size; j++){
		k++;
		if(board[j].isEmpty()){
			break;
		}
		if(board[j].size()<board[location].size()-k){
			break;
		}

		auto boardScan=board[j].begin();
		int newSize = static_cast<int> (board[location].size());
		
		for(int i=0; i<newSize-1-k; i++){
			boardScan++;
		}	

		if(*boardScan== currentMove){
			counter++;
			if (counter==3){
				win=true;
				return win;
			}
			continue;
		} 
		break;
	}
	return win;
}

bool winCondition(LL<bool> board[], int size, int location){
	// return false;
	if(vertical(board, size, location)){
        //cout << " vertical win\n";
		return true;
	}else if (horizontal(board, size, location)){
        //cout << " horizontal win\n";
		return true;
	}else if(diagonalUp(board, size, location)){
       // cout << " diagonalUp win\n";
		return true;
	}else if(diagonalDown(board, size, location)){
        //cout << " diagonalDown win\n";
		return true;
	}else{
		return false;
	}
	

	// start and end of the board[location](vertical check)
	// if size of board[location]<4 
	// if 4+ then compare 3 nodes below
	// check if adjacent linked lists are the same size or higher(horizontal check)
	//diagonal check
	// interate through adjacent linked lists by size of board[location] (if they are not identical return false)
	// check nodes ubove and below adjacent nodes and see if identical pieces are place diagonally
}

void boardPrint(LL<bool> board[], int size){
	auto a = board[0].end();
	auto b = board[1].end();
	auto c = board[2].end();
	auto d = board[3].end();
	auto e = board[4].end();
	auto f = board[5].end();
	auto g = board[6].end();
	a--;
	b--;
	c--;
	d--;
	e--;
	f--;
	g--;
	size--;
	size_t as = board[0].size();
	size_t bs = board[1].size();
	size_t cs = board[2].size();
	size_t ds = board[3].size();
	size_t es = board[4].size();
	size_t fs = board[5].size();
	size_t gs = board[6].size();
    cout << '\n';
	while (size>=0){
		if(as>size){
			if(*a== true){
				cout << " R ";
			}else if(*a== false){
				cout << " B ";
			}
			a--;	
		}else{
			cout << " - ";
		}

		if(bs>size){
			if(*b== true){
				cout << " R ";
			}else if(*b== false){
				cout << " B ";
			}
			b--;	
		}else{
			cout << " - ";
		}

		if(cs>size){
			if(*c== true){
				cout << " R ";
			}else if(*c== false){
				cout << " B ";
			}
			c--;	
		}else{
			cout << " - ";
		}

		if(ds>size){
			if(*d== true){
				cout << " R ";
			}else if(*d== false){
				cout << " B ";
			}
			d--;	
		}else{
			cout << " - ";
		}
		if(es>size){
			if(*e== true){
				cout << " R ";
			}else if(*e== false){
				cout << " B ";
			}
			e--;	
		}else{
			cout << " - ";
		}
		if(fs>size){
			if(*f== true){
				cout << " R ";
			}else if(*f== false){
				cout <<  " B ";
			}
			f--;	
		}else{
			cout << " - ";
		}

		if(gs>size){
			if(*g== true){
				cout << " R ";
			}else if(*g== false){
				cout << " B ";
			}
			g--;	
		}else{
			cout << " - ";
		}

		cout << "\n";
		size--;
	}

    cout << "\n";
	
	cout << " A  B  C  D  E  F  G " << endl; 
    cout << "\n";
}