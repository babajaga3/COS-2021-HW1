#include <stdexcept>
#include <vector>
#include "shelf.cpp"
#include "./base_structures/linked_list.hpp"
#include "./base_structures/queue.hpp"

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
        int sum = 0;
        if (arrival_queue.is_empty()) {
            throw std::logic_error("Cannot sort items in an empty queue.");
        }

        Shelf current_shelf = Shelf();

        do {
            InputCrate ic = arrival_queue.dequeue();
            Crate crate = Crate(ic.weight, ic.uuid);

            for (int i = 0; i <= NUMBER_OF_SHELVES; i++) {
                try {
                    current_shelf.push(crate);
                    std::cout << crate.get_weight() << std::endl;;
                    break;
                } catch (std::range_error e) {
                    shelves.add(current_shelf);
                    current_shelf = Shelf();
                } catch (std::logic_error e) {}
            }
        } while (arrival_queue.is_empty() == false);

        shelves.add(current_shelf);
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
