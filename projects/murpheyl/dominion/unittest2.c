#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
	
	printf("\nUnit Test 2: getCost()\n\n");

	printf("curse: ");
	if (getCost(curse) == 0) printf("Passed\n");
	else printf("Failed\n");
	printf("estate: ");
	if (getCost(estate) == 2) printf("Passed\n");
	else printf("Failed\n");
	printf("duchy: ");
	if (getCost(duchy) == 5) printf("Passed\n");
	else printf("Failed\n");
	printf("province: ");
	if (getCost(province) == 8) printf("Passed\n");
	else printf("Failed\n");
	printf("copper: ");
	if (getCost(copper) == 0) printf("Passed\n");
	else printf("Failed\n");
	printf("silver: ");
	if (getCost(silver) == 3) printf("Passed\n");
	else printf("Failed\n");
	printf("gold: ");
	if (getCost(gold) == 6) printf("Passed\n");
	else printf("Failed\n");
	printf("adventurer: ");
	if (getCost(adventurer) == 6) printf("Passed\n");
	else printf("Failed\n");
	printf("council_room: ");
	if (getCost(council_room) == 5) printf("Passed\n");
	else printf("Failed\n");
	printf("feast: ");
	if (getCost(feast) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("gardens: ");
	if (getCost(gardens) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("mine: ");
	if (getCost(mine) == 5) printf("Passed\n");
	else printf("Failed\n");
	printf("remodel: ");
	if (getCost(remodel) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("smithy: ");
	if (getCost(smithy) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("village: ");
	if (getCost(village) == 3) printf("Passed\n");
	else printf("Failed\n");
	printf("baron: ");
	if (getCost(baron) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("great_hall: ");
	if (getCost(great_hall) == 3) printf("Passed\n");
	else printf("Failed\n");
	printf("minion: ");
	if (getCost(minion) == 5) printf("Passed\n");
	else printf("Failed\n");
	printf("steward: ");
	if (getCost(steward) == 3) printf("Passed\n");
	else printf("Failed\n");
	printf("tribute: ");
	if (getCost(tribute) == 5) printf("Passed\n");
	else printf("Failed\n");
	printf("ambassador: ");
	if (getCost(ambassador) == 3) printf("Passed\n");
	else printf("Failed\n");
	printf("cutpurse: ");
	if (getCost(cutpurse) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("embargo: ");
	if (getCost(embargo) == 2) printf("Passed\n");
	else printf("Failed\n");
	printf("outpost: ");
	if (getCost(outpost) == 5) printf("Passed\n");
	else printf("Failed\n");
	printf("salvager: ");
	if (getCost(salvager) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("sea_hag: ");
	if (getCost(sea_hag) == 4) printf("Passed\n");
	else printf("Failed\n");
	printf("treasure_map: ");
	if (getCost(treasure_map) == 4) printf("Passed\n");
	else printf("Failed\n");

	printf("\nEnd Unit Test 2\n\n");
	
	return 0;
} 