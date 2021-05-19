
Main: Animal.o Game.o Game_Board.o Position.o Sheep.o Wolf.o sheepGroup.o Main.o
	g++ $(CFLAGS) -o Main Main.o Animal.o Game.o Game_Board.o Position.o Sheep.o Wolf.o sheepGroup.o 
Main.o: Main.cpp Game.h
	g++ $(CFLAGS) -c Main.cpp
Game.o: Game.cpp Game.h Wolf.h Game_Board.h Animal.h Position.h sheepGroup.h Sheep.h
	g++ $(CFLAGS) -c Game.cpp
Animal.o: Animal.cpp Animal.h Game_Board.h Position.h
	g++ $(CFLAGS) -c Animal.cpp
Position.o: Position.cpp Position.h
	g++ $(CFLAGS) -c Position.cpp
Game_Board.o: Game_Board.cpp Game_Board.h
	g++ $(CFLAGS) -c Game_Board.cpp
Wolf.o: Wolf.cpp Wolf.h Game_Board.h Animal.h Position.h
	g++ $(CFLAGS) -c Wolf.cpp
Sheep.o: Sheep.cpp Sheep.h Animal.h Game_Board.h
	g++ $(CFLAGS) -c Sheep.cpp
sheepGroup.o: sheepGroup.cpp sheepGroup.h Game_Board.h Sheep.h Animal.h Position.h
	g++ $(CFLAGS) -c sheepGroup.cpp
clear:
	rm -f *.o Main
    