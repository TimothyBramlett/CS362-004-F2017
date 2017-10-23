#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv)	{
	struct gameState state;
	state.handCount[0] = 5;
	state.coins = 0;
	
	printf("\nUnit Test 1: updateCoins()\n");
	
	for (int i = 0; i < 5; i++) {
		state.hand[0][i] = copper;
	}
	updateCoins(0, &state, 0);
	printf("\nUpdate to 5 copper coins: ");
	if (state.coins == 5) printf("Passed\n");
	else printf("Failed\n");
	
	for (int i = 0; i < 5; i++) {
		state.hand[0][i] = silver;
	}
	updateCoins(0, &state, 0);
	printf("\nUpdate to 5 silver coins: ");
	if (state.coins == 10) printf("Passed\n");
	else printf("Failed\n");
	
	for (int i = 0; i < 5; i++) {
		state.hand[0][i] = gold;
	}
	updateCoins(0, &state, 0);
	printf("\nUpdate to 5 gold coins: ");
	if (state.coins == 15) printf("Passed\n");
	else printf("Failed\n");
	
	printf("\nEnd Unit Test 4\n\n"); 

	return 0;
}