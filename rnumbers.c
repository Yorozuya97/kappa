#include <stdio.h>
#include <conio.h>

int main(){
    int i=0;

    srand(time(NULL));
    
    while(i<10){
        printf("%d\n",rand());
        i++;
    }
    getch();
    return 0;
}