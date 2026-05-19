#pragma once
#include "Item.h"
#include <string>

class Magazine : public Item {
private:
    std::string publisher;
    std::string issueDate;
    std::string category;

public:
    Magazine(const std::string& id,
             const std::string& title,
             const std::string& publisher,
             const std::string& issueDate,
             const std::string& category,
             bool available = true);

    std::string getPublisher() const { return publisher; }
    std::string getIssueDate() const { return issueDate; }
    std::string getCategory()  const { return category;  }

    std::string getType()      const override { return "Magazine"; }
    void        displayInfo()  const override;
    std::string toFileString() const override;

    static Magazine* fromFileString(const std::string& line);
};