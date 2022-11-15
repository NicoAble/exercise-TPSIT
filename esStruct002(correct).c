/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
typedef struct  node
{
    int  valore;
    struct  node* next;
}Node;

void stampaLista(Node* lista){
    Node *l;
    l=lista;
    printf("numeri  inseriti: ");
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next;
    }
}

void stampaLista1(Node* l)
{
    printf("%d - %p \n",l->valore, l->next);
    if(l->next!=NULL)
        stampaLista1(l->next);
}

int contaNodi(Node* lista){
    Node* l;
    l=lista;
    int c=0;
    while(l!=NULL){
        l=l->next;
        c++;
    }
    return c;
}

int contaNodi1(Node* l){
    if(l!=NULL)
        return contaNodi1(l->next)+1;
    return 0;
}

int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;
    int c=0;

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /*  prima  iterazione  */
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else /*  iterazioni  successive  */
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);

    stampaLista1(lista);
    c=contaNodi1(lista);
    printf("numero nodi: %d", c);
    printf("\n");
    free(lista);
    return  0;
}