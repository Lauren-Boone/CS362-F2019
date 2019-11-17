#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
	int i;
	int seed = 1000;
	int numPlayer =2;
	int p,r, handCount=1;
	int k[10] = {mine, adventurer, council_room, feast, gardens, minion, remodel, smithy, village, baron, great_hall};
	int maxHandCount = 5,c;
	struct gameState G;
	printf("\nTesting Mine Card\n");
	for(p=0; p<numPlayer; ++p){
		
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		c = getCost(handCount) +3;
		
		if(p==0){
		printf("Testing if bug allows card greater than 3 to be obtained.\n");
		G.hand[p][0]= baron;
		G.deck[p][0]=treasure_map;
		playMine(&G,p,0, treasure_map, handCount);
			if(G.hand[p][0] == treasure_map){
				printf("----Fail - Player gained a card worth more than 3 more\n");
			}
			else if (G.hand[p][0] != treasure_map){
				printf("----Pase - Player did not gain card work more than 3 more\n");
			}
		 
		}
		else {
		printf("Testing if card is properly discarded\n");
			int discardC = G.discardCount[p];
			playMine(&G,p, 0,4, handCount);
			if(discardC == G.discardCount[p]){
				printf("----Fail - Card was not discarded\n");
			}
			else{
				printf("----Pass - Card was discarded\n");
			}
		}
	}
return 0;
}
