
/*Δημιουργήστε μία συνάρτηση που να δέχεται σαν παράμετρο έναν πίνακα πραγματικών και να τον ταξινομεί κατά αύξουσα σειρά σύμφωνα με τον αλγόριθμο της ταξινόμησης με επιλογή.
 Στη συνέχεια, να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τους βαθμούς 10 φοιτητών, να τους αποθηκεύει σε έναν πίνακα, να καλεί τη συνάρτηση και να εμφανίζει τον ταξινομημένο πίνακα.*/


#include <stdio.h>
#include <conio.h>
#define SIZE 10

void sinart(double arr[]);

int main(void){
    int i;
    double arr[SIZE];
    srand(time(NULL));
    for(i=0;i<SIZE;i++){
      arr[i]=rand();
    }
    sinart(arr);
    printf("\nSORTED ARRAY\n");
    for(i=0;i<SIZE;i++)
      printf("%.2f\n",arr[i]);
    return 0;  

}

void sinart(double arr[]){
      int i,j;
      double temp;
      for(i=0;i<SIZE-1;i++){
          for(j=i+1;j<SIZE;j++){
              if(arr[i]>arr[j]){
                  temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
              }
          }
      }
}