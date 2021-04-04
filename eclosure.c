#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tostate{
	int a;
	char i;
	int b[10];
}tostate;

void main(){
	tostate tab[10];
	int n,inp,size=-1;
	printf("Enter the no. of states:");
	scanf("%d",&n);
	printf("Enter the different inputs:");
	while(tmp!=-1){
		scanf("%d",&inp[]);
	}
	for(int i=0;i<n;i++){
		
		for(int j=0;j<inp;j++){
			size++;
			tab[size].i;
			printf("Enter the output state of %d on %d:",i,inp);
			int tmp;int k=0;
			while(tmp!=-1){
				scanf("%d",&tab[size].b[k]);
				tmp=tab[i].b[k];
				k++;
			}
		}
		tab[size].a=i;
	}
}
