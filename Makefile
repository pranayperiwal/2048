movementLeft.o: movementLeft.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

movementRight.o: movementRight.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

movementUp.o: movementUp.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

movementDown.o: movementDown.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

main.o: main.cpp undo.h finalMovements.h
	g++ -c $<

main: main.o movementLeft.o movementDown.o movementUp.o movementRight.o
	g++ $^ -o main
