

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>


int main(){
	int seed = 1000;
	int numPlayers =3;
	int i,j,coins, pass=0, fail=0, numActions;
	struct gameState G;
	int k[10] = {tribute, baron, sea_hag, tribute, smithy, mine, village, embargo, ambassador, great_hall};
printf("\nTesting Tribute card\n");
//	int cards[10];
	srand(time(NULL));
	for( i = 0; i < 1000; ++i){
		j= initializeGame(numPlayers, k, seed, &G);
		coins=G.coins;
		numActions=G.numActions;
		G.handCount[1]= 10;
		G.handCount[0]=10;
		for(j=0; j<10; ++j){//opponent hand for reveal (randomize_
			G.hand[1][j]=rand()%27;
		}
		
		tributeCard(0,1, 0,0,0,0,&G);
		if(G.coins > coins || G.numActions > numActions || G.handCount[0] >10){
			if(G.coins > coins || G.numActions > numActions || G.handCount[0] >10){
			pass++;
			}
			else{
				fail++;
			}
		}
		
		//Set up for duplications
		G.handCount[1]=10;
		for(j=0; j<10; ++j){
			G.hand[1][j]=rand()%27;
		}
		G.hand[1][0]=village;
		G.hand[1][1]=G.hand[1][0];
		coins = G.coins;
		numActions=G.numActions;
		G.handCount[0]=10;
		tributeCard(0,1,0,0,0,0, &G);
		if(G.numActions == numActions-4){
			fail++;
		}
		else if(G.numActions == numActions+2){
			pass++;
		}
		

		G.handCount[1]=0;
		G.handCount[2]=5;
		for(j=0; j<5; ++j){
			G.hand[2][j]=rand()%27;
		}
		tributeCard(0,1,0,0,0,0,&G);
		if(G.handCount[2] ==3){
			pass++;
		}
		else if(G.handCount[2] == 5){
			fail++;
		}

		
		G.discardCount[1] = 2;
		
		G.deckCount[1]=0;
		int discard = G.discardCount[1];
		G.handCount[1]=5;
		for(j=0; j< 5; ++j){
			G.hand[1][j] = rand() %27;
		}
		tributeCard(0,1,0,0,0,0, &G);
		if(G.discardCount[1] > discard){
			pass++;
		}
		else{
			fail++;
		}	


}

printf("Failed %d Tests\n", fail);
printf("Passed %d tests\n", pass);

return 0;
}


