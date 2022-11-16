#include <stdio.h>
#include <malloc.h>
#define DIM 10

int main() {
    //int mat[2][2]={{2, 5}, {6, 4}};
    int **x;
    int *z;
    int y;
    z=&y;
    x=&z;

    printf("inserisci un numero: ");
    scanf("%d",  z); //*x
    printf("%d", y); //**x
    //printf("%d", mat[2][1]);
    //printf("%d", *(x+1)[1]);
    //printf("%d", *(*(x+1)+1));
    char *s;
    int a;
    int *n=&a;
    s=(char*)malloc(DIM*sizeof(char));
    printf("inserisci un nome:");
    scanf("%s", s);
    printf("inserisci un numero: ");
    scanf("%d", n);

    printf("%s %d", s, a);

    return 0;
}
