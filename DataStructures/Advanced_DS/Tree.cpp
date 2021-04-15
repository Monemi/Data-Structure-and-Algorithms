#include <iostream>
#include <vector>
template<class T>
class Node {
public:
	int children_count = 0;
	bool has_father = false;
	bool is_father = false;
	T data;
	Node<T>* father = nullptr;
	std::vector<Node<T>*> Children;
	Node(T Node_data) {
		data = Node_data;

	}
	bool AddChildren(Node<T>* child) {
		if (child->has_father == false) {
			Children.push_back(child);
			child->has_father = true;
			child->father = this;
			children_count++;
			is_father = true;
			return true;
		}
		else {
			return false;
		}

	}

private:
};

template <class T>
class Tree {
public:
	bool is_empty = true;
	Node<T>* Root = nullptr;


	void Add(Node<T>* father_node, T datas) {
		if (is_empty) {
			Node<T>* root = new Node<T>(datas);
			root->has_father = false;
			root->father = nullptr;
			Root = root;
			is_empty = false;
		}
		else {
			Node<T>* new_child = new Node<T>(datas);
			father_node->AddChildren(new_child);

		}
	}
	void Add(Tree<T>* sub_tree_Head, Node<T>* father_Node) {
		sub_tree_Head->Root->father = nullptr;
		father_Node->AddChildren(sub_tree_Head->Root);
	}
	void print_LRV(Node<T>* Now) {
		if (!is_empty && Root != nullptr) {

			for (int i = 0; i < Now->children_count; i++) {
				print_LRV(Now->Children[i]);
			}
			if (Now != Root) { std::cout << "Father Node: " << Now->father->data << std::endl; }

			else { std::cout << "Root Node " << std::endl; }
			std::cout << Now->data << std::endl;
			if (Now->father == nullptr) { return; }

		}
		else {
			std::cout << "Tree Havnt Root yet !!!" << std::endl;
		}
	}
	void print_VLR(Node<T>* Now) {
		if (!is_empty && Root != nullptr) {

			if (Now != Root) { std::cout << "Father Node: " << Now->father->data << std::endl; }
			else { std::cout << "Root Node " << std::endl; }
			std::cout << Now->data << std::endl;
			for (int i = 0; i < Now->children_count; i++) {
				print_VLR(Now->Children[i]);
			}

			if (Now->father == nullptr) { return; }

		}

		else { std::cout << "Tree Havnt Root yet !!!" << std::endl; }

	}
	bool Remove(Node<T>* Removing) {
		bool Removed = false;
		if (Removing != nullptr) {

			Removed = true;
		}
		else {
			Removed = false;
		}
		return Removed;
	}


};


int main() {
	Tree<int> tree;
	tree.Add(nullptr, 12);
	tree.Add(tree.Root, 18);
	tree.Add(tree.Root, 20);
	tree.Add(tree.Root->Children[0], 0);
	tree.Add(tree.Root->Children[1], 1000);
	tree.Add(tree.Root->Children[1], 2);
	tree.Add(tree.Root->Children[1], 3);
	tree.Add(tree.Root->Children[1]->Children[1], 1234);

	Tree<int> tree2;
	tree2.Add(nullptr, 7);
	tree2.Add(tree2.Root, 6);
	tree2.Add(tree2.Root, 5);

	tree.print_LRV(tree.Root);
	std::cout << "==================================" << std::endl;
	tree.print_VLR(tree.Root);

	tree.Add(&tree2, tree.Root);
	std::cout << "==================================" << std::endl;
	tree.print_VLR(tree.Root);
}