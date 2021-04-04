#include<stdio.h>
#include<stdlib.h>

void display_array(int *a){
	for(int i=0;a[i]!=-1;i++){
		printf("%d ",a[i]);
	}
}

void dfs(int s,int *visited,int *op,int *ob_rs,int tab[10][10],int state_n){
	int j=0;
	op[*(ob_rs)]=s;
	visited[s]=1;	
	for(j=0;j<s;j++){
		if(tab[s][j]!=1 && visited[j]!=1){
			(*ob_rs)+=1;
			dfs(j,visited,op,ob_rs,tab,state_n);
		}
		
	}
	for(j=s+1;j<state_n;j++){
		if(tab[j][s]!=1 && visited[j]!=1){
			(*ob_rs)+=1;
			dfs(j,visited,op,ob_rs,tab,state_n);
		}
		
	}
}

int isInside(int *a,int b){	
	for(int i=0;a[i]!=-1;i++){
		if(a[i]==b){
			return 1;
		}
	}	
	return 0;
}




int getSt(int a,int arr[10][10],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;arr[i][j]!=-1;j++){
			if(a==arr[i][j]){
				return i;
			}
		}
	}
}
void main(){
	int a[10][10],i,j,k,x,y;
	char ip_lst[10];
	int isModed=1,f[10],state_n,ni,tab[10][10];
	int states[10][10],newcount,newpos,visited[10];
	int final_op[10][10],index=0;
	
	printf("Enter the no. of states:");
	scanf("%d",&state_n);
	printf("Enter the no. of input symbols:");
	scanf("%d",&ni);
	printf("Enter the input symbols:\n");	
	for(i=0;i<ni;i++){
		scanf("\n%c",&ip_lst[i]);
	}
	printf("Enter output for the following:\n");
	for(i=0;i<state_n;i++){
		for(j=0;j<ni;j++){
			printf("f(%d,%c) : ",i,ip_lst[j]);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the final states, -1 to stop:\n");
	for(i=0;;i++){
		scanf("%d",&f[i]);
		if(f[i]==-1){
			break;
		}
	}
	printf("\n\n");
	for(i=1;i<state_n;i++){
		for(j=0;j<i;j++){
			if((isInside(f,i)+isInside(f,j))==1){
				tab[i][j]=1;
			}
			else{
				tab[i][j]=0;
			}
		}
	}
	isModed=1;
	while(isModed==1){
		isModed=0;
		for(i=1;i<state_n;i++){
			for(j=0;j<i;j++){
				for(k=0;k<ni;k++){
					x=a[i][k];
					y=a[j][k];
					if(tab[x][y]==1){
						if((x-y)>0 && tab[i][j]!=1){
							tab[i][j]=1;
							isModed=1;
						}
					}
					else if(tab[y][x]==1){
						if((x-y)<0 && tab[i][j]!=1){
							tab[i][j]=1;
							isModed=1;
						}
					}
				}
			}
		}	
			
	}/*
	for(i=1;i<state_n;i++){
		for(j=0;j<i;j++){
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}//io end*/
	
	
	printf("\n\n\n");
	for(i=0;i<state_n;i++){
		visited[i]=0;
	}
	for(i=0,newcount=0;i<state_n;i++){
		if(visited[i]!=1){
			newpos=0;
			dfs(i,visited,states[newcount],&newpos,tab,state_n);
			states[newcount][newpos+1]=-1;
			newcount+=1;
		}
	}
	printf("\n\nThe new states are:\n");
	for(i=0;i<newcount;i++){
		for(j=0;states[i][j]!=-1;j++){
			printf("%d ",states[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<newcount;i++){
		for(j=0;j<ni;j++){
			x=states[i][0];
			index=getSt(a[x][j],states,newcount);
			final_op[i][j]=index;
		}
	}
	printf("\n\nThe new transitions are:\n");
	int fg=0;
	for(i=0;i<newcount;i++){
		for(k=0;states[i][k]!=-1;k++){
			if(isInside(f,states[i][k])){
				fg=1;
				//printf("[ final state ]\t");
				break;
			}
		}
		for(j=0;j<ni;j++){			
			printf("D([ ");
			for(k=0;states[i][k]!=-1;k++){
				//if(states[i][k+1]==-1)
					//printf("%d",states[i][k]);
				//else
					printf("%d ",states[i][k]);
			}
			printf("], %c) = [",ip_lst[j]);
			display_array(states[final_op[i][j]]);
			printf("]\t");
			
		}
		if(fg==1){
			printf("(final state)");
			fg=0;				
		}
		printf("\n\n");
	}
	
}
