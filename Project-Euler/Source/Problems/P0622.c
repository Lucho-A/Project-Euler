/*
	Riffle Shuffles
	Problem 622
149516, 400002, 1064626, 1400908, 1641256
	28 abr. 2019
 */

#include "libEuler.h"
#define S(N) 60
#define N 100

typedef struct Card{
	struct Card *next;
	int value;
}Card;


void P0622(void){
	time_t tInit=clock();
	struct Card *deck=NULL, *auxDeck=NULL, *rightH=NULL;
	long unsigned int cont=1, ok=FALSE, reps=0, sum=0;
	for(long unsigned int cards=2;cards<N;cards+=2){
		auxDeck=deck;
		rightH=NULL;
		reps=0;
		ok=0;
		for(long unsigned int i=cards;i>0;i--){
			struct Card *card=malloc(sizeof(Card));
			card->next=deck;
			card->value=i;
			deck=card;
		}
		while(ok==FALSE){
			if(reps>59) break;
			auxDeck=deck;
			cont=1;
			reps++;
			while(cont++!=cards/2) auxDeck=auxDeck->next;
			rightH=auxDeck->next;
			auxDeck->next=NULL;
			auxDeck=deck;
			while(auxDeck!=NULL){
				struct Card *aux=rightH->next;
				rightH->next=auxDeck->next;
				auxDeck->next=rightH;
				auxDeck=(auxDeck->next)->next;
				rightH=aux;
			}
			auxDeck=deck;
			cont=1;
			ok=1;
			while(auxDeck!=NULL){
				if(auxDeck->value!=cont){
					ok=0;
					break;
				}
				auxDeck=auxDeck->next;
				cont++;
			}
			auxDeck=deck;
			if(ok==1){
				if(reps==S(N)){
					//printf("Cards: %lu\n",cards);
					sum+=cards;
					break;
				}
			}
		}
	}
	time_t tEnd=clock();
	printf("Problem 622 - Result: %lu. Elapsed Time: %.6f\n", sum,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
