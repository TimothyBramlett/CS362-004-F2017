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
	
	printf("\nCard Test 2: Smithy\n\n");

	state.numActions = 0;
	state.handCount[0] = 1;
	cardsInHand = state.handCount[0];

	state.hand[0][0] = smithy;
	result = cardEffect(smithy, 0, 0, 0, &state, 0, 0);
	
	if (result == 0) printf("Result=0: Passed\n");
	else printf("Result=0: Failed\n");
	if (state.handCount[0] == (cardsInHand + 3)) printf("+3 Cards: Passed\n");
	else printf("+3 Cards:  Failed\n");
	
	
	printf ("\nEnd Smithy Card Test\n\n");
	
	return 0;
}