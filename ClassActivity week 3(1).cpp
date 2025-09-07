#include <iostream>
using namespace std;
class CircularQueue {
 int *arr;
 int front, rear, capacity, count;
public:
 CircularQueue(int size = 5) {
 capacity = size;
 arr = new int[capacity];
 front = 0;
 rear = -1;
 count = 0;
 }
 void enqueue(int x) {
 if (count == capacity) {
            cout << "Queue is full, cannot enqueue " << x << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
 

 }
 int dequeue() {
        if (count == 0) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
 return -1;
 }
 void display() {
 cout << "Queue: ";
 for (int i = 0; i < count; i++) {
 cout << arr[(front + i) % capacity] << " ";
 }
 cout << endl;
 }
};
int main() {
cout << "Steven Saavedra"<< endl;
 CircularQueue q(5);
 q.enqueue(10);
 q.enqueue(20);
 q.enqueue(30);
 q.display();
 q.dequeue();
 q.display();
 return 0;
}