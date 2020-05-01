#include <stdio.h>
#include <math.h>

int main(){
    double base , power,result;
    printf("Give the base:");
    scanf("%lf",&base);
    printf("Give the power:");
    scanf("%lf",&power);
    result= pow(base,power);
    printf("%.1lf^%.1lf=%.1lf\n",base,power,result);



    int x;
    for (x=1;x<=10;x++){
        printf("%d\n", square(x));
    }
    return 0;
}

int square(int y){
    return y*y;
}