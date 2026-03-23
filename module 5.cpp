#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    // Example line from arrivingAnimals.txt
    std::string line = "4 year old female hyena, born in spring, tan color, 70 pounds";

    std::stringstream ss(line);
    std::string segment;
    std::vector<std::string> parts;

    // Split by comma
    while (std::getline(ss, segment, ',')) {
        // Simple trim for leading spaces
        if (segment[0] == ' ') segment.erase(0, 1);
        parts.push_back(segment);
    }

    // Quick extraction test
    std::cout << "Age/Species Info: " << parts[0] << std::endl;
    std::cout << "Birth Season: " << parts[1] << std::endl;

    return 0;
}