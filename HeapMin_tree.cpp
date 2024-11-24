#include <iostream>
#include <vector>
#include <algorithm>

class MinHeap {
public:
    std::vector<int> Heap;

    void Heapify(int index) {
        int left = 2 * index + 1;  
        int right = 2 * index + 2; 
        int smallest = index;

        if (left < Heap.size() && Heap[left] < Heap[smallest]) {
            smallest = left;
        }

        if (right < Heap.size() && Heap[right] < Heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            std::swap(Heap[smallest], Heap[index]);
            Heapify(smallest); 
        }
    }

    void insert(int val) {
        Heap.push_back(val); 
        int index = Heap.size() - 1;

        while (index != 0 && Heap[(index - 1) / 2] > Heap[index]) {
            std::swap(Heap[(index - 1) / 2], Heap[index]);
            index = (index - 1) / 2;
        }
    }

    void deleteRoot() {
        if (Heap.empty()) {
            std::cout << "The Heap is empty" << std::endl;
            return;
        }

        Heap[0] = Heap[Heap.size() - 1];
        Heap.pop_back();

        Heapify(0);
    }

    int getRoot() {
        if (Heap.empty()) {
            std::cout << "The Heap is empty" << std::endl;
            return -1; 
        }
        return Heap[0];
    }

    void DisplayHeap() {
        for (int i = 0; i < Heap.size(); i++) {
            std::cout << Heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap myHeap;
    int n;
    std::cout << "Please input the number of elements\n";
    std::cin >> n;
    int k;

    for (int i = 0; i < n; i++) {
        std::cin >> k;
        myHeap.insert(k);
    }

    std::cout << "What do you want to do? 1.delete the root 2.Get Root 3.Display\n";
    int answer;
    std::cin >> answer;

    switch (answer) {
    case 1:
        myHeap.deleteRoot();
        myHeap.DisplayHeap();
        break; 
    case 2:
        std::cout << "Root: " << myHeap.getRoot() << std::endl;
        break; 
    case 3:
        myHeap.DisplayHeap();
        break; 
    default:
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
