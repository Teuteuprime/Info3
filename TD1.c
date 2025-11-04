#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct Chainon{
	int valeur;
	struct Chainon* prochain;
}Chainon; 


Chainon* creationchainon(int a){
	Chainon* c = malloc(sizeof(Chainon));
	if(c==NULL){	
		exit(1);
	}
	c->valeur=a;
	c->prochain=NULL;
	return c;
}

Chainon* insertdebut(Chainon* pliste, int a){
	Chainon* c;
	c=creationchainon(a);
	if (pliste==NULL){
		pliste=c;
	}
	else{
		c->prochain=pliste;
	}
	pliste=c;
	return pliste;
}

Chainon* insertfin(Chainon* pliste, int a){
	Chainon* c; Chainon* c2;
	c=creationchainon(a);
	if (pliste==NULL){
		pliste=c;
	}
	else{
		c2=pliste;
		while(c2->prochain!=NULL){
			c2=c2->prochain;
			}
		c2->prochain=c;
		
	}
	return pliste;
}

		
void afficheliste(Chainon* pliste){
	Chainon* c;
	c=creationchainon(1);
	if (pliste==NULL){
		printf("liste vide");
		return;
	}
	else{
			
		printf("%d \n", pliste->valeur);
		while(pliste->prochain!=NULL){
				printf("->\n");
				pliste=pliste->prochain;
				printf("%d \n", pliste->valeur);
		}
	}
}


Chainon* puissance(Chainon * c){
	int a; Chainon* liste=NULL; int b=2; int sum=0;
	printf("combien de puissances de deux");
	scanf("%d", &a);
	while(a>=1){
		liste=insertfin(liste, pow(b,sum));
		printf("test boucle puissance  \n");
		a-=1;
		sum+=1;
	}
	afficheliste(liste);
	return liste;
}
		
Chainon* insertcroissant(Chainon* pliste, int a){
	Chainon* tmp; int i=0;
	Chainon* tmp2;
	tmp=creationchainon(a);
	
	if(pliste->valeur > a){
		insertdebut(pliste, a);
	}
	else{
		printf("test insertcroissant\n");
		tmp2=pliste;
		while(tmp2->prochain->valeur < a){
			tmp2= tmp2->prochain;
		}
		tmp->prochain=tmp2->prochain;
		tmp2->prochain=tmp;
		return pliste;
	}
}
		
	
//EXO5

typedef struct etudiant{
	char* nom[50];
	char* prenom[50];
	int groupe;
	tab notes[9];
}etudiant;

typedef struct lstetudiants{
	etudiant valeur;
	struct lstetudiants* prochain;
}lstetudiant;

lstetudiant* saisirEtudiant(lstetudiant* lst){
	
	lstetudiants* etu=NULL ;
	etu=malloc(sizeof(lstetudiant);
	if(etu==NULL){
		exit(1);
	}
	printf("nom  :\n");
	scanf("%c", etu->nom);
	printf("prenom :\n");
	scanf("%c", etu->prenom);
	
	printf("groupe  :\n");
	scanf("%d", etu->groupe)
	for (int i=0; i<10 ; i++){
		etu->valeur->tab[i]=rand()%9 +1
	
	
	etu->prcohain=NULL;
	
	return lst;
	
	
int main(){
	Chainon* c=NULL; Chainon* a=NULL;
	c=creationchainon(4);
	c=insertdebut(c,2);
	c=insertfin(c, 3);
	afficheliste(c);
	a=puissance(a);
	a=insertcroissant(a,3);
	afficheliste(a);
	return 0;
	
}
	
