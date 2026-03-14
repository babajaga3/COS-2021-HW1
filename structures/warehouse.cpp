#include <stdexcept>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "shelf.cpp"
#include "../base_structures/new_linked_list.hpp"
#include "../base_structures/queue.hpp"

class Warehouse {
    // 10 shelves
    LinkedList<Shelf> *shelves;
    // 1 arrival queue
    Queue<InputCrate> *arrival_queue;
    // 1 sorting floor
    std::vector<Crate> sorting_floor;

public:
    Warehouse() {
        shelves = new LinkedList<Shelf>();
        arrival_queue = new Queue<InputCrate>();
    }

    ~Warehouse() {
        delete shelves;
        delete arrival_queue;
    }

    Queue<InputCrate> &get_arrival_queue() const {
        return *arrival_queue;
    }

    void read_crates(const std::string filename) const {
        std::ifstream crate_file(filename);

        if (crate_file.is_open()) {
            std::string line;
            while (getline(crate_file, line, '\n')) {
                std::string delimiter = " ";
                std::string weight = line.substr(0, line.find(delimiter));

                // Source - https://stackoverflow.com/a/14266139
                // Posted by Vincenzo Pii, modified by community. See post 'Timeline' for
                // change history Retrieved 2026-02-10, License - CC BY-SA 4.0
                line.erase(0, line.find(delimiter) + delimiter.length());

                std::string uuid = line.substr(0, line.find(delimiter));
                InputCrate ic = {std::stoi(weight), uuid};

                arrival_queue->enqueue(ic);
            };

            crate_file.close();
        } else {
            std::cout << "Unable to open file";
        }
    }

    void sort() const {
        if (arrival_queue->is_empty()) {
            throw std::logic_error("Cannot sort items in an empty queue.");
        }

        Shelf current_shelf;

        do {
            const InputCrate ic = arrival_queue->dequeue();
            const Crate crate = Crate(ic.weight, ic.uuid);

            for (int i = 0; i <= NUMBER_OF_SHELVES; i++) {
                try {
                    current_shelf.push(crate);
                    std::cout << crate.get_weight() << std::endl;;
                    break;
                } catch (std::range_error &e) {
                    shelves->push_back(current_shelf);
                    current_shelf = Shelf();
                } catch (std::logic_error &e) {
                }
            }
        } while (arrival_queue->is_empty() == false);
        shelves->push_back(current_shelf);
    }

    void print() const {
        std::printf("%-8s%-8s%-8s%-8s%-8s\n", "SHELF01", "SHELF02", "SHELF03", "SHELF04", "SHELF05");

        // Loop for rows
        for (int i = BULK_LIMIT - 1; i >= 0; i--) {
            // Loop for columns
            for (int j = 0; j < 5; j++) {
                Shelf shelf = shelves->get_element_at(j);

                try {
                    const int weight = shelf.get_crate(i).get_weight();

                    std::printf("%-8d", weight);
                } catch (std::out_of_range &e) {
                    std::printf("%-8s", "");
                }
            }

            std::cout << std::endl;
        }

        for (int i = 0; i < 5; i++) {
            std::printf("%-8s", shelves->get_element_at(i).get_total_weight() <= WEIGHT_LIMIT ? "GOOD" : "BAD");
        }

        std::cout << std::endl;
        std::cout << std::endl;

        std::printf("%-8s%-8s%-8s%-8s%-8s\n", "SHELF06", "SHELF07", "SHELF08", "SHELF09", "SHELF10");

        // Loop for rows
        for (int i = BULK_LIMIT - 1; i >= 0; i--) {
            // Loop for columns
            for (int j = 5; j < 10; j++) {
                Shelf shelf = shelves->get_element_at(j);

                try {
                    const int weight = shelf.get_crate(i).get_weight();

                    std::printf("%-8d", weight);
                } catch (std::out_of_range &e) {
                    std::printf("%-8s", "");
                }
            }

            std::cout << std::endl;
        }

        for (int i = 5; i < 10; i++) {
            std::printf("%-8s", shelves->get_element_at(i).get_total_weight() <= WEIGHT_LIMIT ? "GOOD" : "BAD");
        }
    }

        // new sorting algorithm design for hw 2
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

    // void sort_items_in_shelf(Shelf& current_shelf, Crate& current_crate, const int index) {
    //     const Crate last = current_shelf.last();
    //
    //     const int new_total_weight =
    //         current_shelf.get_total_weight() + current_crate.get_weight() - last.get_weight();
    //
    //     if (new_total_weight > current_shelf.get_total_weight() && new_total_weight < WEIGHT_LIMIT) {
    //
    //         while (!current_shelf.can_put_on_top(current_crate)) {
    //             const Crate last_shelf = current_shelf.pop();
    //             this->sorting_floor.push_back(last_shelf);
    //         }
    //
    //         current_shelf.push(current_crate);
    //
    //         shelves.set_element_at(0, current_shelf);
    //
    //         main_sorting_function(index);
    //
    //     } else {
    //         main_sorting_function(index + 1);
    //     }
    // }
    //
    // void main_sorting_function(const int index) {
    //     Shelf current_shelf;
    //     Crate current_crate;
    //
    //     if (!shelves.is_empty()) {
    //         try {
    //             current_shelf = shelves.get_element_at(index).get_data();
    //         } catch (std::out_of_range e) {
    //             const Shelf new_shelf;
    //             shelves.add(new_shelf);
    //
    //             main_sorting_function(index);
    //             return;
    //         }
    //     }
    //
    //     if (this->sorting_floor.empty()) {
    //         try {
    //             const InputCrate ic = arrival_queue->dequeue();
    //             current_crate = Crate(ic.weight, ic.uuid);
    //         } catch (std::length_error e) {
    //             std::cout << "both arrival queue and sorting floor are empty" << std::endl;
    //             this->print();
    //             exit(0);
    //         }
    //     } else {
    //         current_crate = this->sorting_floor.back();
    //         this->sorting_floor.pop_back();
    //     }
    //
    //     if (current_shelf.can_put_on_shelf(current_crate)) {
    //         current_shelf.push(current_crate);
    //         // shelves.set_element_at(index, current_shelf);
    //     } else {
    //         const Crate last = current_shelf.last();
    //
    //         const int new_total_weight =
    //             current_shelf.get_total_weight() + current_crate.get_weight() - last.get_weight();
    //
    //         if (new_total_weight > current_shelf.get_total_weight() && new_total_weight <= WEIGHT_LIMIT) {
    //
    //             while (!current_shelf.can_put_on_top(current_crate)) {
    //                 const Crate last_shelf = current_shelf.pop();
    //                 this->sorting_floor.push_back(last_shelf);
    //             }
    //
    //             current_shelf.push(current_crate);
    //             // shelves.set_element_at(index, current_shelf);
    //         } else {
    //             main_sorting_function(index + 1);
    //         }
    //     }
    //
    //     if (shelves.is_empty()) {
    //         shelves.add(current_shelf);
    //     }
    //
    //     if (!this->sorting_floor.empty() || !arrival_queue->is_empty()) {
    //         main_sorting_function(index);
    //     }
    // }
};
