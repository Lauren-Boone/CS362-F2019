#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>



int main(){

int k[10]= {ambassador, sea_hag, sea_hag, baron, mine, smithy, great_hall, adventurer, mine, mine};
int numPlayer = 2;
int seed = 1000;
struct gameState G;
int maxHandCount=5;
int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];
int p, i, handCount, r,d;
for (i=0; i < MAX_HAND; i++){
	coppers[i] = copper;
	silvers[i] = silver;
	golds[i]=gold;
}
//int result;
G.supplyCount[1] = -1;
printf("TESTING BARON\n");
for(p=0; p<numPlayer; p++){
//	for(handCount =1; handCount <= maxHandCount; handCount++){
		//memset(G, 23, sizeof( struct gameState));
		d=initializeGame(numPlayer, k, seed, &G);
		G.handCount[p]=handCount;
		memcpy(G.hand[p], coppers, sizeof(int) * handCount);
		r = G.discardCount[p];
		int coins= G.coins;
		d = numHandCards( &G);
		playBaron(&G,p, p, 0);
		// assert(G.discardCount[p] == r);
		
	if(p!=0){
		printf("\nTesting if estate card discarded and 4 coins gained\n");
		if(G.coins>coins){
			printf("----Pass- gained four coins\n");
		}
		else{
			printf("----Fail - did not gain four coins\n");
		}
		if(G.coins == (coins +8)){
			printf("----Fail - did not mark estate card as discarded");
		}
			
		
		if(G.discardCount[p] == r){
			printf("----Fail - player did not discard\n");
		}	
		else{
			printf("----Pass -player discarded\n");
		}
	//	assert(numHandCards(&G) ==d);
	//
	}
	if(p==0){
		int estateCheck = 0;
		printf("Testing to get an estate card from supply\n");
		for(int j = 0; j<G.handCount[p]; ++j){
			if(G.hand[p][i] == estate){
				estateCheck++;
			}
		}
		if(estateCheck >0){
			printf("----Pass- the player gained an estate\n");
		}
		else{
			printf("----Fail- the played did not gain an estate\n");
		}
	}
		d++;
		
//	}

}


return 0;
}
