/*
	Names scores
	Problem 22

	Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
	containing over five-thousand first names, begin by sorting
	it into alphabetical order. Then working out the alphabetical value for each
	name, multiply this value by its alphabetical position in the list to obtain
	a name score.

	For example, when the list is sorted into alphabetical order, COLIN, which is
	worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
	So, COLIN would obtain a score of 938 × 53 = 49714.

	What is the total of all the name scores in the file?
	24 sep. 2018
 */

#include "libEuler.h"

void sort(char names[10000][50], int qNames){
	char buffer[10000]="";
	for(int i=0;i<qNames-1;i++){
		for(int j=i+1;j<qNames;j++){
			if(strcmp(names[i],names[j])>0){
				strcpy(buffer,names[i]);
				strcpy(names[i],names[j]);
				strcpy(names[j],buffer);
			}
		}
	}
}

int score(char *name, int pos){
	int sum=0;
	int count=0;
	char abc[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	while(strcmp(&name[count],"")){
		for(int i=0;i<27;i++){
			if(name[count]==abc[i]){
				sum+=i+1;
				break;
			}
		}
		count++;
	}
	return sum*pos;
}

void P0022(void){
	time_t tInit=clock();
	FILE *f;
	llu resp=0;
	char namesInFile[100000]="", names[6000][50]={""}, c;
	int i=0, qNames=0;
	const char s[2] = ",";
	char *name;
	if((f=fopen("Resources/P0022/p022_names.txt","r"))==NULL){
		printf("File error\n");
		exit(1);
	}
	while((c=getc(f)) != EOF){
		namesInFile[i]=c;
		i++;
	}
	fclose(f);
	i=0;
	name=strtok(namesInFile, s);
	while(name != NULL) {
		strcpy(names[i],name);
		name=strtok(NULL, s);
		i++;
	}
	while(strcmp(names[qNames],"")) qNames++;
	sort(names, qNames);
	for(int i=0;i<qNames;i++) resp+=score(names[i], i+1);
	time_t tEnd=clock();
	printf("Problem 22 - Result: %llu. Elapsed Time: %.6f\n",resp ,(double) (tEnd-tInit)/CLOCKS_PER_SEC);
	return;
}
