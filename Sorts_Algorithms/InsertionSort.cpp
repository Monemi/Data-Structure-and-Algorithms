#include <iostream>
void Insertion_Sort(int[], int );
int main(){

	int ali[14] = {21,1231,3423,2,342,-12,23,45,5, 1,3,2,1,7};
	
	Insertion_Sort(ali, 14);
	for (int i = 0; i < 14; i++) {
		std::cout << ali[i] << " ";
	}
}
void Insertion_Sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		for (int j =0; j< i; j++) {
			if(arr[i-j-1]>key){
				
				arr[i - j] = arr[i - j-1];
				arr[i - j - 1] = key;
			}
			else {

				break;
			}
		}
	}

}