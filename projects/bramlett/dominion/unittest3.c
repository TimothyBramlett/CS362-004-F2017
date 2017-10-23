#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONNAME "buyCard()"


int main () {

    int i, n, r, p, deckCount, discardCount, handCount, result;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing %s\n-------------------------------\n", FUNCTIONNAME);

    int num_players = 2;
    r = initializeGame(num_players, k, 1, &G);

    G.whoseTurn = 0; // player one
    result = buyCard(1, &G);
    char msg[] = "when buying card worth 2.";
    if (result == 0)
        printf("%s: PASS %s\n", FUNCTIONNAME, msg);
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, msg);

    G.whoseTurn = 1;
    result = buyCard(3, &G);
    char msg2[] = "when buying card with more coins than have.";
    if (result == -1)
        printf("%s: PASS %s\n", FUNCTIONNAME, msg2);
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, msg2);

    G.numBuys = 0;
        result = buyCard(1, &G);
    char msg3[] = "when trying to buy card with no buys left.";
    if (result == -1)
        printf("%s: PASS %s\n", FUNCTIONNAME, msg3);
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, msg3);


    return 0;


}
