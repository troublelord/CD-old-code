#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct{
	int i;
	char inp;
	int f;
}tostate;

void printEclos(int a,tostate *tostates, int *vst,int n){
	printf("%d ",a);
	vst[a]=1;
	for(int i=0;i<n;i++){
		if(tostates[i].i==a && tostates[i].inp=='e'){
			if(vst[tostates[i].f]==0){
				printEclos(tostates[i].f,tostates,vst,n);
			}
		}
	}
}

int isInside(int a,int arr[100],int n){
	for(int i=0;i<n;i++){
		if(arr[i]==a){
			return 1;
		}
	}
	return 0;
}
void main(){
	tostate a[100];
	int temp,i=0;
	int j,ntemp,n,vst[100],tlist[100];
	printf("Enter transition function elements, enter -07 to stop\n\n");
	do{
		printf("Current state: ");
		scanf("%d",&temp);
		if(temp!=-07)
			a[i].i=temp;
		else
			break;
		printf("Input: ");
		scanf("\n%c",&(a[i].inp));
		printf("Next State: ");
		scanf("%d",&(a[i].f));
		i++;
	}while(1);
	n=i;
	//for(i=0;i<n;i++){
		//printf("f(%d,%c) = %d\n",a[i].i,a[i].inp,a[i].f);
	//}
	j=0;
	for(i=0;i<n;i++){
		if(!isInside(a[i].i,tlist,j)){
			tlist[j]=a[i].i;
			j+=1;
		}
		if(!isInside(a[i].f,tlist,j)){
			tlist[j]=a[i].f;
			j+=1;
		}
	}
	ntemp=j;
	for(i=0;i<ntemp;i++){
		for(j=0;j<ntemp;j++){
			vst[tlist[j]]=0;
		}
		printf("e-closure(%d)={ ",tlist[i]);
		
		printEclos(tlist[i],a,vst,n);
		printf("}\n");
	}
}
