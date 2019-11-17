#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int numHandCards(struct gameState *state);

int main(){


int k[10] = {ambassador, sea_hag, gardens, mine, mine, gardens, baron, great_hall, baron, adventurer};

int seed = 1000;
int i, p, r, handCount=1, discard;
int maxHandCount = 5;
struct gameState G;
int numPlayer = 2;


printf("\nTesting Ambassador\n");

for (p = 0; p< numPlayer; ++p){
//	for(handCount = 1; handCount <= maxHandCount; handCount++){
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		discard =G.discard[(p)];
		G.handCount[p]=5;
		if(p==1){
		printf("Testing to see if the opponent gained a card\n");
		G.handCount[(p+1)]=2;
		playAmbassador(&G,p,p, (p+1),(handCount+1));
		if(G.handCount[(p+1)] == 3){
			printf("----Pass - opponet gained card\n");
			
		}
		else{
			printf("----Fail - opponent did not gain card\n");
		}
		}
	
		else{
			printf("testing to see if card was trashed\n");
		int count= G.discardCount[p];
		playAmbassador(&G,p,p,p,0);
		//for(i=0; i<G.discardCount[p]; ++p){
		//	if(G.discard[p][i] == p){
		//		count++;
		//}		
		if((count+2) == count){
			printf("----Fail -- too many cards discarded");
		}
		else{
			printf("----Pass - One card discarded\n");
		}
		
	}
//}
}
return 0;
}


