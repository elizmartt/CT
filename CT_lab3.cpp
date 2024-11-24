#include <iostream>
#include <cstdlib>    
#include <ctime>     

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL";
    }

    void fillRandom(int size) {
        std::srand(std::time(nullptr));
        for (int i = 0; i < size; ++i) {
            int randomDigit = std::rand() % 10;
            insert(randomDigit);
        }
    }
};

LinkedList sumLists(LinkedList& list1, LinkedList& list2, int* carryArr, int* modArr, int& size) {
    Node* l1 = list1.head;
    Node* l2 = list2.head;
    LinkedList result;
    int carry = 0;
    size = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;        
        int modValue = sum % 10; 
        result.insert(modValue); 

        *(carryArr + size) = carry;
        *(modArr + size) = modValue;
        ++size;
    }

    return result;
}

bool TestList(int* carryArr, int* modArr, LinkedList& result, int size) {
    Node* temp = result.head;
    int i = 0;
    std::cout<<std::endl << "The array values"<<std::endl;
    while (temp != nullptr && i < size) {
        int expectedValue = (*(modArr + i)); 

        if (temp->data != expectedValue) {
            return false; 
        }
        std::cout << expectedValue<<" ";
        temp = temp->next;
        ++i;
    }

    return (temp == nullptr && i == size);
    
}

int main() {
    LinkedList list1, list2;

    int size1, size2;
    std::cout << "Enter the size of the first list: ";
    std::cin >> size1;
    std::cout << "Enter the size of the second list: ";
    std::cin >> size2;

    list1.fillRandom(size1);
    list2.fillRandom(size2);

    std::cout << "Linked list 1: ";
    list1.display();
    std::cout << std::endl << "Linked list 2: ";
    list2.display();

    int maxSize = (size1 > size2 ? size1 : size2) + 1;
    int* carryArr = new int[maxSize]; 
    int* modArr = new int[maxSize];   
    int resultSize = 0;  

    LinkedList result = sumLists(list1, list2, carryArr, modArr, resultSize);

    std::cout << "The final linked list: " <<std::endl;
    result.display();

    if (TestList(carryArr, modArr, result, resultSize)) {
        std::cout << std::endl << "The test passed: the final list matches the expected array sums!" << std::endl;
    }
    else {
        std::cout << std::endl << "The test failed: the final list does not match the array sums!" << std::endl;
    }

    list1.display();
    list2.display();
    delete[] carryArr;
    delete[] modArr;

    return 0;
}
