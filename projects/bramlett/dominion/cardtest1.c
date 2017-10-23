#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONNAME "smithy"


int main () {

    int i, n, r, p, deckCount, discardCount, handCount, result;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing %s\n-------------------------------\n", FUNCTIONNAME);

    int num_players = 2;
    r = initializeGame(num_players, k, 1, &G);



    // printState(&G);
    // printHand(0, &G);
    // printf("%d\n", playCard(2, 0, 0, 0, &G));
    endTurn(&G);
    G.whoseTurn = 0;
    // printHand(0, &G);
    addCardToHand(0, smithy, &G);
    int prior_hand_count = numHandCards(&G);
    // printHand(0, &G);
    playCard(0, 0, 0, 0, &G);
    // printState(&G);
    // printHand(0, &G);

    int hand_count = numHandCards(&G);
    if (hand_count - prior_hand_count == 2)
        printf("%s: PASS %s\n", FUNCTIONNAME, "Smithy increased cards by 3");
    else
        printf("%s: FAIL %s\n", FUNCTIONNAME, "Smithy did not increase cards by 3");






    return 0;


}
