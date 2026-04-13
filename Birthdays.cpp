std::string genBirthDay(int age, std::string season) {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm* parts = std::localtime(&now_c);
    int birthYear = (1900 + parts->tm_year) - age;

    std::string monthDay = "01-01"; // Default
    if (season.find("spring") != std::string::npos) monthDay = "03-21";
    else if (season.find("summer") != std::string::npos) monthDay = "06-21";
    else if (season.find("fall") != std::string::npos) monthDay = "09-21";
    else if (season.find("winter") != std::string::npos) monthDay = "12-21";

    return std::to_string(birthYear) + "-" + monthDay;
}