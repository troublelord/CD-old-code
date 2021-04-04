#include <stdio.h>
#include <string.h>
#include <ctype.h>
int fcurr;
int ff_count;
char ff[10][10];
int fenter=0;
char curr;
char folprod[200][200];
int folprod_count=0;

char first_finish[20];
int first_count;
char follow_finish[20];
int follow_count;
	int prod_count=0;
	char prod[20][20];
	char temp[20];

int isfinish(char hi){
	for(int i=0;i<first_count;i++){
		if(first_finish[i]==hi)	
			return 1;
	}
	return 0;
}
int isfinishfollow(char hi){
	for(int i=0;i<follow_count;i++){
		if(follow_finish[i]==hi)	
			return 1;
	}
	return 0;
}
int f_count=0;
int flag=0;
int first(char hi){
	if(f_count){
	f_count--;
	}else
		flag=0;
	
	if(islower(hi) )	{
		if(fenter){
			printf(" %c",hi);
			fenter=0;		
		}
		else
			printf(", %c",hi);
		return 1;              // if epsilon return 9
	}
	for(int i=0; i<prod_count;i++){
		if(prod[i][0]==hi){
			int len = strlen(prod[i]);
			for(int j=2;j<len;j++ ){

				if(prod[i][j]=='#'){
					flag=1;
					f_count++;
					
				}
				else if(isupper(prod[i][j])){
					if(first(prod[i][j])!=9){
						break;
					}
				}
				
				else{
					if(fenter){
						printf(" %c",prod[i][j]);
						fenter=0;		
					}
					else
						printf(", %c",prod[i][j]);
					
					break;
					
				}
			}

		}
	}
	if(flag==1){
		return 9;
	}

}

int firstfol(char hi){
	int flag=0;
	if(islower(hi) )	{
		for(int k=0;k<folprod_count;k++){
							if(folprod[k][0]==curr)
						 		strncat(folprod[k],&hi,1);
						}
		return 1;              // if epsilon return 9
	}
	for(int i=0; i<prod_count;i++){
		if(prod[i][0]==hi){
			int len = strlen(prod[i]);
			for(int j=2;j<len;j++ ){

				if(prod[i][j]=='#'){
					flag=1;
				}
				else if(isupper(prod[i][j])){
					if(first(prod[i][j])!=9){
						break;
					}
				}
				
				else{
					for(int k=0;k<folprod_count;k++){
							if(folprod[k][0]==curr)
						 		strncat(folprod[k],&prod[i][j],1);
						}
					break;
					
				}
			}

		}
	}
	if(flag==1){
		return 9;
	}

}

char kk[50];

int followww(char hi){
	for(int i=0; i<prod_count;i++){
		int len=strlen(prod[i]);
		for(int j=2;j<len;j++ ){
			if(prod[i][j]==hi){
				if(j+1<len){
					//printf(" %c",prod[i][j+1] );
					
					
				}
				else {
					//if(isfinishfollow(prod[i][0])==1){
						//follow(prod[i][0]);
					//if(strcmp
					if(curr!=prod[i][0]){
					strncat(kk,&curr,1);
					strncat(kk,&prod[i][0],1);
					}
					//curr, prod[i][0];
					//}
				}
			}
		}

	}
}

int follow(char hi){
	
	if(hi==prod[0][0]){
		char tmpp='$';
		for(int k=0;k<folprod_count;k++){
							if(folprod[k][0]==curr)
						 		strncat(folprod[k],&tmpp,1);
						}
	}

	for(int i=0; i<prod_count;i++){
		int len=strlen(prod[i]);
		for(int j=2;j<len;j++ ){
			if(prod[i][j]==hi){
				if(j+1<len){
					//printf(" %c",prod[i][j+1] );
					if(  isupper( prod[i][j+1] )  ){ 
							if(firstfol(prod[i][j+1])==9){
								//if(j+1>=len)
							follow(prod[i][0]);
							}
					}
					else{
						//printf(" %c",prod[i][j+1] );
						for(int k=0;k<folprod_count;k++){
							if(folprod[k][0]==curr)
						 		strncat(folprod[k],&prod[i][j+1],1);
						}
					}
					
				}
				//else {
					//if(isfinishfollow(prod[i][0])==1){
						//follow(prod[i][0]);
					//if(strcmp
					//if(curr!=prod[i][0]){
					//strncat(kk,&curr,1);
					//strncat(kk,&prod[i][0],1);
					//}
					//curr, prod[i][0];
					//}
				}
			}
		}

	}

