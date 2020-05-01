#include <stdio.h>
int main(){
    char arr[]="MALAKAS";
    printf("%d\n",sizeof(arr));// Vgazei eksodo 8 giati 7 grammata MALAKAS kai en to "\0" termatikos char.

    char str1[]="pepega";//einai lathos giati kindunos alloiwshs dedomenwn. 
    char str2[]="pepege";
    str1[7]='s';
    printf("%c\n",str2[0]);


    char jerry[]="MALAKA VLAKA OBAMA";
    printf("%s\n",jerry+8);
    printf("%s\n",&jerry[15]);
    printf("%d\n",sizeof(jerry));

    puts(jerry);//sunarthsh emfanishs alfarithmitikwn san thn printf(),antikathista to \0 me \n automata
    puts(arr);//vlepoume thn alloiwsh dedomenwn apo to str1[7]='s;.

    char garbage[100];//epeidh den exoun dwthei times ston pinaka h puts tha emfanisei skoupidia.
    garbage[0]='a';
    garbage[1]='b';
    puts(garbage);

    char *ptr;//Xrhsimopoioume pointer san pinaka.
    int i;
    ptr="TEXT";
    for(i=0;ptr[i]!='\0';i++)
     printf("%c %c\n",*(ptr+i),ptr[i]);

     char perko[100];
     scanf("%[^\n]",perko);
     printf("%s\n",perko);
     scanf("%s",perko);
     printf("%s %s",perko,perko+10);

    return 0;
}