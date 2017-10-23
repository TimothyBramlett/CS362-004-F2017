#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONNAME "council_room"


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
    addCardToHand(0, council_room, &G);

    int p_discard = G.discardCount[0];
    int p_hcount = G.handCount[0];
    playCard(0, 0, 0, 0, &G);
    int discard = G.discardCount[0];
    int c_hcount = G.handCount[0];

    if (c_hcount - p_hcount == 3)
        printf("%s: PASS %s\n", FUNCTIONNAME, "council_room increased hand cards by 4");
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, "council_room did not increase hand cards properly.");







    return 0;


}
