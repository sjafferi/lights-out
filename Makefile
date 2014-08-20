CXX=g++
XXFLAGS=-Wall -MMD
EXEC=a4q3
OBJECTS=a4q3.o textdisplay.o grid.o cell.o window.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${XXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
-include ${DEPENDS}

clean:
	rm ${OBJECTS}${EXEC}