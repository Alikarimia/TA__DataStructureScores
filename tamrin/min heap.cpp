#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
	//insert
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
//remove
    void removeMin() {
        if (heap.empty()) {
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
//display
    void display() {
        for (int i = 0; i < heap.size(); ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
//size
    int size() {
        return heap.size();
    }
//min
    int getMin() {
        if (heap.empty()) {
            return -1; // ?? ?? ????? ?????? ???? ???? ???? ???? ???? ???? MinHeap
        }
        return heap[0];
    }

    void decreaseKey(int index, int newValue) {
        if (index >= heap.size()) {
            return;
        }
        
        heap[index] = newValue;
        heapifyUp(index);
    }
    //search
    bool search(int value) {
       for (int i = 0; i < heap.size(); ++i) {
           if (heap[i] == value) {
               return true;
           }
       }
       return false;
   }

};

int main() {
    MinHeap minHeap;
    
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(1);
    
    minHeap.display(); // 1 3 8 5
    
    minHeap.removeMin();
    
    minHeap.display(); // 3 5 8

    std::cout << "Size of MinHeap=> " << minHeap.size() << std::endl; // 3

    std::cout << "Minimum value in MinHeap=> " << minHeap.getMin() << std::endl; // 3

    minHeap.decreaseKey(2, 2);
    
    minHeap.display(); // Output: 2 3 5

    return 0;
}