#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv)	{
	struct gameState state;
	int return_value;
	
	printf ("\nCard Test 4: Great Hall\n\n");

	state.numActions = 0;
	state.handCount[0] = 1;
	state.hand[0][0] = great_hall;
	return_value = cardEffect(great_hall, 0, 0, 0, &state, 0, 0);
	if (return_value == 0) printf("Return_Value=0: Passed\n");
	else printf("Return_Value=0: Failed\n");
	if (state.handCount[0] == 1) printf("Cards=1: Passed\n");
	else printf("Cards=1: Failed\n");
	if (state.numActions == 1) printf("Actions=1: Passed\n");
	else printf("Actions=1: Failed\n");
	
	printf ("\nEnd Great Hall Card Test\n\n");
	
	return 0;
}