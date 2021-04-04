#include <stdio.h>
#include <string.h>
#include <ctype.h>
int fenter=0;
char curr;
int f_count=0;
int flag=0;

char prod[50][50];
int prod_count=0;

char first[25][25];
int first_count=0;

char follow[25][25];
int follow_count=0;

char first_finish[50];
//int first_


int ispresent(char ch, int ind){

	for(int i=2;i<strlen(first[ind]);i++){
		if(first[ind][i]==ch){
			return 1;
		}
	}
	return 0;

}

int isfinish(char hi){
	for(int i=0;i<first_count;i++){
		if(first_finish[i]==hi)	
			return 1;
	}
	return 0;
}

int firstt(char hi){
	if(f_count){
	f_count--;
	}else
		flag=0;
	
	if(islower(hi) )	{
		if(fenter){
			if(!ispresent(hi,first_count))
				strncat(first[first_count],&hi,1);
			//printf(" %c",hi);
			fenter=0;		
		}
		else{ int jk=0;
			if(!ispresent(hi,first_count))
				strncat(first[first_count],&hi,1);
			//printf(", %c",hi);
		}
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
					if(firstt(prod[i][j])!=9){
						break;
					}
				}
				
				else{
					if(fenter){
						if(!ispresent(prod[i][j],first_count))
							strncat(first[first_count],&prod[i][j],1);
						//printf(" %c",prod[i][j]);
						fenter=0;		
					}
					else{
						if(!ispresent(prod[i][j],first_count))
							strncat(first[first_count],&prod[i][j],1);
						//printf(", %c",prod[i][j]);
						printf("\t");
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




char copy[50];// first second implies second needs to be copied to first

int cpy(char to, char from){
	int ep_flag=0;
	for(int i=0;i<follow_count;i++){
		if(follow[i][0]==to){
			for(int j=0;j<first_count;j++){
				if(first[j][0]==from){
					
					for(int m=2;m<strlen(first[j]);m++){
						int flag=0;
						for(int n=2;n<strlen(follow[i]);n++){
							if(follow[i][n]==first[j][m]){
								flag=1;
								break;
							}
						}
						if(flag==1){

							break;
						}else{

							if(first[j][m]=='#'){
								ep_flag=1;
							}else{
								strncat(follow[i],&first[j][m],1);
							}
						}
					}
					if(ep_flag)
						return 1;
					else
						return 0;
					
					//break;
				}
					
			}//break;
		
		
		}

	}	
}


//1 is first and 2 is follow
void follo(char ch){
	int flagg=0;
		
	for(int j=0;j<follow_count;j++){
		if(follow[j][0]==ch){
			flagg=1;
			break;
		}
	}
	if(!flagg){
		strncat(follow[follow_count],&ch,1);
		strcat(follow[follow_count++],"=");
	}
		
	
	//printf("hello   %c\n",ch);
	for(int i=0; i<prod_count;i++){
		//printf("hi");
		for(int j=2;j<strlen(prod[i]);j++){
			if(prod[i][j]==ch){
				if(j+1==strlen(prod[i])){
					
					
					strncat(copy,&prod[i][0],1);strncat(copy,&prod[i][j],1);
					//strcat(copy,"2");
					break;
				}
				j++;
				int flag=0,ep_flag=0;;
				while(j<strlen(prod[i])){
					flag=0;
					ep_flag=0;
					if( ! isupper(prod[i][j])){
						for(int m=0;m<follow_count;m++){
							if(follow[m][0]==ch){
								int flag=0;
								for(int n=2;n<strlen(follow[i]);n++){
									if(follow[m][n]==prod[i][j]){
										flag=1;
										break;
									}
								}
								if(flag==1){

									break;//return;   imp
								}else{

									//if(first[j][m]=='#'){
										//ep_flag=1;
									//}else{//printf("%s hi %c\n",follow[m],first[j][m]);
										strncat(follow[m],&prod[i][j],1);
										break;//return;  imp
									//}
								}
								break;	
							}
						}
						//if(ep_flag && j+1==strlen(prod[i])){
						//strncat(copy,&ch,1);
						//strncat(copy,&prod[i][0],1);
						//return;}
					}/*else{
						for(int m=0;m<follow_count;m++){
							if(follow[m][0]==ch){
								strncat(follow[m],&prod[i][j],1);
								return;
							}
						}
					}*/

					
					//printf("%s %c %d  %s\n",prod[i],prod[i][j],j,copy);
					if(cpy(ch,prod[i][j])==1){//printf("%d\n",flag);
						flag=1;
						//j++;
					}
					j++;
				
				}
				if(flag ){//printf("fc");printf("%d %d\t",i,j);
					strncat(copy,&prod[i][0],1);
					strncat(copy,&curr,1);
					
					
					
					
					//strcat(copy,"2");
					break;//return;  imp
				}
			}
		}
	}


}

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

void perform_copy(){//printf("hi");
	for(int c=strlen(copy)-1;c>0;c-=2){
		for(int i=0;i<follow_count;i++){
			if(follow[i][0]==copy[c]){
				for(int j=0;j<follow_count;j++){
					if(follow[j][0]==copy[c-1]){// copy j to i
						//printf("%d %d \n",c-1,c);						
						for(int m=2;m<strlen(follow[j]);m++){
							int flag=0;
							for(int n=2;n<strlen(follow[i]);n++){
								if(follow[i][n]==follow[j][m]){
									flag=1;
									break;
								}
							}
							if(flag==1){
								//printf("%s %c already\n",follow[i],follow[j][m]);
								//break;
							}else{
								//printf("%s %c\n",follow[i],follow[j][m]);
								strncat(follow[i],&follow[j][m],1);//printf(" %s %c\n",follow[i],first[j][m]);
								
							}
						}
						
					}

				}
				
			}
			
		}
		
	}
}

void main(){

	/*strcpy(prod[0], "S=ACB"); 
	strcpy(prod[1], "S=Cd"); 
	strcpy(prod[2], "B=aB"); 
	strcpy(prod[3], "C=cC"); 
	strcpy(prod[4], "C=#"); 
	strcpy(prod[5], "B=#"); 
	prod_count=6;
	*/
	strcpy(prod[0], "S=ACB"); 
	strcpy(prod[1], "S=Cbb"); 
	strcpy(prod[2], "S=Ba"); 
	strcpy(prod[3], "A=da"); 
	strcpy(prod[4], "A=BC"); 
	strcpy(prod[5], "B=g"); 
	strcpy(prod[6], "B=k"); 
	strcpy(prod[7], "C=h"); 
	strcpy(prod[8], "C=#"); 
	prod_count=9;

	/*printf("Enter the productions of the grammer(use '-' when you have finished entering!)\n");	
	while(1){

		scanf("%s",prod[prod_count++]);
		if(prod[prod_count-1][0]=='-'){
			prod_count--;
			//printf("inside");

			break;
		//}
		//else
				//printf("outside");
		
		
	}*/

	

	//strcpy(first[first_count++],"S=dgh#ba");
	//strcpy(first[first_count++],"A=dgh#");
	//strcpy(first[first_count++],"B=g#");
	//strcpy(first[first_count++],"C=h#");
	printf("\n\nProductions of the inputed grammer is:\n");
	for(int i=0; i < prod_count; i++)
		printf("%s\n",prod[i]);
	printf("\n\n");
	
	for(int i=0; i < prod_count; i++){
		//printf("\n %d %s \n",i,first_finish);
		if( ! isfinish(prod[i][0]) ){
			strncpy(first[first_count],&prod[i][0],1);
			strcat(first[first_count],"=");
			//printf("first(%c) = { ",prod[i][0]);
			fenter=1;
			if(firstt(prod[i][0])==9){
				if(fenter){
					//printf(" #");
					if(!ispresent('#',first_count))
						strcat(first[first_count],"#");
					fenter=0;
				}
				else{	
					if(!ispresent('#',first_count))
						strcat(first[first_count],"#");
					//printf(", #");
				}
			}

				//;
			//printf(" }\n");
			strncat(first_finish,&prod[i][0],1);
			first_count++;
		}
		//else{
			//printf("/n hi /n");
		//}
		
	}

	strncat(follow[follow_count],&prod[0][0],1);
	strcat(follow[follow_count++],"=$");
	//printf("hi");
	for(int i=0;i<prod_count;i++){
		curr=prod[i][0];
		follo(prod[i][0]);
	}
	for(int i=0;i<follow_count;i++){
		//printf("hi");
		//printf("%s\n",follow[i]);
	}
	//printf("%s\n",copy);
	perform_copy();
	printf("\n\n");
	for(int i=0;i<first_count;i++){
		//printf("hi");
		printf("%s\n",first[i]);
	}
	printf("\n\n");
	for(int i=0;i<follow_count;i++){
		//printf("hi");
		printf("%s\n",follow[i]);
	}

}
