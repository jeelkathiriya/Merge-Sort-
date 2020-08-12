#include<iostream>
using namespace std;


void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;

   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) 
   {     
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr)
    {    
      array[k] = rarr[j];
      j++; k++;
   }
}
void merge_sort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      merge_sort(array, l, m);
      merge_sort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
   int number;
   cout << "Enter the Array Size"<<endl;
   cin >> number;
   int input[number]; 
   cout << "Enter elements:" << endl;
   for(int i = 0; i<number; i++) 
   {
      cin >> input[i];
   }
   cout<<endl;
   cout << "Inputed Array: ";
   for(int i = 0; i<number; i++)
      cout << input[i] << " ";
      cout << endl;
   merge_sort(input, 0, number-1);
   cout<<endl;  
   cout << "Final Sort: ";
   for(int i = 0; i<number; i++)
      cout << input[i] << " ";
      cout << endl; 
}