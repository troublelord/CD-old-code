#include<stdio.h>
#include<string.h>

char inp[50];

char prod[20][10];
int prod_count=0,ptr=0;

char stck[100];
int stck_ptr=0;

void push(int ptr){
	strncat(stck,&inp[ptr],1);
	stck_ptr++;
}
//int a[10];
//int size=0;

/*int match(){
	
	for(int i=0;i<size;i++){// for different length of productions;
		if(stck_ptr>= a[i]){
			for(int j=stck_ptr-1;j-a[i]>=0 ;j=j-a[i]){
				for(int m=0;m<prod_count;m++){
					if( (strlen(prod[m]) -2 )!= a[i] )
						continue;
					int tmp=stck_ptr-1,flag=0;
					for(int k=j;k>=j-a[i];k--){
						
							if(! prod[k]==stck[tmp]){
								flag=1;
								break;
							}

						
					}
					if(! flag){
						//for(int q=0,tmp=stck_ptr; q<j;q++){ 
							stck[stck_ptr-a[i]]=prod[m][0];
							stck_ptr=stck_ptr-a[i];
							printf("%s",prod[m]);
							//stck_ptr=stck_ptr-a[i];
						//}
					}
				}
			}
		}
	}
}*/

int match(){
	if(stck[stck_ptr-1]=='i'){
		stck[stck_ptr-1]='E';
		return 1;
	}else if(stck[stck_ptr-1]=='E'){
		if(stck[stck_ptr-2]=='*'){
			if(stck[stck_ptr-3]=='E'){
				stck[stck_ptr-3]='E';
				stck_ptr-=2;
				stck[stck_ptr]='\0';
				return 1;
			}
		}else if(stck[stck_ptr-2]=='+'){
			if(stck[stck_ptr-3]=='E'){
				stck[stck_ptr-3]='E';
				//printf("%d\n",stck_ptr);
				stck_ptr-=2;
				stck[stck_ptr]='\0';
				return 1;
			}
		}else
			return 0;
	}else if(stck[stck_ptr-1]==')'){
		if(stck[stck_ptr-2]=='E'){
			if(stck[stck_ptr-3]=='('){
				stck[stck_ptr-3]='E';
				stck_ptr-=2;
				stck[stck_ptr]='\0';
				return 1;
			}else
				return 0;
		}else
			return 0;
	}else
		return 0;
}

void shift(){
	stck[stck_ptr++]='$';
	//printf(" %s\t%s \n",stck,inp);
	for(int i=0;i<strlen(inp);i++){
		printf(" %s\t\t",stck);
		for(int j=ptr;j<strlen(inp);j++)
			printf("%c",inp[j]);
		printf("\t");
		//if( stck_ptr!=2 ){
			if(match()){
				
				printf("\t\tReduce\n",inp);
				i--;
			}else{
				push(ptr++);
				//printf(" %s\t",stck);
				//for(int j=ptr;j<strlen(inp);j++)
					//printf("%c",inp[j]);
				printf("\t\tshift\n",inp);
			}
		/*}else{
			push(ptr++);
			//printf(" %s\t",stck);
			//for(int j=ptr;j<strlen(inp);j++)
				//printf("%c",inp[j]);
			printf("\t\t\tshift\n",inp);		
		}*/

		
	}
	if((stck[stck_ptr-1])=='$' && stck[stck_ptr-2]=='E' && (stck[stck_ptr-3])=='$'){
		printf(" %s\t\t",stck);
			for(int j=ptr;j<strlen(inp);j++)
				printf("%c",inp[j]);
		printf("\n");
		printf("successfully parsed\n");
		return;
	}
	printf(" %s\t\t",stck);
				for(int j=ptr;j<strlen(inp);j++)
					printf("%c",inp[j]);
	printf("\n");
	while(match()){
		printf(" %s\t\t",stck);
		for(int j=ptr;j<strlen(inp);j++)
			printf("%c",inp[j]);
		printf("\t\tReduce\n",inp);
	}
	//printf("%d %c\n",stck_ptr,stck[stck_ptr-1]);
	if((stck[stck_ptr-1])=='$' && stck[stck_ptr-2]=='E' && (stck[stck_ptr-3])=='$'){
		printf("successfully parsed\n");
	}else
		printf("failed to be successfully parsed\n");
	
}

void main(){
	strcpy(inp,"(-i+i*i+(i))$");	
	strcpy(prod[prod_count++],"E=E+E");
	strcpy(prod[prod_count++],"E=E*E");
	strcpy(prod[prod_count++],"E=(E)");
	strcpy(prod[prod_count++],"E=i");
	/*for(int i=0;i<prod_count;i++){
		int tmp=strlen(prod[i]), flag=0;
		for(int j=0;j<size;j++){
			if(tmp==a[j]){
				flag=1;
			}
				
		}
		if( ! flag)
			a[size++]=tmp;
	}*/
	shift();

}
