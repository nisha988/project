#pragma once
#include "Item.h"

class Book : public Item {
private:
    std::string author;
    std::string isbn;
    std::string genre;

public:
    Book(const std::string& id,
         const std::string& title,
         const std::string& author,
         const std::string& isbn,
         const std::string& genre,
         bool available = true);

    std::string getAuthor() const { return author; }
    std::string getISBN()   const { return isbn;   }
    std::string getGenre()  const { return genre;  }

    std::string getType()      const override { return "Book"; }
    void        displayInfo()  const override;
    std::string toFileString() const override;

    // Re-hydrate from a pipe-delimited file line
    static Book* fromFileString(const std::string& line);
};
