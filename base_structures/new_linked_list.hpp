#pragma once

#include "node.hpp"

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

LinkedList() {
    head = nullptr;
    tail = nullptr;
}

public:
    void push_back(T data) {
        Node<T>* temp = new Node<T>(data);

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->set_next(temp);
            tail = temp;
        }
    }

    void push_front(T data) {
        Node<T>* temp = new Node<T>(data);

        temp->set_next(head);

        head = temp;
    }
};