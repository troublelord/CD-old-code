#include<stdio.h>
#include<string.h>
#include<ctype.h>

char prod[20][10];
int prod_count=0;

char lead[20][10];
int lead_c=0;

char trail[20][10];
int trail_c=0;

char copy_str[50];


char op_tab[10][10];
int x_op=1, y_op=1;

void push(char ch, char src){
	
	for(int i=0;i<lead_c;i++){
		if(src==lead[i][0]){
			for(int j=2;j<strlen(lead[i]);j++){
				if(ch==lead[i][j])
					return;
				
			}
			strncat(lead[i],&ch,1);
			return;
		}
	}
	strncat(lead[lead_c],&src,1);
	strcat(lead[lead_c],"=");
	strncat(lead[lead_c++],&ch,1);
}

void trail_push(char ch, char src){
	
	for(int i=0;i<trail_c;i++){
		if(src==trail[i][0]){
			for(int j=2;j<strlen(trail[i]);j++){
				if(ch==trail[i][j])
					return;
				
			}
			strncat(trail[i],&ch,1);
			return;
		}
	}
	strncat(trail[trail_c],&src,1);
	strcat(trail[trail_c],"=");
	strncat(trail[trail_c++],&ch,1);
}

void leading(){
	for(int i=0;i<prod_count;i++){
		
		for(int j=2;j<strlen(prod[i]);j++){
			if(isupper(prod[i][j]) ){
				//printf("hi");
				if(prod[i][0]!=prod[i][j]){
					strncat(copy_str,&prod[i][0],1);
					strncat(copy_str,&prod[i][j],1);
				}
			}else{
				//printf("hello");
				push(prod[i][j],prod[i][0]);
				break;
			}
		}
	}
	for(int i=strlen(copy_str);i>=2;i=i-2){
		//printf("%c %d %c\n",copy_str[i-1],i,copy_str[i-2]);
		int flag1=1, flag2=1;
		for(int m=0;m<lead_c && flag2==1;m++){
			if(lead[m][0]==copy_str[i-1]){//m is second
				flag2=0;
				//printf("%c second ",lead[m][0]);
				for(int n=0;n<lead_c && flag1==1;n++){
					
					if(lead[n][0]==copy_str[i-2]){//n is first
						flag1=0;
						//printf("%c first\n",lead[n][0]);
						//int flag=1;
						for(int j=2;j<strlen(lead[m]);j++ ){// j in m is 1
							int flag=1;
							int k=2;
							for(;k<strlen(lead[n]);k++ ){//k in n is 2
								if(lead[m][j]==lead[n][k]){
									flag=0;
									break;
								}

							}
							//printf(" %c \n",lead[m][j]);
							if(flag==1)
								strncat(lead[n],&lead[m][j],1);
						}

					}
				}
			}
		}
	}
}
void trailing(){
	strcpy(copy_str,"");
	for(int i=0;i<prod_count;i++){
		
		for(int j=strlen(prod[i])-1;j>=2;j--){
			if(isupper(prod[i][j]) ){
				//printf("hi");
				if(prod[i][0]!=prod[i][j]){
					strncat(copy_str,&prod[i][0],1);
					strncat(copy_str,&prod[i][j],1);
				}
			}else{
				//printf("hello");
				trail_push(prod[i][j],prod[i][0]);
				break;
			}
		}
	}
	for(int i=strlen(copy_str);i>=2;i=i-2){
		//printf("%c %d %c\n",copy_str[i-1],i,copy_str[i-2]);
		int flag1=1, flag2=1;
		for(int m=0;m<trail_c && flag2==1;m++){
			if(trail[m][0]==copy_str[i-1]){//m is second
				flag2=0;
				//printf("%c second ",trail[m][0]);
				for(int n=0;n<trail_c && flag1==1;n++){
					
					if(trail[n][0]==copy_str[i-2]){//n is first
						flag1=0;
						//printf("%c first\n",trail[n][0]);
						//int flag=1;
						for(int j=2;j<strlen(trail[m]);j++ ){// j in m is 1
							int flag=1;
							int k=2;
							for(;k<strlen(trail[n]);k++ ){//k in n is 2
								if(trail[m][j]==trail[n][k]){
									flag=0;
									break;
								}

							}
							//printf(" %c \n",trail[m][j]);
							if(flag==1)
								strncat(trail[n],&trail[m][j],1);
						}

					}
				}
			}
		}
	}
}

int x_loc=0, y_loc=0;

void find_loc(char ch1, char ch2){
	for(int i=1;i<y_op;i++){
		if( ch1 == op_tab[0][i] )
			x_loc=i;
	}

	for(int i=1;i<x_op;i++){
		if( ch2 == op_tab[i][0] )
			y_loc=i;
	}

}

