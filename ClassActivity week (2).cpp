#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
 vector<int> heap;
 int parent(int i) { return (i - 1) / 2; }
 int left(int i) { return 2 * i + 1; }
 int right(int i) { return 2 * i + 2; }
public:
 void insert(int val) {
      heap.push_back(val);     
     heapifyUp(heap.size() - 1);
 }
 int extractMax() {
 if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int maxVal = heap[0];               
        heap[0] = heap.back();              
        heap.pop_back();                    
        if (!heap.empty()){ 
            heapifyDown(0);
        }

        return maxVal;
 return -1;
 }
 void display() {
 cout << "Heap: ";
 for (int v : heap) cout << v << " ";
 cout << endl;
 }
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
    void heapifyDown(int index) {
        int largest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
};
int main() {
cout << "Steven Saavedra" << endl;
 MaxHeap pq;
 pq.insert(10);
 pq.insert(30);
 pq.insert(20);
 pq.display();
 cout << "Extracted max = " << pq.extractMax() << endl;
 pq.display();
 return 0;
}