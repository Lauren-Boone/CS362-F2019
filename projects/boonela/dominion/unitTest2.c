#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){


int k[10] = {ambassador, sea_hag, gardens, mine, mine, gardens, baron, great_hall, baron, adventurer};

int seed = 1000;
int i, p, r, handCount, discard;
int maxHandCount = 5;
struct gameState G;
int numPlayer = 3;


printf("Testing Ambassador\n");
for (p = 0; p< numPlayer; ++p){
	for(handCount = 1; handCount <= maxHandCount; handCount++){
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		i = G.handCount[(p+1)];
		discard =G.discardCount[(p+1)];
		ambassadorCard(p, p, p, 0,0, &G);
	//	assert(G.handCount[(p+1)] != i);
	//	assert(G.discardCount[(p+1)] != discard);
	}
}

}


