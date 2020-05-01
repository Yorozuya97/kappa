#include <stdio.h>
int main(){
    int i,num,t1=0,t2=1,next;
    printf("Give number of terms:");
    scanf("%d",&num);
    printf("Fibonacci Series:");
    for(i=1;i<=num;++i){
     printf("%d,",t1);
     next=t1+t2;
     t1=t2;
     t2=next;
    }
    return 0; 
}