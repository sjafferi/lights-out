#include "grid.h"
#include <iostream>
#include <string>
void Grid::addNeighbours(Cell * currCell, int x, int y){	//finds any neighbours and adds them
	if ((x-1) >= 0) currCell->addNeighbour(theGrid[gridSize*y + (x-1)]);
	if ((x+1) < gridSize) currCell->addNeighbour(theGrid[gridSize*y + (x+1)]);
	if ((y-1) >= 0) currCell->addNeighbour(theGrid[gridSize*(y-1) + x]);
	if ((y+1) < gridSize) currCell->addNeighbour(theGrid[gridSize*(y+1) + x]);
}
void Grid::clearGrid(){	//frees grid
  	for (int i = 0; i < gridSize*gridSize; i++){
		delete theGrid[i];
	}
	delete [] theGrid;
	gridSize = 0;
}
bool Grid::isWon(){	//check if all the lights are off, if so then you win!
	int numOn = 0;
	for (int i = 0; i < gridSize*gridSize; i++){
		if(!theGrid[i]->getOn()) numOn++;
	}
	return (numOn == (gridSize * gridSize));
}
void Grid::init(int n){
	wind = new Xwindow();
	theGrid = new Cell*[n*n];
	gridSize = n;
	int width = 200/n;
	for (int r = 0; r < n; r ++){
		for (int c = 0; c < n; c++){
			int pos = r*n + c;
			theGrid[pos] = new Cell();	//initialize each cell and set their coordinates
			theGrid[pos]->setCoords(r, c, 125 + width*c,125 + width*r, width, width, wind);		
		}		
	}
	for (int r = 0; r < n; r ++){
		for (int c = 0; c < n; c++){
			int pos = r*n + c;
			addNeighbours(theGrid[pos], c, r);	//add the neighbours of each cell
		}		
	}
	
	
}
void Grid::turnOn(int r, int c){
	int pos = r*gridSize + c;
	if(theGrid[pos]){
		theGrid[pos]->setOn();	//sets the cell to on
	}
}
void Grid::toggle(int r, int c){
	int pos = r*gridSize + c;
	if(theGrid[pos]){
		theGrid[pos]->toggle(); //toggle the cell
		theGrid[pos]->notifyNeighbours(); //let neighbours know about toggle
	}
}
void Grid::init(int r, int c){
	turnOn(r, c);	//seems like a redundant function but yolo
}
Grid::~Grid(){
  	for (int i = 0; i < gridSize*gridSize; i++){	//deletes all cell in grid
		delete theGrid[i];
	}
	delete [] theGrid; // delete grid itself
	delete wind; //delete Xwindow
}
