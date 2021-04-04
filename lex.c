#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;
	
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	
	return flag;
}
int iscomment(char buffer[100],int pos){
	if(buffer[pos+1]=='/')
		return 1;
	else
		return 0;
}
int isoperator(char ch){
	switch(ch){
		case '+': return 1;	
		case '-':	return 1;
		case '*':	return 1;
		case '/':	return 1;
		case '=':	return 1;
		default :	return 0;
	}
}


void main(){
	char buffer[100];
	FILE *fp;
	fp=fopen("test","r");
	while(fgets(buffer,100,fp)!=NULL){
		//printf("%s\n",buffer);
		int preflag=0,i=0;
		int len=strlen(buffer);
		while(isspace(buffer[i])) i++;
		if(buffer[i] =='#'){
			printf("%s is a preprocessor directive\n",buffer);
			continue;
		}else if(buffer[i] =='/' && buffer[i+1]=='/')
				continue;

		/*while(i<len){			
			if(buffer[i] =='#'){
				preflag=1;//printf("hi");		
				break;
			}else		
				break;
			
		}
		if(preflag)
			continue;
		 i=0;int comflag=0;	
			
		while(i<len){
			while(isspace(buffer[i])) i++;
			//switch(buffer[i]){case '/':printf("found it");break;}
			//if(buffer[i] =='/'){ printf("found it");if(buffer[i] =='/')printf("found it");}
			 if(buffer[i] =='/' && buffer[i+1] =='/') {//printf("inside");	
				//if(iscomment(buffer,i)){
					comflag=1;//printf("hi");	
					break;
				//}	
			}else	
				break;
			
		}	
		if(comflag)
			continue;
		*/
		i=0;
		hello:
		while(i<len){
			while(isspace(buffer[i])) i++;
			
			if(isoperator(buffer[i])){
				printf("%c is an operator",buffer[i]);

			}
			else{ 
				//printf("%s\n",buffer);
				int l=i,k=0;char sstr[100];
				while(i<len && buffer[i] !=' ' && buffer[i] != '(' && buffer[i] != '{'){
						
					i++;}
			        while (l < i){
    					  	sstr[k] = buffer[l];
      						l++;k++;
  				}
   				sstr[k] = '\0';//printf("%s\n",sstr);
				if(isKeyword(sstr)){
					printf("%s is a keyword\n",sstr);
				}
				else{ if(buffer[i]=='('){ printf("( is a special symbol\n");++i;}
					else if(buffer[i]==')'){ printf(") is a special symbol\n");++i;}
					else	if(buffer[i]=='{'){ printf("{ is a special symbol\n");++i;}
					else if(buffer[i]=='}'){ printf("} is a special symbol\n");++i;}
					if(buffer[i]=='"'){

						int k=0;char t[50];i++;
						while(buffer[i]!='"'){t[k]=buffer[i]; k++;i++;}
						i++;printf("%s is a literal\n",t);
					}						
					else printf("%s is a literal\n",sstr);
					/*
					
					switch(buffer[i]){
							case '{': printf("{ is a special symbol\n");break;	
							case '}':printf("} is a special symbol\n");break;
							case '(':printf("( is a special symbol\n");break;
							case ')':printf(") is a special symbol\n");break;
							//case '=':	return 1;
							default :flag=0;break;	//return 0;
					}
					if(flag==0){break;i++;}	*/
					//goto hello;	
				}
				
			}
			
		}
	}
	fclose(fp);	
}


/*
int main(){
	char ch, buffer[15], operators[] = "+-/%=";
	FILE *fp;
	int i,j=0;
	
	fp = fopen("test","r");
	
	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}
	
	while((ch = fgetc(fp)) != EOF){
   		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				printf("%c is operator\n", ch);
   		}
   		
   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;
   				   				
   				if(isKeyword(buffer) == 1)
   					printf("%s is keyword\n", buffer);
   				else
   					printf("%s is indentifier\n", buffer);
   		}
   		
	}
	
	fclose(fp);
	
	return 0;
}
*/
