#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>


int main(){

	int seed = 1000;
	int numPlayers=2;
	struct gameState G;
	int i, j, handpos =0, coins, handCount;
	int k[10] = {baron, minion, sea_hag, tribute, smithy, mine, village, embargo, ambassador, great_hall};

	srand(time(NULL);
	printf("Testing Baron Card\n");
	for(i =0; i < 1000; i++){
		initializeGame(numPlayers, k, seed, &G);
		coins = G.coins;
		handCount = G.handCount[0];
		baronCard(0, i, 0, 0, &G);
		if(G.coins > (coins + 4)){
			printf("Fail - to many coins gained\n");
		}
		else if (G.coins == (coins +4)){
			printf("Pass - four coins gained\n");
		}
		if(G.handCount[0] != (handCount+1){
			printf("Fail - did not get estate\n");
		}
		else if(G.handCount[0] == (handCount+1)){
			printf("Pass - gained estate\n");
		}

		G.supplyCount[1] = -1;
	
	}
return 0;
}