//}
int dup(char str[])
{
  	//char str[100];
  	int i, j, k;
 
  	//printf("\n Please Enter any String :  ");
  	//gets(str);
  	 	
  	for(i = 0; i < strlen(str); i++)
  	{
  		for(j = i + 1; str[j] != '\0'; j++)
  		{
  			if(str[j] == str[i])  
			{
  				for(k = j; str[k] != '\0'; k++)
				{
					str[k] = str[k + 1];
				}
 			}
		}
	}
	
	printf("Follow(%c) = {",str[0]);
	for( int i=2;i<strlen(str);i++){
		if(i==2)
			printf(" %c",str[i]);
		else
			printf(", %c",str[i]);
	}
	//printf("\n The Final String after Removing All Duplicates = %s ", str);
	printf(" }\n");
	
  	return 0;
}

void main(){


	printf("Enter the productions of the grammer(use '-' when you have finished entering!)\n");	
	while(1){

		scanf("%s",prod[prod_count++]);
		if(prod[prod_count-1][0]=='-'){
			prod_count--;
			//printf("inside");

			break;
		}
		//else
				//printf("outside");
		
		
	}

	/*strcpy(prod[0], "E=TR"); 
	strcpy(prod[1], "R=+TR"); 
	strcpy(prod[2], "R=#"); 
	strcpy(prod[3], "T=FY"); 
	strcpy(prod[4], "Y=*FY"); 
	strcpy(prod[5], "Y=#"); 
	strcpy(prod[6], "F=(E)"); 
	strcpy(prod[7], "F=i"); 
	prod_count=8;*/
	printf("\n\nProductions of the inputed grammer is:\n");
	for(int i=0; i < prod_count; i++)
		printf("%s\n",prod[i]);
	printf("\n\n");

	for(int i=0; i < prod_count; i++){
		//printf("\n %d %s \n",i,first_finish);
		if( ! isfinish(prod[i][0]) ){
			printf("first(%c) = { ",prod[i][0]);
			fenter=1;
			if(first(prod[i][0])==9){
				if(fenter){
					printf(" #");
					fenter=0;
				}
				else
					printf(", #");
			}

				;
			printf(" }\n");
			strncat(first_finish,&prod[i][0],1);
			first_count++;
		}
		//else{
			//printf("/n hi /n");
		//}
		
	}


		for(int i=0; i < prod_count; i++){
		//printf("\n %d %s \n",i,follow_finish);
		if( ! isfinishfollow(prod[i][0]) ){
			//printf("follow(%c)={ ",prod[i][0]);
			//if(
				curr=prod[i][0];
				
				strncpy(folprod[folprod_count],&curr,1);
				strcat(folprod[folprod_count++],"=");
				follow(prod[i][0]);
				//==9){
				//printf(" #");
			//}

				//;
			//printf(" }\n");
			strncat(follow_finish,&prod[i][0],1);
			follow_count++;
		}
		//else{
			//printf("/n hi /n");
		//}

	}

	//strcpy(folprod"");
	follow_count=0;
	printf("\n\n");
	for(int i=0; i < prod_count; i++){
		//printf("\n %d %s \n",i,follow_finish);
		if( ! isfinishfollow(prod[i][0]) ){
			//printf("follow(%c)={ ",prod[i][0]);
			//if(
				curr=prod[i][0];
				
				//strncpy(folprod[folprod_count],&curr,1);
				//strcat(folprod[folprod_count++],"=");
				followww(prod[i][0]);
				//==9){
				//printf(" #");
			//}

				//;
			//printf(" }\n");
			strncat(follow_finish,&prod[i][0],1);
			follow_count++;
		}
		//else{
		//	printf("/n hi /n");
		//}

	}
	//printf("helloooooooooo  %s",kk);
	
	for(int i=0;i<(strlen(kk));i=i+2){
		for(int k=0;k<folprod_count;k++){
				if(folprod[k][0]==kk[i]){
					for(int p=0;p<folprod_count;p++){
						if(folprod[p][0]==kk[i+1]){
							for(int m=2;m<strlen(folprod[p]);m++){
								strncat(folprod[k],&folprod[p][m],1);
							}
						}
					}
				}	
		}
	}
	for(int k=0;k<folprod_count;k++){
		dup(folprod[k]);
			//printf(" %s\n",folprod[k]);
		}

	/*for(int i=0; i < prod_count; i++){
		printf("first(%c)={ ",prod[i][0]);
		follow((prod[i][0]));
		printf(" }\n");
	}*/

}
