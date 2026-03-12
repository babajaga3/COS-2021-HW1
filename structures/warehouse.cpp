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

    void sort_two() { // new sorting algorithm design for hw 2
        // Step 1: check if there is an existing shelf?
        // If no: create shelf, run function again
        // If yes: continue

        // Step 2: Check if sorting floor is empty?
        // If yes: get crate from arrival queue, continue
        // If no: get last element from sf, continue

        // Step 3: Using element,
        // Run function `can_put_on_shelf`?
        // If yes: put and
        // Run function again

        // If no: If you remove last element, combine
            //  new total weight with incoming element
                // Is new total weight > old total weight && < max weight?
                    // If yes:
                    // remove last element and add to sorting floor

                    /*
                     *  check if you can put it on top
                     *
                     *  if no:
                     *      remove last element to sorting floor
                     *      try again
                     *
                     *  if yes:
                     *      put to shelf
                     *      run whole function recursively
                     *
                     */

                    // If no:
                        // remove the element before that last checked index - 1
                        // try check again
                        // if none work - go to next shelf (create new shelf and pass it in the function), and try whole function again.

    }

    void main_function() {

    }

    void can_put_on_shelf() {
        // Check if you can add point-blank
        // 1. number of elements
        // 2. order
        // 3. max weight
    }
};
