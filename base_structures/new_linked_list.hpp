#pragma once

#include <stdexcept>
#include "node.hpp"

// Help was sourced from - https://www.learn-cpp.org/en/Linked_lists
template<typename T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_back(T data) {
        Node<T> *temp = new Node<T>(data);

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->set_next(temp);
            tail = temp;
        }

        size++;
    }

    void push_front(T data) {
        Node<T> *temp = new Node<T>(data);

        temp->set_next(head);

        head = temp;

        size++;
    }

    int get_size() const {
        return size;
    }

    T &get_element_at(const int index) const {
        if (index < 0 || index > size) {
            throw std::out_of_range("linked list - get_element_at: index out of range");
        }

        Node<T> *current = head;

        if (index == 0) return current->get_data();

        for (int i = 0; i < index; i++) {
            current = current->get_next();
        }

        return current->get_data();
    }
};
