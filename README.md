Lights-Out
==========
Uses the observer design pattern of programming to make the simple game Lights Out (http://en.wikipedia.org/wiki/Lights_Out_(game)). Run make to build, must have xming/x11.
Enter standard input after running the program to play.

new X (X is any natural number): Makes a new grid of size X (must run this first)

init X Y (X, Y are natural numbers less than grid size): Turns on cell at X Y (running this is optional, can occur during game option)

game X: Uses previously created grid to set up a new game with X amount of turns to finish

switch X Y: Toggles the cell at position X Y
