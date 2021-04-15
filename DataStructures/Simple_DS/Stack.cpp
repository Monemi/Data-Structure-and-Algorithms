#include <iostream>
//stack implementation -- LIFO
//USE Templates For them
template <class T>
class Stack {
private:
	int i = 0;
	int n = 1000;
	T* MemoryPointer;
public:
	Stack(int Size) {
		this->n = Size;
		 MemoryPointer = new T[n];

	}
	Stack(){	MemoryPointer = new T[n];
}

	void Push_back(T data){
		if(i>=n-1){
			MemoryPointer[i] = data;
		}
		else{
			MemoryPointer[i] = data;
			i++;
		}
		
	}
	void Pop_back(){
		if(i>0){ i--; }
	}
	void Print() {
		if (i < 1) {
			std::cout << "We Havent any Data in Stack !" << std::endl;
		}
		for (int k = 0; k < i; k++) {
			std::cout << MemoryPointer[k] << " ";
		}
		std::cout<<std::endl;
	}
	~Stack() {
		delete[] MemoryPointer;
	}
};

int main() {
	Stack<int> ali(100);
	ali.Push_back(100);
	ali.Push_back(130);
	ali.Push_back(80);
	ali.Push_back(75);
	ali.Pop_back();
	ali.Pop_back();
	ali.Pop_back();
	ali.Pop_back();
	ali.Pop_back();
	ali.Pop_back();
	ali.Push_back(100);
	ali.Push_back(130);
	ali.Push_back(80);
	ali.Push_back(75);
	ali.Print();
	///
	Stack<std::string> a1;
	a1.Push_back("Hello");
	a1.Push_back("My Name is :");
	a1.Push_back(" Ali ");
	a1.Pop_back();
	a1.Pop_back();
	a1.Print();
	///
	Stack<double> a2(5);
	for (int i = 0; i < 50; i++) {
		a2.Push_back(i);
	}
	a2.Print();

}