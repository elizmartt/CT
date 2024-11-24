#include <iostream>
class Node {
public:
	std::pair<int, int>keyValue;
	Node* next;
	Node(int key, int value) :keyValue(key, value), next(nullptr) {};

};
class LinkedList {
public:
	Node* head;
	LinkedList() :head(nullptr) {};
	void insert(int key, int value) {
		Node* NewNode = new Node(key, value);
		if (!head) {
			head = NewNode;
			return;
		}
		Node* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = NewNode;

	}
	void remove(int key) {
		if (head && head->keyValue.first == key) {  
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* current = head;
		while (current && current->next) {  
			if (current->next->keyValue.first == key) {
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
			}
			else {
				current = current->next;
			}
		}
	}

	void print() {
		Node* temp = head;
		while (temp) {
			std::cout << "{" << temp->keyValue.first << ":" << temp->keyValue.second << "}->";
			temp = temp->next;
		}
		std::cout << "NULL" << std::endl;
	}


};
class HashTable {
private:
	static const int size = 10;
	LinkedList table[size];
public:
	void insert(int key, int value) {
		int index = (key * 31) % size;
		table[index].insert(key, value);

	}
	void remove(int key) {
		int index = (key * 31) % size;
		table[index].remove(key);
	}
	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << "Bucket" << i << ":";
			table[i].print();
		}

	}



};
int main() {
	HashTable myHash;
	int key;
	int value;
	int number;
	std::cout << "Please input the count of numbers to be inserted";
	std::cin >> number;
	for (int i = 0; i < number; i++) {
		std::cin >> key;
		std::cin >> value;
		myHash.insert(key, value);
	}
	myHash.print();
	std::cout << "Please input the key of removing value";
	std::cin >> key;
	myHash.remove(key);
	myHash.print();

}