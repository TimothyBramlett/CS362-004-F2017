#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONNAME "village"


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
    addCardToHand(0, village, &G);


    // int prior_hand_count = numHandCards(&G);

    // int p_coints = countHandCoins(0, &G);

    int p_discard = G.discardCount[0];
    int p_actions = G.numActions;
    playCard(0, 0, 0, 0, &G);
    int discard = G.discardCount[0];
    int actions = G.numActions;

    if (discard - p_discard == 1)
        printf("%s: PASS %s\n", FUNCTIONNAME, "village increased cards");
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, "village did not increase cards properly");

    if (actions - p_actions == 2)
        printf("%s: PASS %s\n", FUNCTIONNAME, "village increased actions by 2");
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, "village did NOT increase actions by 2");






    return 0;


}
