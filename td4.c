#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int node;
	struct tree* sonl;
	struct tree* sonr;
}tree;


typedef tree* ptree;





typedef struct node{
	ptree arbre;
	struct node* prev;
	struct node* next;
}node;

typedef struct file{
	node* head;
	node* queue;
}file;




ptree createTree(int elt){
	ptree a = malloc(sizeof(tree));
	if(a==NULL){
		exit(1);
	}
	
	a->node=elt;
	a->sonl=NULL;
	a->sonr=NULL;
	return a;
}
	

int empty(ptree a){
	if (a==NULL){
		printf("vide\n");
		return 1;
	}
	else{
		printf("non vide\n");
		return 0;
	}
}

int leaf(ptree a){
	if (a!=NULL && (a->sonl==NULL && a->sonr==NULL)){
		printf("feuille\n");
		return 1;
	}
	else{
		printf("erreur ou non feuille\n");
		return 0;
	}
}
	
int element(ptree a){	
	int b= a->node;
	return b;
}

int leftson(ptree a){
	if (a->sonl!=NULL){
		printf("fils gauche\n");
		return 1;
	}
	else{
		printf("pas fils gauche\n");
		return 0;
	}
}

int rightson(ptree a){
	if (a->sonr!=NULL){
		printf("fils droit\n");
		return 1;
	}
	else{
		printf("pas fils droit\n");
		return 0;
	}
}

ptree addleftson(ptree a, int e){
	if(leftson(a)!=1){

		a->sonl=createTree(e);
	
	}
	return a;
}



ptree addrightson(ptree a, int e){
	if(rightson(a)!=1){
		
		a->sonr=createTree(e);
	}
	return a;
}

void traiter(ptree a){
	printf("valeur noeud = %d \n", a->node);
}

void prefixe(ptree a){
	printf("prefixe\n");
	if (a!=NULL){
		traiter(a);
		prefixe(a->sonl);
		prefixe(a->sonr);
	}
}

void postfixe(ptree a){
	printf("postfixe\n");
	if(a!=NULL){
		postfixe(a->sonl);
		postfixe(a->sonr);
		traiter(a);
	}
}

void infixe(ptree a){
	printf("infixe\n");
	if(a!=NULL){
		postfixe(a->sonl);
		traiter(a);
		postfixe(a->sonr);
	}
}


file* creationnode(ptree b){
	node* a=malloc(sizeof(node));
	if (a==NULL){
		exit(1);
	}
	a->next=NULL;
	a->prev=NULL;
	a->arbre=b;
	return a;
}

file* creationFILE() {
    file* a = malloc(sizeof(file));
    if (a == NULL) {
        printf("Erreur\n");
        exit(1);
    }
    a->head = NULL;
    a->queue = NULL;
    return a;
}
	
	
	
file* insertFILE(file* pfile, ptree a){
	node* new= creationnode(a);
	if (pfile->head==NULL){
		pfile->queue=new;
		pfile->head=new;
	}
	else{	
		pfile->queue->next=new;
		new->prev=pfile->queue;
		pfile->queue= new;
	}
	return pfile;
}

ptree removeFILE(file* f) {
    if (f->head == NULL)
        return NULL; // file vide

    node* temp = f->head;
    ptree a = temp->arbre;

    if (f->head == f->queue) { // un seul élément
        f->head = NULL;
        f->queue = NULL;
    } else {
        f->head = temp->next;
        f->head->prev = NULL;
    }

    free(temp);
    return a;
}

void parcourslargeur( ptree a){
	if(a==NULL){
		exit(2);
	}
	file* f =creationFILE();
	f=insertFILE(f, a);
	
	while(f->head!=NULL){
		a=removeFILE(f);
		traiter(a);
		if (leftson(a)){
			insertFILE(f, a->sonl);
		}
		if (rightson(a)){
			insertFILE(f, a->sonr);
		}
	}
}
	
int main(){
	ptree racine = createTree(10);
    addleftson(racine, 5);
    addrightson(racine, 15);
    addleftson(racine->sonl, 3);
    addrightson(racine->sonl, 7);
    prefixe(racine);
    printf("----\n");
    postfixe(racine);
    printf("----\n");
    infixe(racine);
    printf("----\n");
    file* f=creationFILE;
    printf("parcours largeur : \n");
    parcourslargeur(racine);
    
    return 0;
   }
    
	

	
	
