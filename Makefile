movementLeft.o: movement/movementLeft.cpp header/checkMove.h header/movements.h header/finalMovements.h
	g++ -c $<

movementRight.o: movement/movementRight.cpp header/checkMove.h header/movements.h header/finalMovements.h
	g++ -c $<

movementUp.o: movement/movementUp.cpp header/checkMove.h header/movements.h header/finalMovements.h
	g++ -c $<

movementDown.o: movement/movementDown.cpp header/checkMove.h header/movements.h header/finalMovements.h
	g++ -c $<

endConditions.o: functionalities/endConditions.cpp header/finalMovements.h header/endConditions.h
	g++ -c $<

quit.o: functionalities/quit.cpp header/save.h
	g++ -c $<

undo.o: functionalities/undo.cpp header/undo.h
	g++ -c $<

main.o: main.cpp header/undo.h header/finalMovements.h header/save.h header/endConditions.h header/movements.h
	g++ -c $<

main: main.o movementLeft.o movementDown.o movementUp.o movementRight.o endConditions.o quit.o undo.o
	g++ $^ -o main

clean:
	rm -f main main.o movementLeft.o movementDown.o movementUp.o movementRight.o endConditions.o quit.o undo.o

.PHONY: clean