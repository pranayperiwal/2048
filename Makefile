movementLeft.o: movementLeft.cpp movements.h
	g++ -c $<

movementRight.o: movementRight.cpp movements.h
	g++ -c $<

movementUp.o: movementUp.cpp movements.h
	g++ -c $<

movementDown.o: movementDown.cpp movements.h
	g++ -c $<

main.o: main.cpp 
	g++ -c $<

main: main.o movementLeft.o movementDown.o movementUp.o movementRight.o
	g++ $^ -o main
