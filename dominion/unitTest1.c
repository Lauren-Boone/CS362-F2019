#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(){

int k[10]= {tribute, sea_hag, sea_hag, baron, mine, smithy, great_hall, adventurer, mine, mine};
int numPlayer = 2;
int seed = 1000;
struct gameState G;
int i;

printf("Testing Tribute Cards for awarding actions when duplicates are presented\n");

initializeGame(numPlayer, k, seed, &G);
G.handCount[1]= 5;
for(i=0; i<5; i++){
	G.hand[1][i]=estate;
}

int actions = G.numActions;
G.whoseTurn=0;
	cardEffect(tribute,0,0,0,&G, 0, 0);
if(G.numActions > actions){
	printf("Failed: Player awarded two actions when opponent revealed duplicates\n");
}
else{
	printf("Pass: No actions gained\n");
}

return 0;
} 



