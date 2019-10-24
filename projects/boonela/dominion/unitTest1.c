#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){


int k[10]= {ambassador, seahag, seahag, baron, mine, smithy, great_hall, adventurer, mine, mine};
int numPlayer=2;
int maxHandCount = 5;


struct gameState G;
int p,i,handCount;
int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];
for (i = 0; i< MAX_HAND; i++){
	coppers[i] = copper;
	silvers[i]=silver;
	golds[i]=gold;
}
printf("TESTING baron");
for (p=0;p<numPlayer; p++){
	for(handCount=1; handCount <maxHandCount; handCout++){
	
}
return 0;
}
