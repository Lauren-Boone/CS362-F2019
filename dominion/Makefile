CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittestresults: finalunittest01.c finalunittest02.c finalunittest03.c finalunittest04.c finalunittest05.c finalunittest06.c finalunittest07.c finalunittest08.c finalunittest08.c finalunittest09.c finalunittest10.c dominion.o rngs.o
	gcc -o finalunittest01 finalunittest01.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest02 finalunittest02.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest03 finalunittest03.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest04 finalunittest04.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest05 finalunittest05.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest06 finalunittest06.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest07 finalunittest07.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest08 finalunittest08.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest09 finalunittest09.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o finalunittest10 finalunittest10.c -g dominion.o rngs.o $(CFLAGS)
	./finalunittest01 >> unittestresults.out
	./finalunittest02 >> unittestresults.out
	./finalunittest03 >> unittestresults.out
	./finalunittest04 >> unittestresults.out
	./finalunittest05 >> unittestresults.out
	./finalunittest06 >> unittestresults.out
	./finalunittest07 >> unittestresults.out
	./finalunittest08 >> unittestresults.out
	./finalunittest09 >> unittestresults.out
	./finalunittest10 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out 

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe unitTest1.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
