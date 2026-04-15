#include<stdio.h>
#include<conio.h>
int main(){
	FILE *fp;
	int i,n;
	printf("how many numbers you want to enter ?");
	scanf("%d",&n);
	
	fp = fopen("sample1.txt","w");
	for(i=1;i<=n;i++){
		putw(i,fp);
	}
	fclose(fp);
	getch();
	return 0;
	}
