#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv)	{
	struct gameState state;
	int result;
	int cardsInHand;
	state.numActions = 0;
	int actions = state.numActions;
	state.handCount[0] = 1;
	cardsInHand = state.handCount[0];
	
	printf("\nCard Test 3: Village\n\n");

	state.hand[0][0] = village;
	result = cardEffect(village, 0, 0, 0, &state, 0, 0);
	
	if (state.numActions == (actions + 2)) printf("+2 Actions: Passed\n");
	else printf("+2 Actions:  Failed\n");
	if (state.handCount[0] == (cardsInHand + 1)) printf("+1 Cards: Passed\n");
	else printf("+1 Cards:  Failed\n");
	
	
	printf ("\nEnd Village Card Test\n\n");
	
	return 0;
}