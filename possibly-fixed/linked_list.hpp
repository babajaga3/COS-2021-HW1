#pragma once

#include "node.hpp"
#include <stdexcept>

template<typename T>
class LinkedList {
    Node<T> *head;
    int max_number_of_elements;

public:
    LinkedList() {
        head = nullptr;
        max_number_of_elements = 0;
    }

    LinkedList(const int max_number_of_elements) {
        head = nullptr;
        this->max_number_of_elements = max_number_of_elements;
    }

    void add(T t) {
        int number_of_elements = 1;
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
            number_of_elements++;

            if (number_of_elements > max_number_of_elements) {
                throw std::out_of_range("Cannot add more elements");
            }
        }

        // set the next one.
        current->set_next(new_node);
    }

    // todo unused for now
    void remove() {
    }

    T get_element_at(const int index) {
        if (index < 0) {
            throw std::out_of_range("Cannot get element at index"); // todo change
            // return;
        }

        // get the current (first, head)
        Node<T> *current = head;

        // if index is 0 return the head data
        if (index == 0) return current->get_data();

        // loop through the list until landing at the right element
        for (int i = 0; i < index; i++) {
            if (!current) throw std::out_of_range("Cannot get element at index");
            current = current->get_next();
        }

        if (!current) throw std::out_of_range("Cannot get element at index");

        // return it
        return current->get_data();
    }

    void set_element_at(const int index, const T data) {
        if (index < 0) {
            throw std::out_of_range("Cannot get element at index"); // todo change
            // return;
        }

        // get current (first)
        Node<T> *current = head;

        // change the head
        if (index == 0) {
            Node<T> *old_head = current;
            Node<T> *new_node = new Node<T>(data);

            head = new_node;
            head->set_next(old_head);

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
        new_node->set_next(current);
    }
};
