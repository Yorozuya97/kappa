#include <stdio.h>
int cube(int num);
int main(){
    int i;
    do{
      printf("Give Number:");
      scanf("%d",&i);
    }while (i<0 || i>1000);
    printf("%d\n",cube(i));
    return 0;
       
} 
int cube(int num){//YPOLOGIZEI TO 1^3+2^3+3^3.....num^3
     int i,sum=0;
     for (i=1;i<=num;i++)
       sum+=i*i*i;// 
     return sum;
}
