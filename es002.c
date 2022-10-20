/*-Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno in formato INT)
-scorrere il file con la funzione FGETS e STRTOK
-stampare in ordine DECRESCENTE (dal più grande al più piccolo)
 utilizzando i puntatori e allocazione dinamica (MALLOC)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 1024

typedef struct persona{
    char* Cognome;
    char* Nome;
    int Data;
}Persona;

int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET);
    return sz;
}

void bubbleSort(Persona *a, int n){
    int k, sup, temp;
    for (sup = 1; sup < n; sup++){
        for (k = 0; k < sup ; k++){
            if ((a+sup)->Data < (a+sup)->Data)
            {
                temp = (a+sup)->Data;
                (a+sup)->Data = (a+k)->Data;
                (a+k)->Data = temp;
            }
    }
}
}

void leggiInOrdine(Persona *a, int c){
    for(int x=0; x<c; x++){
        printf("la posizione n.%d e': %s %s %d", x, (a+x)->Cognome, (a+x)->Nome, (a+x)->Data);
        printf("\n");
    }
}

int main(){
    FILE* fp=fopen("02.csv", "r");
    Persona *p, *a;
    char riga[LUNG];
    int count=0, dim=0;
    if(fp!=NULL){
    dim=sizeof(fp);
    p=(Persona*)malloc(dim*sizeof(Persona));
    a=p;

    while(fgets(riga, LUNG, fp))   {
            (a+count)->Cognome=strtok(riga, ",");
            (a+count)->Nome=strtok(NULL, ",");
            (a+count)->Data=atoi(strtok(NULL, ","));
            printf("%s %s %d\n", (a+count)->Cognome, (a+count)->Nome, (a+count)->Data);
            count++;
    }
    printf("\n");
    bubbleSort(a, count);
    leggiInOrdine(a, count);
    }
    free(p);
    fclose(fp);
return 0;
}