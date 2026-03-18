#pragma once

#include <string>

const int BULK_LIMIT = 4;
const int WEIGHT_LIMIT = 1000;
const int NUMBER_OF_SHELVES = 10;
const std::string FILENAME = "crates.txt";

struct InputCrate {
    int weight;
    std::string uuid;
};
