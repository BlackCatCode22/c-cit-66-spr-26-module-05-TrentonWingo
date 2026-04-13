#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <chrono>
#include <iomanip>

struct Animal {
    std::string id, name, birthDate, color, sex, weight, origin, arrivalDate;
};

// Global map to track species counts for genUniqueID()
std::map<std::string, int> speciesCounts;

std::string genUniqueID(std::string species) {
    std::string prefix = species.substr(0, 2);
    prefix[0] = toupper(prefix[0]);
    prefix[1] = tolower(prefix[1]);

    speciesCounts[prefix]++;
    std::stringstream ss;
    ss << prefix << std::setfill('0') << std::setw(2) << speciesCounts[prefix];
    return ss.str();
}