#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    char* nome;
    struct node *next;
}Node;

int main() {
    Node *lista = (Node *) malloc(sizeof(Node *));
    Node *l = lista;
    char risp;
    int c=0;
    do{
        printf("\ninserire il %d nome: ", c+1);
        if(c==0) {
            scanf("%s", l->nome);
        }else{
            scanf("%s", l->next->nome);

        }
        l->next = (Node *) malloc(sizeof(Node *));
        l = l->next;

        do{
            printf("\nvuoi continuare? (inserire s per si e n per no): ");
            scanf("%c", &risp);
        }while(!(risp=='s' || risp=='S' || risp=='n' || risp=='N'));
        c++;
    }while(risp=='s' || risp=='S');
    for(int k=0; k<c; k++){
        if(k==0){
            printf("\n%s", l->nome);
        }else{
            printf("\n%s", l->next);
        }
    }
    free(lista);

    return 0;
}