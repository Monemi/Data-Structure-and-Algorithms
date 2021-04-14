#include <iostream>
//2-Sorted Array
double SortThem(int[], int[],int ,int );
int main() {

	int a1[] = { 1,2,3,4,5,6 };
	int a2[] = { -1,2,3,7,8,9,2 };
	double Mianeh=SortThem(a1, a2,6,7);
	std::cout << Mianeh << std::endl;
}
double  SortThem(int a[] , int b[],int size1,int size2)
{
	int pivot1 = 0;
	int pivot2 = 0;
	int count = 0;
	double M = 0;
	int* Merged = new int[(size1 + size2)];
	if(size1>size2){
		int tmp;
		tmp = size1;
		size1 = size2;
		size2 = tmp;
	}
	else{}
	while (pivot1 < size1 && pivot2 < size2) {
		if (a[pivot1] >= b[pivot2]) {
			Merged[count]=b[pivot2];
			pivot2++;
			count++;
		}
		else {
			Merged[count] = a[pivot1];
			pivot1++;
			count++;
		}

	}
	while (pivot2 < size2) {
		Merged[count] = b[pivot2];
		pivot2++;
		count++;
	}
	
	int SizeMerged = size1 + size2;
	if(SizeMerged%2==0){
		M = ((double)(Merged[SizeMerged / 2] + Merged[(SizeMerged / 2) - 1]) )/ 2;
	}
	else{
		int M_index = (size1 + size2) / 2;
		M = Merged[M_index];
	}
	for (int i = 0; i < SizeMerged; i++) {
		std::cout << Merged[i] << " ";
	}
	std::cout << std::endl;
	
	return M;
}