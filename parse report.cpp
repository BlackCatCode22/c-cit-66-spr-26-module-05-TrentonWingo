cpp

void generateReport(std::string inputPath, std::string outputPath) {
    std::ifstream inputFile(inputPath);
    std::ofstream outputFile(outputPath);
    std::map<std::string, std::vector<Animal>> habitats;

    std::string line;
    while (std::getline(inputFile, line)) {
        // Parsing logic here (e.g., using stringstream or find/substr)
        // Example: "4 year old female hyena, born in spring..."

        Animal a;
        std::string species = "Hyena"; // Derived from parsing
        a.id = genUniqueID(species);
        a.birthDate = genBirthDay(4, "spring");
        // ... fill other fields ...

        habitats[species + " Habitat"].push_back(a);
    }

    // Write to zooPopulation.txt
    for (auto const& [habitat, animals] : habitats) {
        outputFile << habitat << ":" << std::endl;
        for (const auto& a : animals) {
            outputFile << "    " << a.id << "; " << a.name << "; birth date "
                       << a.birthDate << "; " << a.color << "; " << a.sex << "; "
                       << a.weight << "; " << a.origin << "; arrived 2024-03-05" << std::endl;
        }
    }
}