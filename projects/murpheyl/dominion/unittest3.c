#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
	struct gameState state;
	int result;
	
	printf("\nUnit Test 3: isGameOver()\n\n");

	printf("Supply Count Cards=0, Game Ends: ");
	state.supplyCount[province] = 0;
	result = isGameOver(&state);
	if (result == 1) printf("Passed\n");
	else printf("Failed\n");

	printf("\nEnd Unit Test 3\n\n");
	
	return 0;
} 