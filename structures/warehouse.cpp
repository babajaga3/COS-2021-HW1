#include <vector>
#include "shelf.cpp"
#include "../base_structures/linked_list.hpp"
#include "../base_structures/queue.hpp"

class Warehouse {
    // 10 shelves
    LinkedList<Shelf> shelves;
    // 1 arrival queue
    Queue<InputCrate> arrival_queue;
    // 1 sorting floor
    std::vector<Crate> sorting_floor;

public:
    Warehouse() {
        shelves = LinkedList<Shelf>(NUMBER_OF_SHELVES);
        arrival_queue = Queue<InputCrate>();
        // todo sorting floor later
    }

    Queue<InputCrate> get_arrival_queue() const {
        return arrival_queue;
    }

    void set_arrival_queue(Queue<InputCrate> arrival_queue) {
        this->arrival_queue = arrival_queue;
    }

    void sort() {
        if (arrival_queue.is_empty()) {
            throw std::logic_error("Cannot sort items in an empty queue.");
        }

        Shelf current_shelf = Shelf();

        do {
            InputCrate ic = arrival_queue.dequeue();
            Crate crate = Crate(ic.weight, ic.uuid);


            // crate.set_weight(ic.weight);
            // crate.set_uuid(ic.uuid);

            // std::cout << "________" << std::endl;
            // std::cout << "current crate: " << crate.get_uuid() << " " << crate.get_weight() << std::endl;
            // std::cout << "________" << std::endl;
            //
            // std::cout << "looping through shelves..." << std::endl;
            for (int i = 0; i <= NUMBER_OF_SHELVES; i++) {
                // current_shelf.print();

                // std::cout << "currently at shelf no.: " << i << std::endl;

                try {
                    // std::cout << "trying to push there..." << std::endl;
                    current_shelf.push(crate);
                    // std::cout << "successfully pushed there, moving on to next crate..." << std::endl;
                    // std::cout << std::endl;
                    // std::cout << "current items in shelf: " << std::endl;
                    // current_shelf.print();
                    break;
                } catch (std::range_error e) {

                    shelves.add(current_shelf);
                    current_shelf = Shelf();

                    // std::cout << "failed to push crate." << std::endl;
                    // std::cout << "error is: " << _e.what() << std::endl;
                    // std::cout << "trying next shelf..." << std::endl;
                    // if (i == 9) {
                    //     i = -1;
                    // }

                    // std::cout << _e.what() << std::endl;
                }
            }
        } while (arrival_queue.is_empty() == false);
    }

    void print() {
        for (int i = 0; i < NUMBER_OF_SHELVES; i++) {
            Shelf curr_shelf = shelves.get_element_at(i);
            std::cout << "_______" << std::endl;
            std::cout << "SHELF " << i + 1 << std::endl;
            curr_shelf.print();
        }
    }
};
