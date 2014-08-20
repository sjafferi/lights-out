#include <iostream>
#include <string>
#include "grid.h"
#include "cell.h"
#include "window.h"
using namespace std;

int main(){
	Grid g;
	string s;
	int i, r, c, moves;
	cin >> s; //s can be
				// new
				// init
				// game
	while(true){
		if (cin.eof()) break;
		if (s == "new"){ //if new..
				cin >> i;	//grab the required grid Size
				g.init(i);  //then initialize the grid
		} else if (s == "init"){	//if init
			while(cin >> r >> c){	//grab input for required cell changes
				if (r == -1 && c == -1) break;	// if -1 -1 input is given then stop getting input
				g.init(r, c);	//sets the required cell to on
			}
		} else if (s == "game"){ //if game..
			cin >> i;	//grab number of moves
			if (i == 1) cout << i << " move left" << endl; //print num of moves
			else cout << i << " moves left" << endl;
			moves = i;
			while (moves > 0) { //iterate until moves are over, game is won or end of file
				if(g.isWon()) {
					cout << "Won" << endl;	//if game is won before moves are over, then print Won
					return 0;
				}
				cin >> s;	// s can be..
								//init
								//switch
				if(cin.eof()) return 0; 
				if (s == "init"){	//if init..
					while(cin >> r >> c){	//then do the same thing as above
						if (r == -1 && c == -1) break;
						g.init(r, c);
					}
				} else if (s == "switch"){ //if switch..
					cin >> r >> c;	//grab input for cell position
					g.toggle(r, c); //toggle that cell
					moves--;	//less allowed number of moves
					if (moves == 1) cout << moves << " move left" << endl; //print moves left
					else cout << moves << " moves left" << endl;
					if(g.isWon()) {	//check if won
						cout << "Won" << endl;
						return 0;
					}
				}
			}
			if (!g.isWon()){ //if moves end before win then game is lost
				cout << "Lost" << endl;
				return 0;
			}		
		}
		cin >> s; //grab s again
	}
}

