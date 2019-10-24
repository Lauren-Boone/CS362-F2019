#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){

int k[10]= {ambassador, seahag, seahag, baron, mine, smithy, great_hall, adventurer, mine, mine};
int numPlayer = 2;
int seed = 1000;
struct gameState G;

int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];
int p, i, handCount, r;
for (i=0; i < MAX_HAND; i++){
	coppers[i] = copper;
	silvers[i] = silver;
	golds[i]=gold;
}

printf("TESTING BARON");
for(p=0; p<numPlayer; p++){
	for(handCount =1; handCount <= maxHandCount; handCount++){
		memset(&G, 23, sizeof( struct gameState));
		r= initializeGame(numPlayer, k, seed, &G);
		G.handCount[p]=handCount;
		memcpy(G.hand[p], coppers, sizeof(int) * handCount);
		r = G.discardCount[p];
		baronCard(p, 0, , 0 , 0, &G);
		assert(G.discardCount[p] == r);
	}
}
return 0;
}
