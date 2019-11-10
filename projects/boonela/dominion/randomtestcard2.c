
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int main(){
	int seed = 1000;
	int numPlayers =2;
	int i,j;
	struct gameState G;
	int k[10] = {minion, baron, sea_hag, tribute, smithy, mine, village, embargo, ambassador, great_hall};

	int cards[10];
	srand(time(NULL));
	for( i = 0; i < 1000; ++i){
		
