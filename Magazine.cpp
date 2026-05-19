#include "Magazine.h"
#include <sstream>
#include <vector>
#include <iostream>

Magazine::Magazine(const std::string& id,
                   const std::string& title,
                   const std::string& publisher,
                   const std::string& issueDate,
                   const std::string& category,
                   bool available)
    : Item(id, title, 7, available),
      publisher(publisher), issueDate(issueDate), category(category) {}

void Magazine::displayInfo() const {
    std::cout << "[MAGAZINE]  ID: "   << itemID
              << "  Title: "          << title
              << "  Publisher: "      << publisher
              << "  Issue: "          << issueDate
              << "  Category: "       << category
              << "  Available: "      << (available ? "Yes" : "No")
              << "\n";
}

std::string Magazine::toFileString() const {
    return "Magazine|" + itemID + "|" + title + "|" +
           publisher + "|" + issueDate + "|" + category + "|" +
           (available ? "1" : "0");
}

Magazine* Magazine::fromFileString(const std::string& line) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, '|'))
        parts.push_back(token);

    if (parts.size() < 7) return nullptr;
    return new Magazine(parts[1], parts[2], parts[3],
                        parts[4], parts[5], parts[6] == "1");
}