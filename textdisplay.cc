#include "textdisplay.h"
TextDisplay::TextDisplay(int n): gridSize(n){
	theDisplay = new char * [n*n];	//make and initialize 2d array of characters
	for (int i = 0; i < n*n; i++){
		 theDisplay[i] = new char();
	}
}
void TextDisplay::notify(int r, int c, char ch){
	int pos = r*gridSize + c;	//2d position converted to 1d
	*theDisplay[pos] = ch;
}

std::ostream & operator<<(std::ostream &out, const TextDisplay &td){
	for (int r = 0; r < td.gridSize; r++){	
		for (int c = 0; c < td.gridSize; c++){
			int pos = r*td.gridSize + c;
			out << *td.theDisplay[pos];	//out each individual character in row
		}
		out << std::endl; //new line after each row
	}
	return out;
}