movementLeft.o: movementLeft.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

movementRight.o: movementRight.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

movementUp.o: movementUp.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

movementDown.o: movementDown.cpp checkMove.h movements.h finalMovements.h
	g++ -c $<

endConditions.o: endConditions.cpp finalMovements.h endConditions.h
	g++ -c $<

quit.o: quit.cpp save.h
	g++ -c $<

undo.o: undo.cpp undo.h
	g++ -c $<

main.o: main.cpp undo.h finalMovements.h save.h endConditions.h movements.h
	g++ -c $<

main: main.o movementLeft.o movementDown.o movementUp.o movementRight.o endConditions.o quit.o undo.o
	g++ $^ -o main

clean:
	rm -f main main.o movementLeft.o movementDown.o movementUp.o movementRight.o endConditions.o quit.o undo.o

.PHONY: clean