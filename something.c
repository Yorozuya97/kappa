#include <stdio.h>

int piv(int h, int z);
int test(int x, int y);
int main(void){
    int a,b,suma,dif;
    int i,j;
    printf("enter numbers:");
    scanf("%d%d",&a,&b);
    printf("enter numbers:");
    scanf("%d%d",&i,&j);
    suma= test(a,b);
    dif= piv(i,j);
    printf("SUM=%d  DIV=%d",suma,dif);
}

int test(int x, int y){
    return x+y;
}

int piv(int h, int z){
    return h/z;
}