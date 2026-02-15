#include <iostream>
#include <optional>
#include "./crate.cpp"
#include "../consts.hpp"

class Shelf {
    private:
        int top;
        Crate array[BULK_LIMIT];
        
        int totalWeight;
        
    public:
        Shelf() { top = -1; totalWeight = 0; }
        
        void push(Crate crate) {
            
            // handle overflow
            if (top >= BULK_LIMIT - 1) {
                // std::cout << "Stack overflow" << std::endl;
                return;
            }
            
            // handle weight limit
            if ((totalWeight + crate.getWeight()) >= WEIGHT_LIMIT) {
                // std::cout << "YOURE TOO FAT!!!" << std::endl;
                return;
            }
            
            array[++top] = crate;
            totalWeight += crate.getWeight();

            // std::cout << crate.getWeight() << " " << crate.getUuid() << std::endl;
            
            return;
        }
        
        Crate pop() {
            
            // handle if empty
            if (top < 0) {
                std::cout << "IM ALREADY EMPTY BRAT" << std::endl;
                return Crate(0, ""); // todo fix
            }
            
            Crate lastItem = array[--top];
            totalWeight -= lastItem.getWeight();
            
            return lastItem;
            
            // delete lastItem; bate we should do this i think
        }
        
        bool isFull(Crate crate) {            
            // handle weight limit
            if ((totalWeight + crate.getWeight()) > WEIGHT_LIMIT || top >= BULK_LIMIT - 1) {
                if ((totalWeight + crate.getWeight()) > WEIGHT_LIMIT) std::cout << "-- too much weight!" << std::endl;
                if (top >= BULK_LIMIT - 1) std::cout << "-- too many crates!" << std::endl;
                return true;
            }
            
            return false;
        }
        
        void print() {
            std::cout << " The total weight of head shelf is: " << totalWeight << std::endl;
        }
};