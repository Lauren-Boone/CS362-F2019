#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){


int k[10]= {ambassador, sea_hag, sea_hag, baron, mine, smithy, great_hall, adventurer, mine, mine};
int numPlayer=3;
int maxHandCount = 5;
int choice1=1, choice2=2;
int seed=1000;
struct gameState G;
initializeGame(numPlayer, k, seed, &G);


G.handCount[1]=1;
G.handCount[2]=1;
int count1=G.handCount[1];
int count2=G.handCount[2];
G.handCount[0] = 5;
int i;
for(i =0; i<5; ++i){
	G.hand[0][i]=sea_hag;
}
int current=G.handCount[0];
printf("Testing Ambassador card for correctly finding cards in player's hand\n");
cardEffect(ambassador, choice1, choice2, 0, &G, 0,0);

if(G.handCount[1]==count1){
	printf("	Failed: Opponent 1 did not recieve card\n");
}
else{
	printf("	Pass: Correctly counted number of cards\n");
}
if(G.handCount[2]==count2){
	printf("	Failed: Opponent 2 did not recieve card\n");
}
else{
	printf("	Pass: Correctly counted number of cards\n");
}

return 0;
}


