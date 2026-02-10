#include <iostream>
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
                std::cout << "Stack overflow" << std::endl;
                return;
            }
            
            // handle weight limit
            if ((totalWeight + crate.getWeight()) >= WEIGHT_LIMIT) {
                std::cout << "YOURE TOO FAT!!!" << std::endl;
                return;
            }
            
            array[++top] = crate;
            totalWeight += crate.getWeight();

            std::cout << "pushed!" << std::endl;
        }
        
        void pop() {
            
            // handle if empty
            if (top < 0) {
                std::cout << "IM ALREADY EMPTY BRAT" << std::endl;
                return;
            }
            
            Crate lastItem = array[--top];
            totalWeight -= lastItem.getWeight();
            
            // delete lastItem; bate we should do this i think
        }       
};