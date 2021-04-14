#include <iostream>
void Bubble_Sort(int[], int);
void Swap(int[], int, int);
int main() {
	int ali[14] = { 21,1231,3423,2,342,-12,23,45,5, 1,3,2,1,7 };

	Bubble_Sort(ali, 14);
	for (int i = 0; i < 14; i++) {
		std::cout << ali[i] << " ";
	}
}
void Bubble_Sort(int arr[] , int n) {
	
	for (int i = 0; i < n - 1; i++) {
		int n2 = n - 1;
		for (int j = 0; j < n2; j++) {
			if(arr[j]>arr[j+1]){
				Swap(arr, j, j + 1);
			}
			else {

			}
			
		}

	}

}
void Swap(int arr[], int a, int b) {
	int tmp = 0;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
