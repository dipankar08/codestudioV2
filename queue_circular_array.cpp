/***************************************************
 * Title : Queue implementation.
 * Author: Dipankar Dutta
 ****************************************************/

#include <iostream>
using namespace std;
template <class T> class Queue {
private:
  int size, rear, front;
  T *s_ptr;

public:
  Queue(int);
  void enqueue(T val);
  T dequeue();
  bool isFull();
  bool isEmpty();
};
template <class T> Queue<T>::Queue(int maxsize) {
  size = maxsize;
  rear = 0;  // next insertion point
  front = 0; // front position.
  s_ptr = new T(size);
}
template <class T> void Queue<T>::enqueue(T val) {
  if (!isFull()) {
    s_ptr[rear] = val;
    rear = (rear + 1) % size;
  } else {
    cout << "Queue is full" << endl;
  }
}
template <class T> T Queue<T>::dequeue() {
  if (!isEmpty()) {
    int temp = s_ptr[front];
    front = (front + 1) % size;
    return temp;
  } else {
    cout << "Queue is empty" << endl;
    return -1;
  }
}
template <class T> bool Queue<T>::isEmpty() { return front == rear; }

template <class T> bool Queue<T>::isFull() {
  return front == ((rear + 1) % size);
}

int main() {
  Queue<int> qu(3);
  qu.enqueue(1);
  qu.enqueue(2);
  qu.enqueue(3);
  qu.enqueue(4);
  while (!qu.isEmpty()) { // 1 , 2 , 3
    cout << qu.dequeue() << endl;
  }
  cout << qu.dequeue() << endl; // Queue is empty
  qu.enqueue(1);                // Queue is full

  return 0;
}
