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
	int pass=0, fail =0;
	int k[10] = {baron, baron, sea_hag, tribute, smithy, mine, village, embargo, ambassador, great_hall};
	int cards[10];
	srand(time(NULL));
	printf("Testing Baron Card\n");
	for(i =0; i < 1000; i++){
		initializeGame(numPlayers, k, seed, &G);
	//	int deck = rand()%(MAX_DECK);
		//int handSize = rand() %(deck);
	//	handCount = rand() % MAX_HAND;
		coins = G.coins;
	//	G.deckCount[0] = deck - handCount;
		G.handCount[0] = 10;
		for(j = 0; j< 10; ++j){
			G.hand[0][j] = rand() % 27;
		}
		G.supplyCount[1] = -1;	
		handCount = G.handCount[0];
	//	G.handCount[0]= handCount;
		
		//G.handCount[0] = handSize;
		//G.deckCount[0] = deck - handSize;
		playBaron(&G,0, i, 0);
		if(G.coins != (coins + 4)){
		fail++;
		//	printf("Fail - to many coins gained\n");
		}
		else if (G.coins == (coins +4)){
			pass++;
		//	printf("Pass - four coins gained\n");
		}
		if(G.handCount[0] != (handCount+1)){
			fail++;
	//		printf("Fail - did not get estate\n");
		}
		else if(G.handCount[0] == (handCount+1)){
				pass++;	
	//	printf("Pass - gained estate\n");
		}

		//G.supplyCount[1] = -1;
	
	}
printf("passed: %d tests\n", pass);
printf("failed: %d tests\n", fail);
return 0;
}
