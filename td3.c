#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//exo 1

typedef struct doublechainon{
	char word[20];
	struct doublechainon* prev;
	struct doublechainon* next;
}doublechainon;


doublechainon* creationchainon(char* mot){
	doublechainon* c = malloc(sizeof(doublechainon));
	if (c==NULL){
		printf("erreur alloc\n");
		exit(1);
	}
	strcpy(c->word, mot);
	c->word[19] = '\0';
	c->next=NULL;
	c->prev=NULL;
	return c;
}


doublechainon* insertdebut(doublechainon* phead, char* mot){
	doublechainon* new= creationchainon(mot);
	if (phead==NULL){
		phead=new;
	}
	else{
		while(phead->prev!=NULL){
			phead=phead->prev;
		}
		new->next = phead;
		phead->prev = new;
		phead =new;
	}
	
	return phead;
}

doublechainon* insertfin(doublechainon* phead, char* mot){
	doublechainon* new= creationchainon(mot);
	doublechainon* temp= phead;
	if (phead==NULL){
		phead=new;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
			}
			temp->next=new;
			new->next=NULL;
			new->prev=temp;
			
		}
	return phead;
}

void affichedoublechainon(doublechainon* phead){
	if (phead ==NULL){
		printf("erreur\n");
	}
	else{
		printf(" %s -> \n", &phead->word);
		while(phead->next!=NULL){
			
			phead=phead->next;
			printf(" %s -> \n", &phead->word);
		}
	}	
}


doublechainon* inverser(doublechainon* phead){
	if (phead==NULL){
		exit(2);
	}
	doublechainon* temp=phead;
	doublechainon* new=NULL;
	while (temp->next !=NULL){
		temp=temp->next;
	}
	
	while(temp->prev!=NULL){
		new=insertfin(temp, temp->word);
		temp=temp->prev;
	}
	return new;
}

int main(){

	doublechainon* c;
	doublechainon* a;
	c=creationchainon("aaaaaa");
	c=insertfin(c, "bbbbb");
	c=insertfin(c, "ccccb");
	c=insertdebut(c, "abbc");
	
	affichedoublechainon(c);
	a=inverser(c);
	printf("--------\n");
	affichedoublechainon(a);
	
	
	return 0;
}
	
