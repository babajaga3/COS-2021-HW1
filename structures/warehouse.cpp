#include "../linkedlist/index.cpp"
#include "./shelf.cpp"
#include <queue>
#include <vector>

class Warehouse {
private:
  LinkedList<Shelf> shelves;
  std::queue<InputCrate> queue;
  std::vector<Crate> sortingFloor;

public:
  void setQueue(std::queue<InputCrate> queue) { this->queue = queue; }

  std::queue<InputCrate> getQueue() const { return queue; }

  void sort() {
    Shelf shelf;

    while (!queue.empty()) {
      InputCrate ic = queue.front();
      Crate crate = Crate(ic.weight, ic.uuid);

      if (!shelf.isFull(crate)) {
        shelf.push(crate);
        std::cout << "added a new crate - " << crate.getWeight() << std::endl;
      } else {
        shelves.add(shelf);
        std::cout << "shelf added to linked list - " << (shelf.isFull(crate) ? "True" : "False") << std::endl;
        shelf.print();
        
        shelf = Shelf();
        shelf.print();
        shelf.push(crate);
        std::cout << "added a new crate - " << crate.getWeight() << std::endl;
      }

      queue.pop();
    }
    
    shelves.add(shelf);
  }

  void paintShelves() {
    // std::vector<Shelf*> items = shelves.listItems();

    // shelves.getHead()->print();
  }
};
