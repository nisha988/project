#pragma once
#include "Item.h"

class DVD : public Item {
private:
    std::string director;
    int         durationMin;   // runtime in minutes
    std::string genre;

public:
    DVD(const std::string& id,
        const std::string& title,
        const std::string& director,
        int durationMin,
        const std::string& genre,
        bool available = true);

    std::string getDirector()    const { return director;    }
    int         getDuration()    const { return durationMin; }
    std::string getGenre()       const { return genre;       }

    std::string getType()      const override { return "DVD"; }
    void        displayInfo()  const override;
    std::string toFileString() const override;

    static DVD* fromFileString(const std::string& line);
};
