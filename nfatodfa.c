#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int a[50];
}tab;
int isInside(int *a,int val){
	for(int i=0;a[i]!=-1;i++){
		if(val==a[i]){
			return 1;
		}
	}
	return 0;
}
void merge(int *a,int k){
	int i;
	for(i=0;a[i]!=-1;i++){
		if(a[i]==k){
			return;
		}
	}
	a[i]=k;
	a[i+1]=-1;
	
}
void arraycp(int *a,int *b){
	int i=0;
	a[0]=-1;
	for(i=0;b[i]!=-1;i++){
		a[i]=b[i];
	}
	a[i]=-1;
}

int isUnique(tab *a,tab *b[],int n){
	int i,j,*temp;
	int f=0,len;
	if(a->a[0]==1 && a->a[1]==-1){
		return 0;
	}	
	for(i=0;i<n;i++){		
		temp=b[i]->a;
		f=0;
		if(a->a[0]==-1 && temp[0]==-1){
			
			return 0;
		}		
		for(j=0;a->a[j]!=-1;j++){
			if(isInside(temp,a->a[j])){
				continue;
			}
			f=1;
			break;
		}
		if(f==0){
			for(len=0;temp[len]!=-1;len++);
			if(len==j){
				return 0;
			}
			
		}
	}
	return 1;
}
void printtab(int n, int ni,tab arr_mat[20][20],char lst[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<ni;j++){
			printf("\nF(%d,%c) = {",i+1,lst[j]);
			for(int k=0;arr_mat[i][j].a[k]!=-1;k++){
				printf("%d ",arr_mat[i][j].a[k]);
			
			}
			printf("}");
		}
	}
}
void main(){

	int i,j,temp,n;
	
	char lst[100];
	int ni,k,size_res;


	tab arr_mat[20][20],opstates[20];


	int start=0,enddd=0,count=0,indexnw;
	
	tab outputt[20][20],*tabtmp,*q[100];
	
	printf("Enter the no. of states in NFA:");
	scanf("%d",&n);
	printf("Enter no. of inputs:");
	scanf("%d",&ni);
	printf("Enter the input values:\n");
	for(i=0;i<ni;i++){
		scanf("\n%c",&lst[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<ni;j++){
			printf("Enter outputs of d(%d,%c)\n",i+1,lst[j]);
			
			k=0;
			while(1){
				scanf("\n%d",&temp);
				if(temp==-1){
					arr_mat[i][j].a[k]=-1;
					break;
				}
				arr_mat[i][j].a[k]=temp;
				k+=1;				
			}
		}
	}
	//printtab(n,ni,lst,arr_mat)
	
	opstates[0].a[0]=1;
	opstates[0].a[1]=-1;
	for(i=0;i<ni;i++){
		arraycp(outputt[0][i].a,arr_mat[0][i].a);
		if(isUnique(&(outputt[0][i]),q,enddd)){
			q[enddd]=&(outputt[0][i]);
			enddd+=1;
		}
	}
	count=1;
	while(start<enddd){
		
		tabtmp=q[start];
		start+=1;
		arraycp(opstates[count].a,tabtmp->a);		
		for(i=0;i<ni;i++){
			outputt[count][i].a[0]=-1;
			for(j=0;tabtmp->a[j]!=-1;j++){
				indexnw=tabtmp->a[j]-1;								
				for(k=0;arr_mat[indexnw][i].a[k]!=-1;k++){					
					merge(outputt[count][i].a,arr_mat[indexnw][i].a[k]);
					
				}				
				
			}
			if(isUnique(&(outputt[count][i]),q,enddd)){
				
				q[enddd]=&(outputt[count][i]);
				enddd+=1;
			}			

		}
		count+=1;		
	}
	printf("\n\n");
	for(i=0;i<count;i++){		
		for(j=0;j<ni;j++){
			printf("tf( {");
			int fg=1;
			for(k=0;opstates[i].a[k]!=-1;k++){
				if(fg){
					printf("%d",opstates[i].a[k]);
					fg=0;
				}else
					printf(", %d",opstates[i].a[k]);			
			}
			if(opstates[i].a[0]==-1){
				//f(fg){
				//	printf("NULL,");
				//	fg=0;
				//}else{
					printf("NULL");
				//}
			}		
			printf("} , %c) = ",lst[j]);
			if(outputt[i][j].a[0]==-1){
				printf("NULL\n");
				continue;
			}
			printf("{");
			int flag=1;
			for(k=0;outputt[i][j].a[k]!=-1;k++){
				if(flag){
					printf("%d",outputt[i][j].a[k]);
					flag=0;
				}else
					printf(", %d",outputt[i][j].a[k]);
			}
			printf("}\n");
		}
		printf("\n");		
	}	
	
}
