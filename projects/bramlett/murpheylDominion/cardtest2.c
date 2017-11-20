#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONNAME "adventurer"


int main () {

    int i, n, r, p, deckCount, discardCount, handCount, result;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing %s\n-------------------------------\n", FUNCTIONNAME);

    int num_players = 2;
    r = initializeGame(num_players, k, 1, &G);

    endTurn(&G);
    G.whoseTurn = 0;
    addCardToHand(0, adventurer, &G);
    int prior_hand_count = numHandCards(&G);

    int p_coints = countHandCoins(0, &G);

    playCard(0, 0, 0, 0, &G);

    int coints = countHandCoins(0, &G);
    // printf("%d - %d\n", p_coints, coints);
    if (coints - p_coints == 3)
        printf("%s: PASS %s\n", FUNCTIONNAME, "Adventurer increased treasure.");
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, "adventurer did not increase treasure enough.");

    return 0;


}
