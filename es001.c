#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 1024
#define LUNG1 100
#define LUNG2 16600

typedef struct Game{
    int Rank;
    char* Name;
    char* Platform;
    int Year;
    char* Genre;
    char* Publisher;
    float NA_Sales;
    float EU_Sales;
    float JP_Sales;
    float Other_Sales;
    float Global_Sales;
}game;

int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back to where we were
    return sz;
}

int main(){
    FILE* fp;
    char A;
    int n=0;
    int count;
    char* tokenName;
    char* tokenRank;
    char* tokenPlatform;
    char* tokenYear;
    char* tokenGenre;
    char* tokenPublisher;
    char* tokenNa;
    char* tokenEu;
    char* tokenJp;
    char* tokenOther;
    char* tokenGlobal;
    game *gioco;
    game *a;
    int n1=1;
    int count1=0;
    int dim;



    char riga[LUNG];
    fp=fopen("vgsales.csv", "r");

    /*
    if(fp==NULL){
        printf("errore nell'apertura del file\n");
        return 0;
    }
    printf("sono dentro\n");*/

    dim= fsize(fp);


    gioco=(game*)malloc(dim*sizeof(game));
    a=gioco;

    while(fgets(riga, LUNG, fp))   {
            (a+count)->Rank=atoi(strtok(riga, ","));
            (a+count)->Name=strtok(NULL, ",");
            (a+count)->Platform=strtok(NULL, ",");
            (a+count)->Year=atoi(strtok(NULL, ","));
            (a+count)->Genre=strtok(NULL, ",");
            (a+count)->Publisher=strtok(NULL, ",");
            (a+count)->NA_Sales=atof(strtok(NULL, ","));
            (a+count)->EU_Sales=atof(strtok(NULL, ","));
            (a+count)->JP_Sales=atof(strtok(NULL, ","));
            (a+count)->Other_Sales=atof(strtok(NULL, ","));
            (a+count)->Global_Sales=atof(strtok(NULL, ","));

            printf("%d %s %s %d %s %s %.2f %.2f %.2f %.2f %.2f\n", (a+count)->Rank, (a+count)->Name, (a+count)->Platform, (a+count)->Year, (a+count)->Genre, (a+count)->Publisher, (a+count)->NA_Sales, (a+count)->EU_Sales, (a+count)->JP_Sales, (a+count)->Other_Sales, (a+count)->Global_Sales);
            count++;
    }
    free(gioco);
    fclose(fp);
return 0;
}
