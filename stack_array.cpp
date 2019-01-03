/***************************************************
 * Title : Arry Impl of stack
 * Author: Dipankar Dutta
 ****************************************************/

#include <iostream>
using namespace std;
template <class T> class Stack {
private:
  int size, top;
  T *s_ptr;

public:
  Stack(int);
  void push(T val);
  T pop();
  bool isFull();
  bool isEmpty();
};
template <class T> Stack<T>::Stack(int maxsize) {
  size = maxsize;
  top = -1;
  s_ptr = new T(size);
}
template <class T> void Stack<T>::push(T val) {
  if (!isFull()) {
    s_ptr[++top] = val;
  } else {
    cout << "Stack is full" << endl;
  }
}
template <class T> T Stack<T>::pop() {
  if (!isEmpty()) {
    return s_ptr[top--];
  } else {
    cout << "Stack is empty" << endl;
    return -1;
  }
}
template <class T> bool Stack<T>::isFull() { return top == size - 1; }

template <class T> bool Stack<T>::isEmpty() { return top == -1; }

int main() {
  Stack<int> st(3);
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  while (!st.isEmpty()) {
    cout << st.pop() << endl;
  }
  cout << st.pop() << endl;

  return 0;
}
