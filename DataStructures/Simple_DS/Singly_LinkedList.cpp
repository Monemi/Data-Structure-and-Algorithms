#include <iostream>
//Linked List FIFO implentation
//USE Templates For them
template <class T>
class Node {
public:
	Node* next;
	T data;
	Node(T data2) {
		this->next = nullptr;
		this->data = data2;
	}
};
template <class T>
class linkedList {
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	bool start = true;
public:
	
	linkedList() {

	}
	void Add(T Entered_Data) {
		Node<T> *NEWNODE=new Node<T>(Entered_Data);
		if (start) { head = NEWNODE; start = false; 
		tail = NEWNODE;
		}
		else{
			Node<T>* tmptail = tail;
			tail = NEWNODE;
			tmptail->next = tail;
		}
		
		

	}
	void Remove_First(){
		if ( head == tail ) {
			delete head;
			head = nullptr;
			tail = nullptr;
			start = true;
		}
		else{
			if(head!=nullptr){
				Node<T>* Tmp = head->next;
				delete head;
				head = Tmp;
			}
			
		}

	}

	void print(void) {
		Node<T>* Next=nullptr;
		Next = head;
		
		while (Next != nullptr) {
			std::cout << Next->data << " ";
			Next = Next->next;
		}
		std::cout << std::endl;
		
	}
	Node<T>* Find(T data) {
		bool Finded = false;
		Node<T>* Next = nullptr;
		Next = head;
		do{
			if(Next->data==data){
				Finded = true;
			}
			else {
				Next = Next->next;
			}
		
		} 		while (Next != nullptr && Finded == false);

		return Next;
	}
};

int main() {

}