void op(){
	for(int i=0;i<prod_count;i++){
		for(int j=2;j<strlen(prod[i]);j++){
			if( ! isupper(prod[i][j]) ){
				//printf("%c",prod[i][j]);
				op_tab[x_op++][0]=prod[i][j];
				op_tab[0][y_op++]=prod[i][j];
				//printf("  %c   " ,op_tab[x_op++][0]);
			}
		}
	}
	op_tab[x_op++][0]='$';
	op_tab[0][y_op++]='$';

	//rule 1 for lead $
	for(int i=2;i<strlen(lead[0]);i++){//printf("\n %c ",lead[0][i]);
		for(int j=1;j<x_op;j++){//printf(" %c ",op_tab[0][j]);
			if(lead[0][i]==op_tab[0][j]){
				op_tab[x_op-1][j]='<';
				break;
			}
		}
	}
	//rule 2 for trail $
	for(int i=2;i<strlen(trail[0]);i++){//printf("\n %c ",lead[0][i]);
		for(int j=1;j<y_op;j++){//printf(" %c ",op_tab[0][j]);
			if(trail[0][i]==op_tab[j][0]){
				op_tab[j][y_op-1]='>';
				break;
			}
		}
	}

	for(int i=0;i<prod_count;i++){

		//rule 3 ---- variable between 2 terminals 
		for(int j=2;j<strlen(prod[i])-2;j++ ){//printf("\n%c %c\n",prod[i][j],prod[i][j+1]);

			if( (! isupper(prod[i][j]) ) && (! isupper(prod[i][j+2])) ){
				//printf("\n%c %c\n",prod[i][j],prod[i][j+2]);
				find_loc(prod[i][j],prod[i][j+2]);
				op_tab[x_loc][y_loc]='=';
				
			}

		}

		
		for(int j=2;j<strlen(prod[i])-1;j++ ){//printf("\n%c %c\n",prod[i][j],prod[i][j+1]);
			//rule 2 ---- 2 terminals together
			if( (! isupper(prod[i][j]) ) && (! isupper(prod[i][j+1])) ){
				//printf("\n%c %c\n",prod[i][j],prod[i][j+1]);
				find_loc(prod[i][j],prod[i][j+1]);
				op_tab[x_loc][y_loc]='=';
				
			}

		//}

		

			
		//for(int j=2;j<strlen(prod[i])-1;j++ ){//printf("\n%c %c\n",prod[i][j],prod[i][j+1]);
			//rule 5 ---- terminal and then variable ---- xB --- x < lead(B)
			if( (! isupper(prod[i][j]) ) && ( isupper(prod[i][j+1])) ){
				
				for(int k=0;k<lead_c;k++){
					if(lead[k][0]==prod[i][j+1] ){
						for(int l=2;l<strlen(lead[k]);l++){
							find_loc(prod[i][j],lead[k][l]);
							op_tab[x_loc][y_loc]='<';
						}
						break;
					}
					
				}
				//printf("\n%c %c\n",prod[i][j],prod[i][j+2]);
				
				
			}

		//}
			
		//for(int j=2;j<strlen(prod[i])-1;j++ ){//printf("\n%c %c\n",prod[i][j],prod[i][j+1]);
			//rule 6 ---- variable and thent terminal ---- Bx --- x trail(B) > x
			if( ( isupper(prod[i][j]) ) && ( ! isupper(prod[i][j+1])) ){printf("\n%c %c\n",prod[i][j],prod[i][j+1]);
				
				for(int k=0;k<trail_c;k++){
					if(trail[k][0]==prod[i][j] ){
						for(int l=2;l<strlen(trail[k]);l++){
							find_loc(trail[k][l],prod[i][j+1]);
							op_tab[x_loc][y_loc]='>';
						}
						break;
					}
					
				}
				//printf("\n%c %c\n",prod[i][j],prod[i][j+2]);
				
				
			}

		}
	}
	
	//print op_table
	for(int i=0;i<x_op;i++){
		for(int j=0;j<y_op;j++){
			if(op_tab[i][j])
			printf("| %c |",op_tab[i][j]);
			else
			printf("|   |");
		}
		printf("\n");
	}

}

void main(){
	char tmp[10];
	//while(tmp[0]!='-'){
		//scanf("");
	//}

	strcpy(prod[prod_count++],"E=E+T");
	strcpy(prod[prod_count++],"E=T");
	strcpy(prod[prod_count++],"T=T*F");
	strcpy(prod[prod_count++],"T=F");
	strcpy(prod[prod_count++],"F=(E)");
	strcpy(prod[prod_count++],"F=i");
	for(int i=0;i<prod_count;i++){
		printf("%s\n",prod[i]);
	}
	leading();//printf("lead\n")
	printf("\nlead\n");
	for(int i=0;i<lead_c;i++){
		printf("%s\n",lead[i]);
	}
	
	trailing();
	printf("\ntrail\n");
	for(int i=0;i<trail_c;i++){
		printf("%s\n",trail[i]);
	}
	op();
	//printf("%s",copy_str);

}
