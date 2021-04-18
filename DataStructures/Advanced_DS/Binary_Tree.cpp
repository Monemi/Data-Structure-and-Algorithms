#include <iostream>
template <class T >
class Node {
public:
	T data;
	Node<T>* right = nullptr;
	Node<T>* left = nullptr;
	Node() {}
	Node(T datas) {
		data = datas;
	}


};
template <class T>
class Queue {
public:
	bool Is_Empty = true;
	T data;
	int n = 1000;
	int Fulled = 0;
	int  Head = 0;
	int  Tail = 0;
	Queue() {}
	Queue(int Size) {
		n = Size;
	}
	Node<T>* arrp = new Node<T>[n];
	void Enqueue(Node<T>* add_item) {
		if (add_item != nullptr) {


			if (Is_Empty) {
				arrp[Tail] = *add_item;

			}
			else {
				Tail++;
				arrp[Tail] = *add_item;

			}
			Fulled++;
			this->Is_Empty = false;
		}
		else {
			return;
		}

	}
	Node<T>* dequeue(void) {
		if (Is_Empty) { return nullptr; }
		else {
			Node<T>* tmp = &arrp[Head];
			this->Head++;
			isempty();
			Fulled--;
			return tmp;
		}

	}
private:
	void isempty(void) {
		if (this->Fulled == 0) {
			this->Is_Empty = true;
		}
	}

};
template <class T >
class Binary_Tree {
public:
	bool is_Empty = true;
	int Size = 0;
	Node<T>* Root = nullptr;

	bool Add(Node<T>* father, T data) {
		bool Added = false;
		//=========
		if (is_Empty) {
			Node<T>* newnode = new Node<T>(data);
			Root = newnode;
			is_Empty = false;
			Added = true;
			Size++;
			return Added;
		}
		else {}
		//========
		if (father->right == nullptr || father->left == nullptr) {
			Node<T>* newnode = new Node<T>(data);
			if (father->left == nullptr) {
				father->left = newnode;
			}
			else {
				father->right = newnode;
			}

			Added = true;
			is_Empty = false;
			Size++;
		}
		else { Added = false; }
		return Added;
	}
	void Pre_Order(Node<T>* pilot) {

		if (pilot == nullptr) { return; }
		else {
			std::cout << pilot->data << " ";
			Pre_Order(pilot->left);
			Pre_Order(pilot->right);

		}

	}
	void Post_Order(Node<T>* pilot) {

		if (pilot == nullptr) { return; }
		else {
			Post_Order(pilot->left);
			Post_Order(pilot->right);
			std::cout << pilot->data << " ";

		}

	}
	void In_Order(Node<T>* pilot) {
		if (pilot == nullptr) { return; }
		else {
			In_Order(pilot->left);
			std::cout << pilot->data << " ";
			In_Order(pilot->right);


		}

	}
	void Level_Order(void) {
		Queue<T> queue;
		if (this->Root != nullptr)
			queue.Enqueue(this->Root);
		else return;
		while (!queue.Is_Empty) {
			Node<T>* node = queue.dequeue();
			std::cout << node->data << " ";

			if (node->left != nullptr) {
				queue.Enqueue(node->left);
			}

			if (node->right != nullptr) {
				queue.Enqueue(node->right);
			}
		}


	}

};

int main() {
	Binary_Tree<std::string> s;
	std::cout << "Binary Search Tree Traversal :\n\n";
	s.Add(nullptr, "Animals");
	s.Add(s.Root, "mammals");
	s.Add(s.Root, "fishes");
	s.Add(s.Root->left, "Human");
	s.Add(s.Root->left, "Dog");
	s.Add(s.Root->right, "shark");
	s.Add(s.Root->right, "tilapilla");
	std::cout << "Pre Order :\t ";
	s.Pre_Order(s.Root);
	std::cout << std::endl << "Post Order :\t ";
	s.Post_Order(s.Root);
	std::cout << std::endl << "IN Order :\t ";
	s.In_Order(s.Root);
	std::cout << std::endl << "Level Order :\t ";
	s.Level_Order();
}