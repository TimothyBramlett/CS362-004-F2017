#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONNAME "endTurn()"


int main () {

    int i, n, r, p, deckCount, discardCount, handCount, result;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing %s\n-------------------------------\n", FUNCTIONNAME);

    int num_players = 2;
    r = initializeGame(num_players, k, 1, &G);

    G.numActions = 0;
    G.coins = 0;
    G.numBuys = 0;
    // printState(&G);

    endTurn(&G);

    // printState(&G);

    char msg[] = "when actions were reset.";
    if (G.numActions > 0)
        printf("%s: PASS %s\n", FUNCTIONNAME, msg);
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, msg);

    char msg2[] = "Turn changed to next player.";
    if (G.whoseTurn == 1 )
        printf("%s: PASS %s\n", FUNCTIONNAME, msg2);
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, msg2);

    char msg3[] = "when coins were reset.";
    if (G.coins > 0)
        printf("%s: PASS %s\n", FUNCTIONNAME, msg3);
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, msg3);

    char msg4[] = "when buys were reset.";
    if (G.numBuys > 0)
        printf("%s: PASS %s\n", FUNCTIONNAME, msg4);
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, msg4);

    // G.whoseTurn = 1;
    // result = buyCard(3, &G);
    // char msg2[] = "when buying card with more coins than have.";
    // if (result == -1)
    //     printf("%s: PASS %s\n", FUNCTIONNAME, msg2);
    // else
    //     printf("%s: FAIL %s\n", FUNCTIONNAME, msg2);

    // G.numBuys = 0;
    //     result = buyCard(1, &G);
    // char msg3[] = "when trying to buy card with no buys left.";
    // if (result == -1)
    //     printf("%s: PASS %s\n", FUNCTIONNAME, msg3);
    // else
    //     printf("%s: FAIL %s\n", FUNCTIONNAME, msg3);


    return 0;


}
