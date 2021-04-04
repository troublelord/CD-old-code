#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char exper[100];

char post[50];

char stck[50];
int stck_ptr=-1,post_ptr=-1;

void push(char ch,int c){
	if(c==1){
		strncat(stck,&ch,1);
		//stck[++stck_ptr]=ch;
		//stck[stck_ptr+1]='\0';
		stck_ptr++;
	}
	else{
		strncat(post,&ch,1);
		post_ptr++;
		//post[++post_ptr]=ch;
		//post[post_ptr+1]='\0';

	}
}

char pop(){
	//if(stck_ptr<0){
		//printf("%s hi %s",post,stck);
		//exit(0);
		
	//}
	
	char ch = stck[stck_ptr];
	stck[stck_ptr]='\0';
	stck_ptr--;
	return ch;
}
char st_pop(){
	char ch = post[post_ptr];
	post[post_ptr]='\0';
	post_ptr--;
	return ch;
}

void evalu(){
	strcpy(exper,post);
	post_ptr=-1;
	int c=1;
	for(int i=0;i<strlen(exper);i++){
		if(isalnum(exper[i])){			
			push(exper[i],2);
		}else{
			char ch2=st_pop();
			char ch1=st_pop();
			if(exper[i]=='='){
				printf("%c = t%c\n",ch1,ch2);
			}else if(isdigit(ch2) && isdigit(ch1)){
				printf("t%d = t%c %c t%c\n",c++,ch1,exper[i],ch2);}
			else if(isdigit(ch1)){
				printf("t%d = t%c %c %c\n",c++,ch1,exper[i],ch2);
			}
			else if(isdigit(ch2)){
				printf("t%d = %c %c t%c\n",c++,ch1,exper[i],ch2);}
			
			else
				printf("t%d = %c %c %c\n",c++,ch1,exper[i],ch2);
			//sprintf(,"t%d",c-1);
			//ch1=c;
			char ch[10];
			sprintf(ch, "%d", c-1);
			push(ch[0],2);
		}

	}

}

int pred(char ch){
	if(ch=='^'){
		return 3;
	}else 
	if(ch=='*' || ch=='/'){
		return 2;
	}else if(ch=='+' || ch=='-'){
		return 1;
	}else 
		return -1;

}

void inf2pos(){

	for(int i=0;i<strlen(exper);i++){
		//printf("%s hi %s hi %c \n",post,stck,exper[i]);
		if(isalnum(exper[i])){
			//printf("hi");
			push(exper[i],2);
		}else{
			if(exper[i]==')'){
					char ch=pop();
					while(ch!='('){
						push(ch,2);
						ch=pop();
					}
				continue;		
			}
				
			//if(stck_ptr>=0){
				if(stck_ptr<0 || exper[i]=='(' || pred(exper[i])>pred(stck[stck_ptr]) ) {
					push(exper[i],1);
				}else{
					if(stck_ptr>-1){
						char ch;
						while(stck_ptr>-1 && pred(stck[stck_ptr])>=pred(exper[i]) && pred(stck[stck_ptr]) != '('){
							//printf("%s hi %s hi %c \n",post,stck,exper[i]);
							push(pop(),2);
							//i--;
							//if(stck_ptr>-1)
								//ch=pop();
						}
						//push(ch,2);
						push(exper[i],1);
					}else
						push(exper[i],1);
				}
			//}else{
				//push(exper[i],1);			
			//}
		}
	}
	while(stck_ptr!=-1){
		push(pop(),2);
	}
	
}

void eval(){
	for(int i=0;i<strlen(exper);i++){
		printf("hi");
	}
}

void main(){
	//printf("Enter the experression:");
	//scanf("%s",exper);
	strcpy(exper,"a=(x+y)*(y+z)+(x+y+z)");
	inf2pos();
	//push('h',1);
	//push('h',1);
	//push('h',1);
	//pop();
	//printf("%s",stck);
	//eval();
	printf("\n%s\n",post);
	evalu();
}


