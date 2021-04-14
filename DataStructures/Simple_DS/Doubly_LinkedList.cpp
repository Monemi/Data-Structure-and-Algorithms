#include <iostream>
//doubly Linked List implentation
//USE Templates For them
template <class T>
class Node {
public:
	Node* after;
	Node* before;
	T data;
	Node(T data2) {
		this->after = nullptr;
		this->before = nullptr;
		this->data = data2;
	}
};
template <class T>
class DlinkedList {
private:
	int count = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	bool start = true;
	void Remove_Middle(Node<T>* remove) {
		if (head == nullptr || tail == nullptr) {/*Do not Remove*/ }
		else {
			//Remove is Possible
			if (remove->after == nullptr) {
				Remove_Last();

			}
			else if (remove->before == nullptr) {
				Remove_First();
			}
			else {
				remove->before->after = remove->after;
				remove->after->before = remove->before;
				delete remove;
			}

		}
	}

public:

	DlinkedList() {}
	void Insert_First(T Entered_Data) {
		Node<T>* NEWNODE = new Node<T>(Entered_Data);
		NEWNODE->before = nullptr;
		NEWNODE->after = head;
		if (start) {
			head = NEWNODE; tail = head; start = false;
		}
		else {
			Node<T>* Temp = head;
			head = NEWNODE;
			Temp->before = NEWNODE;
		}
		count++;
	}

	void Insert_Last(T Entered_Data) {
		Node<T>* NEWNODE = new Node<T>(Entered_Data);
		NEWNODE->after = nullptr;
		NEWNODE->before = tail;
		if (start) {
			tail = NEWNODE; head = tail; start = false;
		}
		else {
			Node<T>* Temp = tail;
			tail = NEWNODE;
			Temp->after = NEWNODE;
		}
		count++;
	}


	void Remove_First() {
		if (head == nullptr) {
			//Dont remove
		}
		else {
			//	Remove
			Node<T>* tmp = head->after;
			delete head;
			if (tmp != nullptr) {
				head = tmp;
				head->before = nullptr;
			}
			else {
				head = nullptr;
				tail = nullptr;
				start = true;
			}
			count--;
		}

	}
	void Remove_Last() {
		if (tail == nullptr) {
			//Dont remove
		}
		else {
			//	Remove
			Node<T>* tmp = tail->before;
			delete tail;
			if (tmp != nullptr) {
				tail = tmp;
				tail->after = nullptr;
			}
			else {
				tail = nullptr;
				head = nullptr;
				start = true;
			}
			count--;
		}
	}

	void print(void) {
		Node<T>* Next = nullptr;
		Next = head;

		while (Next != nullptr) {
			std::cout << Next->data << " ";
			Next = Next->after;
		}
		std::cout << std::endl;

	}
	Node<T>* Find(T data) {
		Node<T>* tmp = nullptr;
		tmp = head;
		while (tmp != nullptr) {
			if (tmp->data == data) { break; }
			else { tmp = tmp->after; }
		}
		return tmp;


	}
	void Remove_At(int index) {
		int counter = 0;
		Node<T>* tmp = nullptr;
		tmp = head;
		if (index < count) {
			while (tmp != nullptr) {
				if (counter == index) {
					//Do Remove Function
					Remove_Middle(tmp);
					count--;
					break;
				}
				else { tmp = tmp->after; }
				counter++;
			}
		}


	}
	void Remove_after(Node<T>* myremove) {
		if (myremove != nullptr) { Remove_Middle(myremove->after); }
		else {}



	}
	void Remove_before(Node<T>* myremove) {
		if (myremove != nullptr) {
			Remove_Middle(myremove->before);
		}
		else {}
	}
	void Insert_after(Node<T>* add, T data) {
		Node<T>* NEWNODE = new Node<T>(data);
		if (add != nullptr) {
			if (head == nullptr || tail == nullptr) {
				Insert_First(data);
			}
			else {
				if (add->after == nullptr) {
					Insert_Last(data);
				}
				else if (add->before == nullptr) {
					Insert_First(data);
				}
				else {
					NEWNODE->after = add->after;
					add->after = NEWNODE;
					NEWNODE->before = add;
				}


			}
		}
		else {}
	}
	void Insert_before(Node<T>* add, T data) {
		Node<T>* NEWNODE = new Node<T>(data);
		if (add != nullptr) {
			add = add->before;
			if (head == nullptr || tail == nullptr) {
				Insert_First(data);
			}
			else {

				if (add == nullptr) {
					Insert_First(data);
				}
				else {
					NEWNODE->after = add->after;
					add->after = NEWNODE;
					NEWNODE->before = add;
				}


			}
		}
		else {}

	}
	bool Is_Empty() {
		if (head == nullptr && tail == nullptr) {
			return true;
		}
		else {
			return false;
		}

	}
	bool Swap(Node<T>* a, Node<T>* b) {
		bool Swapped = false;
		if (!Is_Empty() && a != nullptr && b != nullptr) {
			T tmpdata;
			tmpdata = a->data;
			a->data = b->data;
			b->data = tmpdata;
			Swapped = true;
		}
		else {
			Swapped = false;
		}
		return Swapped;
	}
};
int main() {
	DlinkedList<int> ll;
	ll.Insert_First(12);
	ll.Insert_First(13);
	ll.Insert_First(14);
	ll.Swap(ll.Find(12), ll.Find(13));
	ll.print();

}
