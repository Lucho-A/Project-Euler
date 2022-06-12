/*
	Poker hands

	Problem 54

	L.

	11 Nov. 2021-23:38:01
*/

#include "../../Src/Headers/libEuler.h"

typedef struct card{
	int value;
	char suite;
}Card;

typedef struct score{
	int value;
	int maxCard1;
	int maxCard2;
	int maxCard3;
	int maxCard4;
	int maxCard5;
}Score;

int evaluateWinner(Score s1, Score s2);
Score evaluate_hand(Card *p);

void P0054(void){
	struct timespec tInit, tEnd;
	// Ver compatibilidad con W64
	//clock_gettime(CLOCK_MONOTONIC_RAW, &tInit);
	FILE *fp=NULL;
	Card j1[5];
	Card j2[5];
	fp = fopen("Resources/P0054/p054_poker.txt", "r");
	if (fp == NULL) exit(EXIT_FAILURE);
	char n[10]="";
	int card=0, value=0;
	Score s1, s2;
	int contW1=0;
	while (fscanf(fp, " %s", n)==1) {
		switch(n[0]){
		case 'T':
			value=10;
			break;
		case 'J':
			value=11;
			break;
		case 'Q':
			value=12;
			break;
		case 'K':
			value=13;
			break;
		case 'A':
			value=14;
			break;
		default:
			value=n[0]-'0';
		}
		if(card<5){
			j1[card].value=value;
			j1[card].suite=n[1];
			card++;
		}else{
			j2[card-5].value=value;
			j2[card-5].suite=n[1];
			card++;
		}
		if(card==10){
			s1=evaluate_hand(j1);
			s2=evaluate_hand(j2);
			int winner=evaluateWinner(s1, s2);
			if(winner==-1){
				printf("The tie persists. Check");
				exit(EXIT_FAILURE);
			}
			if(winner==1)contW1++;
			card=0;
		}
	}
	fclose(fp);
	//clock_gettime(CLOCK_MONOTONIC_RAW, &tEnd);
	double elapsedTime=(tEnd.tv_nsec - tInit.tv_nsec) / 1000000000.0 + (tEnd.tv_sec  - tInit.tv_sec);
	printf("Problem P0054 - Result: %d. Elapsed Time: %.6f secs\n", contW1,elapsedTime);
	return;
}

int evaluateWinner(Score s1, Score s2){
	if(s1.value>s2.value) return 1;
	if(s1.value<s2.value) return 2;
	if(s1.maxCard1>s2.maxCard1) return 1;
	if(s1.maxCard1<s2.maxCard1) return 2;
	if(s1.maxCard2>s2.maxCard2) return 1;
	if(s1.maxCard2<s2.maxCard2) return 2;
	if(s1.maxCard3>s2.maxCard3) return 1;
	if(s1.maxCard3<s2.maxCard3) return 2;
	if(s1.maxCard4>s2.maxCard4) return 1;
	if(s1.maxCard4<s2.maxCard4) return 2;
	if(s1.maxCard5>s2.maxCard5) return 1;
	if(s1.maxCard5<s2.maxCard5) return 2;
	return -1;
}

Score evaluate_hand(Card *p){
	Card aux;
	Score point;
	int cont[5]={1};
	for(int i=0;i<5;i++) cont[i]=1;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<5;j++){
			if(p[i].value > p[j].value){
				aux=p[i];
				p[i]=p[j];
				p[j]=aux;
			}
		}
	}
	if(p[0].value==10
			&& p[1].value==11 && p[1].suite==p[0].suite
			&& p[1].value==12 && p[1].suite==p[0].suite
			&& p[1].value==13 && p[1].suite==p[0].suite
			&& p[1].value==14 && p[1].suite==p[0].suite){
		point.value=10;
		point.maxCard1=-1;
		return point;
	}
	if(p[1].value==p[0].value + 1 && p[1].suite==p[0].suite
			&& p[2].value == p[0].value + 2 && p[2].suite==p[0].suite
			&& p[3].value == p[0].value + 3 && p[3].suite==p[0].suite
			&& p[4].value == p[0].value + 4 && p[4].suite==p[0].suite){
		point.value=9;
		point.maxCard1=p[4].value;
		return point;
	}
	int n=0;
	for(int i=1;i<5;i++){
		if(p[i].value!=p[i-1].value){
			n++;
		}else{
			cont[n]++;
		}
	}
	if(cont[0]==4 || cont[1]==4){
		point.value=8;
		if(cont[0]==4){
			point.maxCard1=p[0].value;
		}else{
			point.maxCard1=p[1].value;
		}
		return point;
	}
	if((cont[0]==3 && cont[1]==2) || (cont[0]==2 && cont[1]==3)) {
		point.value=7;
		if(cont[0]==3){
			point.maxCard1=p[0].value;
		}else{
			point.maxCard1=p[2].value;
		}
		return point;
	}
	if(p[1].suite==p[0].suite
			&& p[2].suite==p[0].suite
			&& p[3].suite==p[0].suite
			&& p[4].suite==p[0].suite){
		point.value=6;
		point.maxCard1=p[4].value;
		return point;
	}
	if(p[1].value==p[0].value + 1
			&& p[2].value == p[0].value + 2
			&& p[3].value == p[0].value + 3
			&& p[4].value == p[0].value + 4){
		point.value=5;
		point.maxCard1=p[4].value;
		return point;
	}
	if(cont[0]==3 || cont[1]==3 || cont[2]==3) {
		point.value=4;
		if(cont[0]==3){
			point.maxCard1=p[0].value;
			return point;
		}
		if(cont[1]==3){
			point.maxCard1=p[1].value;
			return point;
		}
		if(cont[2]==3){
			point.maxCard1=p[2].value;
			return point;
		}
	}
	int pairs=0;
	for(int i=0;i<5;i++){
		if(cont[i]==2){
			pairs++;
		}
	}
	if(pairs==2){
		point.value=3;
		int pairs[2]={0};
		int singleCard=0;
		int ix=0;
		for(int i=0;i<3;i++){
			if(cont[i]==2){
				pairs[ix]=i;
				ix++;
			}else{
				singleCard=i;
			}
		}
		if(p[pairs[0]+1].value>p[pairs[1]+1].value){
			point.maxCard1=p[pairs[0]+1].value;
			point.maxCard2=p[pairs[1]+1].value;
			point.maxCard3=p[singleCard].value;
			return point;
		}else{
			point.maxCard1=p[pairs[1]+1].value;
			point.maxCard2=p[pairs[0]+1].value;
			point.maxCard3=p[singleCard].value;
			return point;
		}
	}
	point.value=2;
	for(int i=0;i<5;i++){
		if(cont[i]==2){
			point.maxCard1=p[i].value;
			if(i==0){
				point.maxCard2=p[4].value;
				point.maxCard3=p[3].value;
				point.maxCard4=p[3].value;
				return point;
			}
			if(i==1){
				point.maxCard2=p[4].value;
				point.maxCard3=p[3].value;
				point.maxCard4=p[0].value;
				return point;
			}
			if(i==2){
				point.maxCard2=p[4].value;
				point.maxCard3=p[1].value;
				point.maxCard4=p[0].value;
				return point;
			}
			if(i==3){
				point.maxCard2=p[2].value;
				point.maxCard3=p[1].value;
				point.maxCard3=p[0].value;
				return point;
			}
		}
	}
	point.value=1;
	point.maxCard1=p[4].value;
	point.maxCard2=p[3].value;
	point.maxCard3=p[2].value;
	point.maxCard4=p[1].value;
	point.maxCard5=p[0].value;
	return point;
}

