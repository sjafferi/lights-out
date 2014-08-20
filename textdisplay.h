#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
  char **theDisplay;
  const int gridSize;
 public:
  TextDisplay(int n); //default ctor
  void notify(int r, int c, char ch); //gets notified by cells of state change
  ~TextDisplay(){	//destroy array of characters on delete
  	for (int i = 0; i < gridSize*gridSize; i++){
		delete theDisplay[i];
	}
	delete [] theDisplay;
  }
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
