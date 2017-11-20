#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONNAME "drawCard()"


int main () {

    int i, n, r, p, deckCount, discardCount, handCount;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing %s\n-------------------------------\n", FUNCTIONNAME);

    int num_players = 2;
    r = initializeGame(num_players, k, 1, &G);

    int cur_cards_player_one = G.handCount[0];
    drawCard(0, &G);
    if (G.handCount[0] == cur_cards_player_one + 1)
        printf("%s: PASS when testing draw card on player 1\n", FUNCTIONNAME);
    else
        printf("%s: FAIL when testing draw card on player 1\n", FUNCTIONNAME);

    int cur_cards_player_two = G.handCount[1];
    drawCard(1, &G);
    if (G.handCount[1] == cur_cards_player_two + 1)
        printf("%s: PASS when testing draw card on player 2\n", FUNCTIONNAME);
    else
        printf("%s: FAIL when testing draw card on player 2\n", FUNCTIONNAME);



    // int fullDeckCount(int player, int card, struct gameState *state);
    // /* Here deck = hand + discard + deck */



    // if (r == 0)
    //     printf("%s: PASS when test containing %d as number of players\n", FUNCTIONNAME, num_players);
    // else
    //     printf("%s: FAIL when test containing %d as number of players\n", FUNCTIONNAME, num_players);

    // num_players = 3;
    // r = initializeGame(num_players, k, 1, &G);
    // if (r == 0)
    //     printf("%s: PASS when test containing %d as number of players\n", FUNCTIONNAME, num_players);
    // else
    //     printf("%s: FAIL when test containing %d as number of players\n", FUNCTIONNAME, num_players);
    
    // num_players = 0;
    // r = initializeGame(num_players, k, 1, &G);
    // if (r == -1)
    //     printf("%s: PASS when test containing %d as number of players\n", FUNCTIONNAME, num_players);
    // else
    //     printf("%s: FAIL when test containing %d as number of players\n", FUNCTIONNAME, num_players);

    // num_players = 1;
    // r = initializeGame(num_players, k, 1, &G);
    // if (r == -1)
    //     printf("%s: PASS when test containing %d as number of players\n", FUNCTIONNAME, num_players);
    // else
    //     printf("%s: FAIL when test containing %d as number of players\n", FUNCTIONNAME, num_players);

    // num_players = 100;
    // r = initializeGame(num_players, k, 1, &G);
    // if (r == -1)
    //     printf("%s: PASS when test containing %d as number of players\n", FUNCTIONNAME, num_players);
    // else
    //     printf("%s: FAIL when test containing %d as number of players\n", FUNCTIONNAME, num_players);

    return 0;


}
