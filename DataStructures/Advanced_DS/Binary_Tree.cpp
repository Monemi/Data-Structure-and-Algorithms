#include <iostream>
template <class T >
class Node {
public:
	T data;
	Node<T>* right = nullptr;
	Node<T>* left = nullptr;
	Node(T datas) {
		data = datas;
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

};

int main() {
	Binary_Tree<std::string> s;
	s.Add(nullptr, "Heivanat");
	s.Add(s.Root, "mammals");
	s.Add(s.Root, "fishes");
	s.Add(s.Root->left, "ensan");
	s.Add(s.Root->left, "sag");
	s.Add(s.Root->right, "shark");
	s.Add(s.Root->right, "tilapilla");
	s.Pre_Order(s.Root);

}