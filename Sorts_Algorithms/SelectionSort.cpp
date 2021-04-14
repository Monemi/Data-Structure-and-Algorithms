#include <iostream>
void Selection_Sort(int[], int n);
void Swap(int[],int, int);
int main() {
	int ali[14] = { 21,1231,3423,2,342,-12,23,45,5, 1,3,2,1,7 };

	Selection_Sort(ali, 14);
	for (int i = 0; i < 14; i++) {
		std::cout << ali[i] << " ";
	}
}
void Selection_Sort(int arr[] , int n) {
	for (int i = 0; i < n-1; i++) {
		int min = arr[n - 1];
		int minindex=n-1;
		for (int j = i; j < n - 1; j++) {
			if(arr[j]<min){
				min = arr[j];
				minindex = j;
			}
			else {

			}
		}
		Swap(arr,minindex,i);
	}

}
void Swap(int arr[], int a, int b) {
	int tmp = 0;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
