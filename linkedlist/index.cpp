#include "../node/index.cpp"
#include <iostream>
#include <vector>

template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  LinkedList() { head = tail = nullptr; }

  void add(T t) {
    Node<T> *n = new Node<T>(t);

    if (head == nullptr) {
      head = n;
      tail = n;
    } else {
      tail->setNext(n);
      tail = n;
    }
  }

  T* getHead() {
      return head->getData();
  }
};
