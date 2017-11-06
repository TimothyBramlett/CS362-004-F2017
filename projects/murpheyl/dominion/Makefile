CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -rf *.o playdom.exe playdom player player.exe testDrawCard badTestDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer *.gcov *.dSYM *.gcda *.gcno *.so

unittestresults.out: playdom player testDrawCard testBuyCard badTestDrawCard
	echo "Result for running unit tests:" > unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o unittest1.c rngs.o -o unittest1 $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "unittest2.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o unittest2.c rngs.o -o unittest2 $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "unittest3.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o unittest3.c rngs.o -o unittest3 $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "unittest4.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o unittest4.c rngs.o -o unittest4 $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "cardtest1.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o cardtest1.c rngs.o -o cardtest1 $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "cardtest2.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o cardtest2.c rngs.o -o cardtest2 $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "cardtest3.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o cardtest3.c rngs.o -o cardtest3 $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	echo "cardtest4.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o cardtest4.c rngs.o -o cardtest4 $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "____________________________________________________________________________________________________" >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestcard1.out: playdom player
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o randomtestcard1.c rngs.o -o randomtestcard1 $(CFLAGS)
	./randomtestcard1 > randomtestcard1.out
	echo "Coverage" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	gcov -b randomtestcard1.c >> randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out
	echo "____________________________________________________________________________________________________" >> randomtestcard1.out
	echo "randomtestcard1.c.gcov" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	echo "____________________________________________________________________________________________________" >> randomtestcard1.out
	echo "dominion.c.gcov" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: playdom player
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o randomtestcard2.c rngs.o -o randomtestcard2 $(CFLAGS)
	./randomtestcard2 > randomtestcard2.out
	echo "Coverage" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	gcov -b randomtestcard2.c >> randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out
	echo "____________________________________________________________________________________________________" >> randomtestcard2.out
	echo "randomtestcard2.c.gcov" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	echo "____________________________________________________________________________________________________" >> randomtestcard2.out
	echo "dominion.c.gcov" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: playdom player
	gcc -fprofile-arcs -ftest-coverage -std=c99 dominion.o randomtestadventurer.c rngs.o -o randomtestadventurer $(CFLAGS)
	./randomtestadventurer > randomtestadventurer.out
	echo "Coverage" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	echo "____________________________________________________________________________________________________" >> randomtestadventurer.out
	echo "randomtestadventurer.c.gcov" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	echo "____________________________________________________________________________________________________" >> randomtestadventurer.out
	echo "dominion.c.gcov" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out




