#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState state;
	int result;
	
	printf("\nUnit Test 1: buyCard()\n\n");

	printf("Not enough buys: ");
 	state.numBuys = 0;
	state.coins = 6;
	result = buyCard(2, &state);
	if (result == -1) printf("Passed\n");
	else printf("Failed\n");

	printf("Not enough money: ");
	state.numBuys = 2;
	state.coins = 2;
 	result = buyCard(2, &state);
	if (result == -1) printf("Passed\n");
	else printf("Failed\n");
	
	printf("Successful purchase: ");
	state.coins = 20;
	result = buyCard(2, &state);
	if (result == 0) printf("Passed\n");
	else printf("Failed\n");

 	printf("\nEnd Unit Test 1\n\n"); 
	
 	return 0;	
}