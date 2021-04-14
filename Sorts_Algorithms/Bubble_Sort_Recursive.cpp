#include<iostream>
using namespace std;
void recBubble(int arr[], int n){
   if (n == 1)
      return;
   for (int i=0; i<n-1; i++) //for each pass p
      if (arr[i] > arr[i+1]) //if the current element is greater than next one
   swap(arr[i], arr[i+1]); //swap elements
   recBubble(arr, n-1);
}
main() {
   int data[] = {54, 74, 98, 154, 98, 32, 20, 13, 35, 40};
   int n = sizeof(data)/sizeof(data[0]);
   cout << "Sorted Sequence ";
   recBubble(data, n);
   for(int i = 0; i <n;i++){
      cout << data[i] << " ";
   }
}