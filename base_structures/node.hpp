#pragma once

template<typename T>
class Node {
    T data;
    Node *next;

public:
    Node(T data) {
        this->data = data;
        next = nullptr;
    }

    T& get_data() {
        return data;
    }

    Node *get_next() {
        return next;
    }

    void set_next(Node *n) {
        next = n;
    }
};
