#include "queue.hpp"
#include "warehouse.cpp"
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
  Queue<InputCrate> arrival_queue = wh->get_arrival_queue();

  std::ifstream crate_file("crates.txt");

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
      InputCrate ic = { std::stoi(weight), uuid };

      arrival_queue.enqueue(ic);
    };

    crate_file.close();
  }
  else {
    std::cout << "Unable to open file";
  }

  wh->set_arrival_queue(arrival_queue);

  wh->sort();

  wh->print();

  delete wh;
  
  return 0;
}