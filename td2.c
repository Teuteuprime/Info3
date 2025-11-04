#include <stdio.h>
#include <stdlib.h>



typedef struct PileDyn{
	int valeur;
	struct PileDyn* next;
}PileDyn;

PileDyn*    empiler(int nb, PileDyn* ppile){
	PileDyn* new=malloc(sizeof(PileDyn));
	if (new==NULL){
		printf("erreur\n");
		exit(1);
	}
	
	new->valeur=nb;
	if (ppile==NULL){
		ppile=new;
	}
	else{
	
		new->next=ppile;
	}
	return new;
}


void affichepile(PileDyn* ppile){
	while(ppile!=NULL){
		printf("%d\n", ppile->valeur);
		ppile=ppile->next;
	}
}
 void affichepile2(PileDyn* ppile){
 	printf("%d\n", ppile->valeur);
 	while(ppile->next!=NULL){
 		ppile=ppile->next;
 		affichepile2(ppile);
 	}
 }


PileDyn* depile(PileDyn* ppile, int a){
	PileDyn* new;
	PileDyn* test;
	test=ppile;
	while ( ppile->next!=NULL && a>0){
		new=ppile->next;
		printf("test\n");
		free(ppile);
		ppile=new;
		a--;
	}
	return new;
}			

//EXO 3 

typedef struct file{
	int tab[20];
	int debut;
	int fin;
	int taille;
}file;	

void initfile(file* f) {
    f->debut = 0;
    f->fin = -1;
    f->taille = 0;
}

void enfiler(file* f, int articles) {
    if (f->taille == 20) {
        printf("File pleine !\n");
        return;
    }
    f->fin = (f->fin + 1);
    f->tab[f->fin] = articles;
    f->taille++;
}
	
int defiler(file* f) {
    if (f->taille == 0) return -1; // file vide
    int client = f->tab[f->debut];
    f->debut = (f->debut + 1) ;
    f->taille--;
    return client;
}


void afficherfile(file f) {
    if (f.taille == 0) {
        printf("Aucun client en caisse.\n");
        return;
    }
    printf("Clients dans la file (ordre d’arrivée) :\n");
    for (int i = 0; i < f.taille; i++) {
        int index = (f.debut + i);
        printf("Client %d : %d articles\n", i + 1, f.tab[index]);
    }
}


int main(){
	PileDyn* a=NULL;
	/*a=empiler(1, a);
	a=empiler(2,a);
	a=empiler(3,a);
	a=empiler(4,a);
	affichepile(a);
	a=depile(a,3);
	
	affichepile(a)*/
	file caisse;
	initfile(&caisse);
	enfiler(&caisse, 20);
	enfiler(&caisse, 30);
	enfiler(&caisse, 30);
	enfiler(&caisse, 30);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	enfiler(&caisse, 2000);
	
	afficherfile(caisse);
	return 0;
}
