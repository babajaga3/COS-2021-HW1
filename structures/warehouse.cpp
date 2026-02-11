#include <queue>
#include <vector>
#include "./shelf.cpp"

class Warehouse {
    private:
        Shelf shelves[SHELVES_SIZE];
        std::queue<InputCrate> queue;
        std::vector<Crate> sortingFloor;
        
    public:
        void setQueue(std::queue<InputCrate> queue) {
            this->queue = queue;
        }
        
        void sort() {
            // todo
            // loop through shelves and put wherever conditions are met (see instruction)
            // loop until all crates are put or impossible to put
        }
};
