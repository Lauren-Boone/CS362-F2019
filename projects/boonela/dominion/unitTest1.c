#include "dominion.h"
//#include "dominion.c"
#include "rngs.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>



int main(){

int k[10]= {ambassador, sea_hag, sea_hag, baron, mine, smithy, great_hall, adventurer, mine, mine};
int numPlayer = 4;
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
G.supplyCount[1] = -1;
printf("TESTING BARON\n");
for(p=0; p<numPlayer; p++){
	for(handCount =1; handCount <= maxHandCount; handCount++){
		//memset(G, 23, sizeof( struct gameState));
		d=initializeGame(numPlayer, k, seed, &G);
		G.handCount[p]=handCount;
		memcpy(G.hand[p], coppers, sizeof(int) * handCount);
		r = G.discardCount[p];
		d = numHandCards( &G);
		baronCard(p, p,0 , 0, &G);
		assert(G.discardCount[p] == r);
		assert(numHandCards(&G) ==d);
		d++;
		
	}

}


return 0;
}
