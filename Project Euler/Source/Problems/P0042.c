/*
	Coded triangle numbers
	Problem 42

	The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

	By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value.
	For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

	Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

	23 dic. 2018
 */

#include "libEuler.h"
#define WORDS 1789

int sumLetters(char *word){
	char letters[28]={" ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int len=strlen(word), sum=0;
	for(int i=0;i<len;i++){
		for(int j=0;j<28;j++){
			if(word[i]==letters[j]) sum+=j;
		}
	}
	return sum;
}

int isTriangle(int sumOfLetters){
	int result=0;
	for(int n=1;result<=sumOfLetters;n++){
		result=n+1;
		result=result*n/2;
		if(result==sumOfLetters && result!=0) return TRUE;
	}
	return FALSE;
}
void P0042(void){
	time_t tInit=clock();
	FILE *f;
	int i=0, sum=0, cont=0;
	char wordsInFile[WORDS * 50]="", words[WORDS][50]={""}, *word=NULL, c=' ';
	const char s[2] = ",";
	if((f=fopen("Resources/P0042/p042_words.txt","r"))==NULL){
		printf("File error\n");
		exit(1);
	}
	while((c=getc(f)) != EOF){
		wordsInFile[i]=c;
		i++;
	}
	fclose(f);
	i=0;
	word=strtok(wordsInFile, s);
	while(word != NULL) {
		strcpy(words[i],word);
		word=strtok(NULL, s);
		i++;
	}
	for(int i=0;i<WORDS;i++){
		sum=sumLetters(words[i]);
		if(isTriangle(sum)==TRUE) cont++;
	}
	time_t tEnd=clock();
	printf("Problem 42 - Result: %d. Elapsed Time: %.6f\n", cont,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
