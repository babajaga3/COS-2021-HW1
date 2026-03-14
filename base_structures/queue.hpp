#pragma once

#include "node.hpp"
#include <iostream>

template<typename T>
class Queue {
    Node<T> *head;

public:
    Queue() { head = nullptr; }

    // essentially prepend that shit
    void enqueue(T s) {
        Node<T> *new_node = new Node<T>(s);

        if (head == nullptr) {
            head = new_node;
            return;
        }

        // fix the old head
        Node<T> *old_head = head;

        // new head
        head = new_node;
        head->set_next(old_head);
    }

    T dequeue() {
        // make sure queue is not empty
        if (head == nullptr) {
            throw std::length_error("Queue is empty");
            // return;
        }

        if (head->get_next() == nullptr) {
            T data_to_return = head->get_data();
            head = nullptr;
            delete head;
            return data_to_return;
        }

        // temp pointers
        Node<T> *parent_of_current = nullptr;
        Node<T> *current = head;

        // loop through until you reach the end
        while (current->get_next()) {
            parent_of_current = current;
            current = current->get_next();
        }

        // TOTAL DESTRUCTION
        Node<T> *to_delete = current;
        T data_to_return = to_delete->get_data();

        delete to_delete;
        if (parent_of_current != nullptr) parent_of_current->set_next(nullptr);



        return data_to_return;
    }

    bool is_empty() {
        return head == nullptr;
    }
};
