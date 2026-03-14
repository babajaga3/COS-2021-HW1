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
  Warehouse *wh = new Warehouse();

  wh->read_crates(FILENAME);

  delete wh;
  
  return 0;
}