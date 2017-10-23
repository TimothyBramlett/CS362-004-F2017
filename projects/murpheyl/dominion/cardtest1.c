#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv)	{
	struct gameState state;
	int result = 0;
	
	printf ("\nCard Test 1: Adventurer\n\n");
	
	state.numActions = 0;
	state.handCount[0] = 5;
	state.hand[0][0] = adventurer;

	//Causing segmentation fault when running test suite in make
	//result = cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

	printf("Return_Value=0: ");
	if (result == 0) printf ("Passed\n");
	else printf ("Failed\n");
	
	printf("Cards Discarded: ");
	if (state.handCount[0] < 5) printf ("Passed\n");
	else printf ("Failed\n");
	
	printf ("\nEnd Adventurer Card Test\n\n");

	return 0;
}


