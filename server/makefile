CC = g++
racer_server: main.o server.o game.o gamelist.o player.o playerlist.o
	$(CC) -o racerserver main.o server.o game.o gamelist.o player.o playerlist.o -pthread
main.o: main.cpp core/server.h
	$(CC) -c main.cpp
server.o: core/src/server.cpp core/server.h ../data/game/game.h ../data/player/player.h
	$(CC) -c core/src/server.cpp
game.o: ../data/game/src/game.cpp ../data/game/game.h
	$(CC) -c ../data/game/src/game.cpp
gamelist.o: ../data/game/src/gamelist.cpp ../data/game/game.h 
	$(CC) -c ../data/game/src/gamelist.cpp
player.o: ../data/player/src/player.cpp ../data/player/player.h
	$(CC) -c ../data/player/src/player.cpp
playerlist.o: ../data/player/src/playerlist.cpp ../data/player/player.h
	$(CC) -c ../data/player/src/playerlist.cpp
clean:
	rm -f *.o