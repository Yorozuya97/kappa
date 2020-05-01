#include <stdio.h>
#define ROW 3
#define COL 5
int main(){
    int i,j,arr[ROW][COL],flag,k;
    for(i=0;i<ROW;i++){
     for(j=0;j<COL;j++){
         printf("Enter Number ROW:[%d] COL:[%d] -->",i,j);
         scanf("%d",&arr[i][j]);
     }
    }
    for(j=0;j<=COL;j++){
        flag=0;
        for(i=0;i<=ROW;i++){
          k=i+1;  
          do{
           if(arr[i][j]==arr[i+1][j])
             flag=1;
           k++; 
          }while(k+1<=ROW || flag==1);     
        }
        if(flag==0){
            for(i=0;i<ROW;i++){
                printf("%d\n",arr[i][j]);
            }
        }
    }
    return 0;
}    