#pragma once

#include "node.hpp"
#include <stdexcept>

template<typename T>
class LinkedList {
    Node<T> *head;
    int max_number_of_elements;
    int size;

public:
    LinkedList() {
        head = nullptr;
        max_number_of_elements = 0;
        size = 0;
    }

    LinkedList(const int max_number_of_elements) {
        head = nullptr;
        this->max_number_of_elements = max_number_of_elements;
        size = 0;
    }

    void add(T t) {
        // create a new node
        Node<T> *new_node = new Node<T>(t);

        // if there isn't a head, add it as head and stop
        if (head == nullptr) {
            head = new_node;
            return;
        }

        // get the current one (head, 1st)
        Node<T> *current = head;

        // loop through the whole list until the last element, then..
        while (current->get_next()) {
            current = current->get_next();
        }

        // set the next one.
        current->set_next(new_node);
        ++size;
    }

    // todo unused for now
    void remove() {
    }

    Node<T>& get_element_at(int index) {
        if (index < 0) {
            throw std::out_of_range("Index cannot be negative");
        }

        Node<T>* current = head;

        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                throw std::out_of_range("linked list - get_element_at: Index out of range");
            }
            current = current->get_next();
        }

        if (current == nullptr) {
            throw std::out_of_range("linked list - get_element_at: Index out of range");
        }

        return *current;
    }

    void set_element_at(const int index, const T data) {
        if (index < 0) {

            if (index - 1 == size) {
                this->add(data);
                return;
            }

            throw std::out_of_range("set element at: Cannot get element at index");
        }

        Node<T> *current = head;

        // change the head
        if (index == 0) {
            Node<T> *new_node = new Node<T>(data);
            head = new_node;

            return;
        }

        Node<T> *parent_to_current = nullptr;

        // go to right index
        for (int i = 0; i < index; i++) {
            parent_to_current = current;
            current = current->get_next();
        }

        // insert element
        Node<T> *new_node = new Node<T>(data);
        parent_to_current->set_next(new_node);
        new_node->set_next(current->get_next());
    }

    bool is_empty() {
        return head == nullptr;
    }
};
