#include <iostream>

class Crate {
    private:
        int weight;
        std::string uuid;
    
    public:
        Crate() {
            weight = 0;
            uuid = "";
        }
        
        Crate(int weight, std::string uuid) {
            this->weight = weight;
            this->uuid = uuid;
        }
        
        int getWeight() const {
            return weight;
        }
        
        std::string getUuid() const {
            return uuid;
        }
        
        void setWeight(int weight) {
            this->weight  = weight;
        }

        void setUuid(std::string uuid) {
            this->uuid = uuid;
        }
};