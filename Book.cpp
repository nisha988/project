#include "Book.h"
#include <sstream>
#include <vector>

Book::Book(const std::string& id,
           const std::string& title,
           const std::string& author,
           const std::string& isbn,
           const std::string& genre,
           bool available)
    : Item(id, title, 14, available),   // books: 14-day loan
      author(author), isbn(isbn), genre(genre) {}

void Book::displayInfo() const {
    std::cout << "[BOOK]  ID: "     << itemID
              << "  Title: "        << title
              << "  Author: "       << author
              << "  ISBN: "         << isbn
              << "  Genre: "        << genre
              << "  Available: "    << (available ? "Yes" : "No")
              << "\n";
}

// Format: Book|ID|TITLE|AUTHOR|ISBN|GENRE|AVAILABLE
std::string Book::toFileString() const {
    return "Book|" + itemID + "|" + title + "|" +
           author + "|" + isbn + "|" + genre + "|" +
           (available ? "1" : "0");
}

Book* Book::fromFileString(const std::string& line) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, '|'))
        parts.push_back(token);

    // parts: [0]=Book [1]=ID [2]=TITLE [3]=AUTHOR [4]=ISBN [5]=GENRE [6]=AVAIL
    if (parts.size() < 7) return nullptr;
    return new Book(parts[1], parts[2], parts[3],
                    parts[4], parts[5], parts[6] == "1");
}
