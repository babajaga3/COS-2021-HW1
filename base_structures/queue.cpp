#include "../node/index.cpp"
#include <iostream>

template <typename T> class Queue {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  Queue() { head = tail = nullptr; }

  void enqueue(T s) {
    Node<T> *n = new Node<T>(s);

    if (tail == nullptr) {
      head = tail = n;
    } else {
      tail->SetNext(n);
      tail = n;
    }
  }
  void dequeue() {
    if (head == nullptr) {
      std::cout << "the quueue is empty" << std::endl;
      return;
    }

    Node<T> *old = head;
    head = head->GetNext();
    delete old;
    if (head == nullptr) { // only one element case
      tail = nullptr;
    }

    return;
  }
};
