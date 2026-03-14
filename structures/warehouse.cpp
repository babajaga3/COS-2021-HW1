#include <stdexcept>
#include <vector>
#include "shelf.cpp"
#include "../base_structures/linked_list.hpp"
#include "../base_structures/queue.hpp"

class Warehouse {
    // 10 shelves
    LinkedList<Shelf> shelves;
    // 1 arrival queue
    Queue<InputCrate>* arrival_queue;
    // 1 sorting floor
    std::vector<Crate> sorting_floor;

public:
    Warehouse() {
        shelves = LinkedList<Shelf>(NUMBER_OF_SHELVES);
        arrival_queue = new Queue<InputCrate>();
        // todo sorting floor later
    }

    ~Warehouse() {
        delete arrival_queue;
    }

    Queue<InputCrate>& get_arrival_queue() const {
        return *arrival_queue;
    }

    void set_arrival_queue(Queue<InputCrate>* arrival_queue) {
        this->arrival_queue = arrival_queue;
    }

    void sort() {
        int sum = 0;
        if (arrival_queue->is_empty()) {
            throw std::logic_error("Cannot sort items in an empty queue.");
        }

        Shelf current_shelf = Shelf();

        do {
            InputCrate ic = arrival_queue->dequeue();
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
        } while (arrival_queue->is_empty() == false);

        shelves.add(current_shelf);
    }

    void print() {
        std::cout << "function finished\n\n";
        for (int i = 0; i < NUMBER_OF_SHELVES; i++) {
            Shelf curr_shelf = shelves.get_element_at(i).get_data();
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

    void sort_items_in_shelf(Shelf& current_shelf, Crate& current_crate, const int index) {
        const Crate last = current_shelf.last();

        const int new_total_weight =
            current_shelf.get_total_weight() + current_crate.get_weight() - last.get_weight();

        if (new_total_weight > current_shelf.get_total_weight() && new_total_weight < WEIGHT_LIMIT) {

            while (!current_shelf.can_put_on_top(current_crate)) {
                const Crate last_shelf = current_shelf.pop();
                this->sorting_floor.push_back(last_shelf);
            }

            current_shelf.push(current_crate);

            shelves.set_element_at(0, current_shelf);

            main_sorting_function(index);

        } else {
            main_sorting_function(index + 1);
        }
    }

    void main_sorting_function(const int index) {
        Shelf current_shelf;
        Crate current_crate;

        if (!shelves.is_empty()) {
            try {
                current_shelf = shelves.get_element_at(index).get_data();
            } catch (std::out_of_range e) {
                const Shelf new_shelf;
                shelves.add(new_shelf);

                main_sorting_function(index);
                return;
            }
        }

        if (this->sorting_floor.empty()) {
            try {
                const InputCrate ic = arrival_queue->dequeue();
                current_crate = Crate(ic.weight, ic.uuid);
            } catch (std::length_error e) {
                std::cout << "both arrival queue and sorting floor are empty" << std::endl;
                this->print();
                exit(0);
            }
        } else {
            current_crate = this->sorting_floor.back();
            this->sorting_floor.pop_back();
        }

        if (current_shelf.can_put_on_shelf(current_crate)) {
            current_shelf.push(current_crate);
            // shelves.set_element_at(index, current_shelf);
        } else {
            const Crate last = current_shelf.last();

            const int new_total_weight =
                current_shelf.get_total_weight() + current_crate.get_weight() - last.get_weight();

            if (new_total_weight > current_shelf.get_total_weight() && new_total_weight <= WEIGHT_LIMIT) {

                while (!current_shelf.can_put_on_top(current_crate)) {
                    const Crate last_shelf = current_shelf.pop();
                    this->sorting_floor.push_back(last_shelf);
                }

                current_shelf.push(current_crate);
                // shelves.set_element_at(index, current_shelf);
            } else {
                main_sorting_function(index + 1);
            }
        }

        if (shelves.is_empty()) {
            shelves.add(current_shelf);
        }

        if (!this->sorting_floor.empty() || !arrival_queue->is_empty()) {
            main_sorting_function(index);
        }
    }
};
