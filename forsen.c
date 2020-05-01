#include <stdio.h>
int square(int a);
int cube(int b);

int main(void){
    int sum,num;
    printf("Give a number:");
    scanf("%d",&num);
    sum= square(num)+square(num);
    printf("Sum of the square is:%d\n",sum);
    printf("Cube of number is:%d\n",cube(num));
    printf("Sum of the square+cube is:%d",square(num)+cube(num));
    return 0;
}

int square(int a){
    return a*a;
}
int cube(int b){
    return b*b*b;
}