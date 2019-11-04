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
	int p, r, handCount=1, n,h;
	int k[10]= {tribute, minion, council_room, feast, gardens, mine, sea_hag, smithy, village, baron, great_hall};
	struct gameState G;
	int maxHandcount=5;
	n=1;

printf("\nTesting Tribute card\n");
	for(p=0; p<numPlayer; p++){
		
		memset(&G, 23,sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		h= G.handCount[n];
		G.deckCount[n] = 2;	
		if(p==0){
		printf("Testing if duplicate for duplicate bug\n");
		G.hand[n][0] = estate;
		G.hand[n][1]= estate;
		int c = G.handCount[p];
		tributeCard(p,n,p,p,p,0, &G);
		if((c+2)!=G.handCount[p]){
			printf("----Fail -- The duplicate was not discarded\n");
			
		}
		else{
			printf("----Pass - duplicated discarded\n");
		}
		}
		else{
		printf("Testing for bug that removes actions instead of awarding 2\n");
		int actions = G.numActions;
		tributeCard(p,(n-1), p,p,p,0,&G);
		if(G.numActions != (actions +2)){
			printf("----Fail - Bug removed 2 actions\n");
		}
		else{
			printf("----Pass - Bug did not remove 2 actionn\n");
		}
		}
	//	assert((G.numActions >1) || G.coins >=2 || G.handCount[p] >2);
		//assert(G.handCount[n] <h); 
	}
return 0;
}
