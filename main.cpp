#include "base_structures/queue.hpp"
#include "structures/warehouse.cpp"
#include <fstream>
#include <iostream>
#include <string>

/*
 * MADE BY:
 * - TOMA BOUROV 200274715
 * - HAYK MATEVOSYAN 200293223
*/

int main() {

    // Create warehouse
    Warehouse *wh = new Warehouse();

    // Read crates from file and add to arrival queue
    wh->read_crates(FILENAME);

    // Cleanup
    delete wh;

    return 0;
}
