#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "cell.h"
#include "textdisplay.h"
#include "window.h"
class Grid {
  Cell **theGrid;  // The actual grid.
  int gridSize;    // Size of the grid.
  bool won;        // Grid in winning state
  TextDisplay *td; // The text display.
  
  void updateDisplay();
  void addNeighbours(Cell * currCell, int x, int y);
  void clearGrid();   // Frees the grid.

 public:
 Xwindow * wind;
  Grid():gridSize(0), won(false){}
  ~Grid();
  bool isWon(); // Call to determine if grid is in a winning state.
  void init(int n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void turnOn(int r, int c);  // Sets cell at row r, col c to On.
  void toggle(int r, int c);  // Sets cell at row r, col c to On/off.
  void init(int r, int c);
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
