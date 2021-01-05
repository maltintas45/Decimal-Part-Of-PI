/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;

	
int Counter::findindex(Token *arr,char elem[]){
	for(int i=0;i<token_count;i++)
		if (strncmp(i[arr].token,elem,TOKEN_LENGTH-1)==0) // a[b] == a+b = b[a]
			return i;
	return -1;
} 

bool Counter::contains(char *token, char target){
	for(int i=0;i<TOKEN_LENGTH-1;i++)
		if (token[i]==target)
			return true;
	return false;
}

void Counter::read_and_count(){		
	int offset=0;
	int index=0;
	char k[2];
	
	FILE *phonebook;
	phonebook = fopen("pi_approximate", "r" );
	if(!phonebook){ 	
		cerr << "Cannot open file" << endl;
		exit(1);
	}
	else{
		fseek(phonebook, 0, SEEK_SET); 
		while(fread(&k, sizeof(k), 1, phonebook)){
			offset++;
			fseek(phonebook, offset, SEEK_SET);
			if (!contains(k,'.')&&!contains(k,'\n')){		
				index=findindex(token_array,k);
				if(index!=-1){					
					token_array[index].count++;
				}
				else{
					strncpy(token_array[token_count].token,k,TOKEN_LENGTH-1);
					token_array[token_count].token[TOKEN_LENGTH-1]='\0';
					token_array[token_count].count=1;					
					token_count++;
				}				
			}
		}	
	}
	fclose(phonebook);
}


Token *Counter::get_most_common_three(){
	static Token common_three[3];
	common_three[0].count=0;
	common_three[1].count=0;
	common_three[2].count=0;
	for(int i=0;i<token_count;i++){
		if (token_array[i].count>common_three[0].count){
			strncpy(common_three[2].token,common_three[1].token,TOKEN_LENGTH);
			common_three[2].count=common_three[1].count;			
			
			strncpy(common_three[1].token,common_three[0].token,TOKEN_LENGTH);
			common_three[1].count=common_three[0].count;			
			
			strncpy(common_three[0].token,token_array[i].token,TOKEN_LENGTH);
			common_three[0].count=token_array[i].count;
		}
		else if(token_array[i].count>common_three[1].count){
			strncpy(common_three[2].token,common_three[1].token,TOKEN_LENGTH);
			common_three[2].count=common_three[1].count;			
			
			strncpy(common_three[1].token,token_array[i].token,TOKEN_LENGTH);
			common_three[1].count=token_array[i].count;			
		}
		else if(token_array[i].count>common_three[2].count){					
			strncpy(common_three[2].token,token_array[i].token,TOKEN_LENGTH);
			common_three[2].count=token_array[i].count;			
		}
	}
	return common_three;
}
