#include <iostream>
#include <fstream>
#include "node/index.cpp"
#include "consts.hpp"

int main() {
  std::string line;
  std::ifstream myFile("crates.txt");
  
  if (myFile.is_open()) {
    while (getline(myFile, line, '\n')) {
        std::string delimiter = " ";
        std::string weight = line.substr(0, line.find(delimiter));

        // Source - https://stackoverflow.com/a/14266139
        // Posted by Vincenzo Pii, modified by community. See post 'Timeline' for change history
        // Retrieved 2026-02-10, License - CC BY-SA 4.0

        line.erase(0, line.find(delimiter) + delimiter.length());
        std::string uuid = line.substr(0, line.find(delimiter));
        
        std::cout << weight << " " << uuid << std::endl;
    };

    myFile.close();
  }

  else
    std::cout << "Unable to open file";

  return 0;
}
