#include <string>
#include "../config.hpp"

class Crate {
    int weight;
    std::string uuid;

public:
    Crate() {
        uuid = "";
        weight = 0;
    }

    Crate(int weight, std::string uuid) {
        this->weight = weight;
        this->uuid = uuid;
    }

    int get_weight() const {
        return weight;
    }

    std::string get_uuid() const {
        return uuid;
    }

    void set_weight(int weight) {
        this->weight = weight;
    }

    void set_uuid(std::string uuid) {
        this->uuid = uuid;
    }

    static Crate convert_to_crate(InputCrate ic) {
        return {ic.weight, ic.uuid};
    }
};
