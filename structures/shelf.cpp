#include <iostream>
#include "crate.cpp"
#include "../config.hpp"

class Shelf {
    int top;
    int totalWeight;
    Crate array[BULK_LIMIT];

public:
    Shelf() : top(-1), totalWeight(0) {}

    void push(Crate crate) {
        if (top >= BULK_LIMIT - 1) {
            throw std::range_error("shelf overflow");
        }

        if ((totalWeight + crate.get_weight()) > WEIGHT_LIMIT) {
            throw std::range_error("shelf is too heavy");
        }

        if (is_empty() || array[top].get_weight() >= crate.get_weight()) {
            array[++top] = crate;
            totalWeight += crate.get_weight();
        } else {
            throw std::logic_error("cannot put heavier crate on lighter one");
        }
    }

    Crate pop() {
        if (is_empty()) {
            throw std::range_error("shelf underflow");
        }

        Crate lastItem = array[top];
        array[top--] = Crate();
        totalWeight -= lastItem.get_weight();

        return lastItem;
    }

    Crate get_crate(const int index) const {
        if (index < 0 || index > top) {
            throw std::out_of_range("shelf - get_crate: cannot get element at index");
        }

        return array[index];
    }

    void print() {
        if (is_empty()) {
            return;
        }

        for (int i = 0; i <= top; i++) {
            std::cout << array[i].get_weight() << "\n";
        }
    }

    bool can_put_on_top(const Crate& crate) const {
        if (is_empty()) {
            return true;
        }

        return array[top].get_weight() > crate.get_weight();
    }

    bool can_put_on_shelf(const Crate& crate) const {
        if (top >= BULK_LIMIT - 1) {
            return false;
        }

        if ((totalWeight + crate.get_weight()) > WEIGHT_LIMIT) {
            return false;
        }

        if (is_empty()) {
            return true;
        }

        return array[top].get_weight() > crate.get_weight();
    }

    Crate last() const {
        if (is_empty()) {
            throw std::range_error("shelf is empty");
        }

        return array[top];
    }

    int get_total_weight() const {
        return totalWeight;
    }

    bool is_empty() const {
        return top < 0;
    }
};