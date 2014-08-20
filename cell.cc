#include "cell.h"
#include <iostream>
using namespace std;
bool Cell::getOn(){
	return isOn;
}
void Cell::setOn(){
	isOn = true;
	draw();
}
void Cell::toggle(){
	isOn = (isOn) ? false: true;	//if cell is on then turn it off and vice versa
	if(isOn) draw();
	else undraw();
}
void Cell::setCoords(int x, int y){ //set the coordinates of cell
	r = x;	
	c = y;
}
void Cell::setCoords(int r, int c, int x, int y, int width, int height, Xwindow *xwin){
	this->r = r;
	this->c = c;
	this->x = x;
	this->y = y;
	w = width;
	h = height;
	wind = xwin;
}
void Cell::notifyDisplay(TextDisplay &t){
	char x = (isOn) ? 'X': '_'; //if the cell is on then notify display that it is in 'X' state otherwise in '_' state
	t.notify(r,c,x);
}
void Cell::addNeighbour(Cell *neighbour){
	if(numNeighbours>=4) return;	
	neighbours[numNeighbours] = neighbour; //set the provided neighbour to array of neighbours
	numNeighbours++;
}
void Cell::notify(){
	toggle();	//when this is notified by neighbours then it has to toggle
}
void Cell::notifyNeighbours(){
	for(int i = 0; i < numNeighbours; i++){
		neighbours[i]->notify();	//notifies all of its neighbours
	}
}
void Cell::draw(){
	wind->fillRectangle(x, y, w, h, 1);
}
void Cell::undraw(){
	wind->fillRectangle(x, y, w, h, 0);
}