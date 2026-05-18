#pragma once
#include <string>
#include <iostream>


class Item {
protected:
    std::string itemID;
    std::string title;
    int         borrowDays;   // max loan period
    bool        available;

public:
    Item(const std::string& id,
         const std::string& title,
         int borrowDays,
         bool available = true);

    virtual ~Item() = default;

    // Getters
    std::string getID()        const { return itemID;     }
    std::string getTitle()     const { return title;      }
    bool        isAvailable()  const { return available;  }
    int         getBorrowDays()const { return borrowDays; }

    // Setter
    void setAvailable(bool avail) { available = avail; }

    // Pure virtual – each subclass must implement
    virtual std::string getType()       const = 0;
    virtual void        displayInfo()   const = 0;
    virtual std::string toFileString()  const = 0;   // for persistence
};
