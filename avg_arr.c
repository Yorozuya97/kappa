/*Δημιουργήστε μία συνάρτηση που να δέχεται σαν παραμέτρους έναν πίνακα ακεραίων και το μέγεθός του, να εμφανίζει τα στοιχεία του πίνακα και να επιστρέφει τον μέσο όρο τους.
Στη συνέχεια γράψτε ένα πρόγραμμα το οποίο να διαβάζει 5 ακεραίους, να τους αποθηκεύει σε έναν πίνακα ακεραίων και να εμφανίζει τον μέσο όρο των στοιχείων του πίνακα με χρήση της συνάρτησης*/

#include <stdio.h>
float avg_arr(int ar[],int size);
int main(void){
    int i,arr[5];
    for ( i = 0; i < 5; i++)
    {
        printf("Give Number:");
        scanf("%d",&arr[i]);
    }
    printf("Avg=%.2f\n",avg_arr(arr,5));
    return 0;
}

float avg_arr(int arr[],int size){
    int sum=0,i;
    for ( i = 0; i < size; i++)
    {
      printf("%d",arr[i]);
      sum+=arr[i];
    }  
    
    return (float)sum/size;
}