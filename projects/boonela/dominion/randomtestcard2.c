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
	int numPlayers =2;
	int i,j,coins, pass=0, fail=0;
	struct gameState G;
	int k[10] = {minion, baron, sea_hag, tribute, smithy, mine, village, embargo, ambassador, great_hall};
printf("Testing Minion card\n");
//	int cards[10];
	srand(time(NULL));
	for( i = 0; i < 1000; ++i){
		j= initializeGame(numPlayers, k, seed, &G);

		coins = G.coins;
		G.handCount[0] = 10;
		G.handCount[1] = rand() % MAX_HAND;
		int oppHand = G.handCount[1];
		for(j = 0; j< 10; ++j){
			G.hand[0][j] = rand() % 27;
		}
		//initializeGame(numPlayers, k, seed, &G);
		//initializeGame(numPlayers, k, seed, &G);

		int choice1 = rand()%2;
		int choice2 = rand() %2;
		minionCard(0, choice1, choice2, 0, &G,0);
		if(choice1){
			if(G.coins != (coins +2)){
			//	printf("Fail - did not gain to coins\n");
				fail++;
			}
			else{
				pass++;
			//	printf("Pass - gained 2 coins\n");
		}
	}
		if(choice2){
			fail++;
			if(G.handCount[0] != 4){
			//	printf("Fail - did not discard cards and gain four\n");
			fail++;
			}
			if(G.handCount[0] >10){
			//	printf("Fail - did not discard before drawing\n");
				fail++;
			} 	
			if(oppHand >=5 && G.handCount[1] > 4){
			//	printf("Fail - opponent did not discard cards\n");
				fail++;
			}
			else if(oppHand >=5 && G.handCount[1] == 4){
			//	printf("pass - opponent didscard all cards and gained 4\n");
				pass++;
				}
		}
	}
printf("Failed: %d tests\n", fail);
printf("Passed: %d tests\n", pass);
return 0;
}
			
