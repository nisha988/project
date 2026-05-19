#include "DVD.h"
#include <sstream>
#include <vector>
#include <iostream>

DVD::DVD(const std::string& id,
         const std::string& title,
         const std::string& director,
         int durationMin,
         const std::string& genre,
         bool available)
    : Item(id, title, 3, available),   // DVDs: 3-day loan
      director(director), durationMin(durationMin), genre(genre) {}

void DVD::displayInfo() const {
    std::cout << "[DVD]  ID: "       << itemID
              << "  Title: "         << title
              << "  Director: "      << director
              << "  Duration: "      << durationMin << " min"
              << "  Genre: "         << genre
              << "  Available: "     << (available ? "Yes" : "No")
              << "\n";
}

// Format: DVD|ID|TITLE|DIRECTOR|DURATION|GENRE|AVAILABLE
std::string DVD::toFileString() const {
    return "DVD|" + itemID + "|" + title + "|" +
           director + "|" + std::to_string(durationMin) + "|" +
           genre + "|" + (available ? "1" : "0");
}

DVD* DVD::fromFileString(const std::string& line) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, '|'))
        parts.push_back(token);

    if (parts.size() < 7) return nullptr;
    return new DVD(parts[1], parts[2], parts[3],
                   std::stoi(parts[4]), parts[5], parts[6] == "1");
}
