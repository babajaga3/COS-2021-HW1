#include <iostream>
#include "crate.cpp"
#include "config.hpp"

class Shelf {
    int top;
    int totalWeight;
    Crate array[BULK_LIMIT]{};

public:
    Shelf() {
        top = -1;
        totalWeight = 0;
    }

    void push(Crate crate) {
        if (top >= BULK_LIMIT - 1) {
            throw std::range_error("shelf overflow");
        }

        // handle weight limit
        if ((totalWeight + crate.get_weight()) > WEIGHT_LIMIT) {
            throw std::range_error("shelf is too heavy");
        }

        if (top < 0) {
            array[++top] = crate;
            totalWeight += crate.get_weight();
        }
        else {
            if(array[top].get_weight() >= crate.get_weight()) {
                array[++top] = crate;
                totalWeight += crate.get_weight();
            }
            else throw std::logic_error("cannot put heavier crate on lighter one");
        }

    }

    void pop() {
        // handle if empty
        if (top < 0) {
            throw std::range_error("shelf underflow");
        }

        Crate lastItem = array[--top];
        totalWeight -= lastItem.get_weight();
    }

    void print() {
        for (int i = 0; i < BULK_LIMIT; i++) {
            std::cout << array[i].get_weight() << " ";
        }

        std::cout << std::endl;

        if (totalWeight > WEIGHT_LIMIT) {
            std::cout << "BAD" << std::endl;
        } else {
            std::cout << "GOOD" << std::endl;
        }
    }

};
