#include "structures/warehouse.cpp"
#include <fstream>
#include <iostream>
#include <queue>

int main() {
  Warehouse *wh = new Warehouse();

  std::string line;
  std::ifstream crateFile("crates.txt");

  std::queue<InputCrate> queue;

  if (crateFile.is_open()) {
    while (getline(crateFile, line, '\n')) {
      std::string delimiter = " ";
      std::string weight = line.substr(0, line.find(delimiter));

      // Source - https://stackoverflow.com/a/14266139
      // Posted by Vincenzo Pii, modified by community. See post 'Timeline' for
      // change history Retrieved 2026-02-10, License - CC BY-SA 4.0
      line.erase(0, line.find(delimiter) + delimiter.length());

      std::string uuid = line.substr(0, line.find(delimiter));

      InputCrate ic = {std::stoi(weight), uuid};

      queue.push(ic);
    };
    
    wh->setQueue(queue);

    crateFile.close();
  }

  else
    std::cout << "Unable to open file";
  
  wh->sort();
  
  wh->paintShelves();
  

  delete wh;
  
  return 0;
}
