#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define NUM_TESTS 5000

int main() {

	srand(time(NULL));
  	struct gameState state;
  	int kingdomCards[10] = {smithy, adventurer, embargo, village, sea_hag, tribute, minion, mine, cutpurse, gardens};
  	int numPlayers, randomSeed, currentPlayer, i, returnValue, tempDeckCount, tempHandCount, tempNumActions;
  	int returnValueErrors = 0, deckCountErrors = 0, handCountErrors = 0, numActionsErrors = 0;

  	printf("Random Testing: Village\n\n");
  	printf("Number of Tests: %d\n\n", NUM_TESTS);

	for (i = 0; i < NUM_TESTS; i++) {
		randomSeed = rand();
		numPlayers = rand() % 2 + 2; //2-4 players 
		initializeGame(numPlayers, kingdomCards, randomSeed, &state);

		currentPlayer = rand() % (numPlayers - 1) + 1;
		state.whoseTurn = currentPlayer;
		state.deckCount[currentPlayer] = rand() % MAX_DECK;
		state.discardCount[currentPlayer] = rand() % MAX_DECK;
		state.handCount[currentPlayer] = rand() % MAX_HAND;
		state.hand[currentPlayer][0] = village;
		state.numActions = rand() % 10; 
		tempDeckCount = state.deckCount[currentPlayer];
		tempNumActions = state.numActions;
		tempHandCount = state.handCount[currentPlayer];
		
		returnValue = cardEffect(village, 0, 0, 0, &state, 0, 0);

		//+1 Card, +2 Actions
		if (returnValue != 0) returnValueErrors++;
		if (state.deckCount[currentPlayer] != (tempDeckCount - 1)) deckCountErrors++;
		if (state.handCount[currentPlayer] != (tempHandCount)) handCountErrors++;
		if (state.numActions != (tempNumActions + 2)) numActionsErrors++;
	}	

	printf("%d Return Value Errors\n", returnValueErrors);
	printf("%d Deck Count Errors\n", deckCountErrors);
	printf("%d Hand Count Errors\n", handCountErrors);
	printf("%d Number of Actions Errors\n", numActionsErrors);
	printf("\nEnd Random Testing: Village");
	printf("\n_____________________________________________________________________________\n");
	
	return 0;
}
