#include <stdio.h>

void add(void);
void sub(void);
int glob=10;
int main(){
    add();
    printf("%d\n",glob);
    sub();
    printf("%d",glob);
}

void add(void){
    glob++;
}
void sub(void){
    glob--;
}