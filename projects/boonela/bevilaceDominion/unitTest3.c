#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(){

	 int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount=1;
	int k[10] = {minion, council_room, feast, gardens, mine
, sea_hag, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5,h;
printf("\nTesting Minion Card\n");
	for(p=0; p< numPlayer; p++){
//	for(handCount=1; handCount <= maxHandCount; handCount++){
		 memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayer, k, seed, &G);
		if(p==0){
		printf("Testing to see if player gained two coins\n");
		h=G.coins;
		playMinion(&G,p, (p+1), p, handCount);
		if(G.coins > h){
			printf("----Passed - player gained 2 coins\n");
		}
		else{
			printf("----Failed - no coins gained\n");
		}
		
		}
		else{
		printf("Testing to see if discarded and gained 4 new cards\n");
		G.handCount[(p-1)] = 5;
		//G.handCount[p] = -1;
		int p2 = G.handCount[(p-1)];
		playMinion(&G,p, 0, 1, handCount);
			if(G.handCount[p] == 4){
				printf("Passed - Player discarded 5 and drew 4\n");
			}
			else{
				printf("---Fail-Player did not discard 5\n");
			}

			
			if(G.handCount[(p-1)] !=4){
				printf("----Fail - opponent did not discard and redraw\n");
			}
			else if(G.handCount[(p-1)] ==4){
				printf("----Pass - opponent discarded and drew 4 cards\n");
			}
		}
//		}
	}
return 0;
}
