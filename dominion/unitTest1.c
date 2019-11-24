#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(){

int k[10]= {tribute,duchy, cutpurse, baron, steward, smithy, great_hall, adventurer, remodel, mine};
int numPlayer = 2;
int seed = 1000;
struct gameState G;
int i;

printf("Testing Tribute Cards for awarding actions when duplicates are presented\n");
//printf("asdf");

int j = initializeGame(numPlayer, k, seed, &G);
//printf("initsdf");
G.handCount[1]= 5;
for(i=0; i<5; i++){
	G.hand[1][i]=estate;
}
G.deckCount[1]=5;
for(i=0; i< 5; ++i){
	G.deck[1][i] = estate;
}
//int j = initializeGame(numPlayer, k, seed, &G);

int actions = G.numActions;
G.whoseTurn=0;
//printf("adsf");
	cardEffect(tribute,0,0,0,&G, 0, 0);
if(G.numActions > actions){
	printf("	Failed: Player awarded two actions when opponent revealed duplicates\n");
}
else{
	printf("	Pass: No actions gained\n");
}

return 0;
} 


