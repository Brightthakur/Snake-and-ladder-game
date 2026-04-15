#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *f;
	int i;
	f = fopen("writing.txt","w");
	for(i=0;i<100;i++){
		fprintf(f,"%d\n",rand()%100);
	}
	fclose(f);
	printf("100 Random numbers saved successfully ---- ");
	
	// Reading From a file ------
	int num;
	printf("\n\n 100 Random numbers are :-\n\n");
	 f = fopen("writing.txt","r");
	 while(fscanf(f,"%d",&num)!=EOF){
	 	printf("%d  ",num);
	 }
	fclose(f);
	return 0;
	}
