#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"
#include "window.h"

const int maxNeighbours = 4;

class Cell {
  bool isOn;
  int numNeighbours;
  Xwindow * wind;
  Cell *neighbours[maxNeighbours];
  int r, c, x, y, w, h;
  // Add other private members if necessary
  void draw();
  void undraw();

 public:
  Cell(): numNeighbours(0), isOn(false){}  // Default constructor

  bool getOn();         // Returns the value of isOn.
  void setOn();         // Explicitly sets me to on.
  void toggle();        // Toggles me between on and off.
  void setCoords(int, int);
  void setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w);
  void notifyDisplay(TextDisplay &t);

  void addNeighbour(Cell *neighbour);

  void notify();  // My neighbours will call this, to let me know
                  // they've been switched.

  void notifyNeighbours();   // Tell all of my neighbours that I have been
                             // switched.
};

#endif