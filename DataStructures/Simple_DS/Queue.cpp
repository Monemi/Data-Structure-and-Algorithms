#include <iostream>
//Queque implementation -- FIFO
//USE Templates For them
template <class T>
class Queue {
private:
	int rear = 0;
	int front = 0;
	int n = 1000;
	T* memorypointer;
public:
	Queue(){
		memorypointer = new T[n];
		
	}
	Queue(int Size) {
		this->n = Size;
		memorypointer = new T[n];
	}
	void Equeque(T data) {
		if(front>n){
			std::cout << "Queue is Full !!"<<std::endl;
		}
		else{
			
			memorypointer[front] = data;
			front++;
		}
		
	}
	void Dequeque(void){
		if (rear > front) { rear = front; }
		else{ 
			
			std::cout << "Queue is Empty !!" << std::endl;
			rear++; }
		
	}
	void Print(void){
		int y = rear;
		
		for (y; y < front; y++) {
			std::cout << this->memorypointer[y] << " " ;
	}
		std::cout << std::endl;
		std::cout <<this->rear <<" "<<this->front<<std::endl;


	}

};

int main() {
	Queue<std::string> ali(100);
	ali.Equeque("A");
	ali.Equeque("B");
	ali.Equeque("C");
	ali.Print();
}