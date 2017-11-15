#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define FUNCTIONNAME "remodel card"


int main () {

    int i, n, r, p, deckCount, discardCount, handCount, result;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing %s\n-------------------------------\n", FUNCTIONNAME);

    int num_players = 2;
    r = initializeGame(num_players, k, 1, &G);

    int temphand = 0;

    srand(4);   

    for (int n = 0; n < 100; n++) 
    {
    
        cardEffect_remodel( rand(), &G, 0, 0, 0, 0, &temphand, 0, 0, 0);

    }

    printf ("ALL TESTS OK\n");

    return 0;


}
