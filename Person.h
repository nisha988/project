#pragma once
#include <string>

// ─────────────────────────────────────────────
//  Abstract base class for all system users
// ─────────────────────────────────────────────
class Person {
protected:
    std::string personID;
    std::string name;
    std::string email;
    std::string password;

public:
    Person(const std::string& id,
           const std::string& name,
           const std::string& email,
           const std::string& password);

    virtual ~Person() = default;

    std::string getID()       const { return personID; }
    std::string getName()     const { return name;     }
    std::string getEmail()    const { return email;    }

    bool checkPassword(const std::string& pw) const { return password == pw; }

    virtual std::string getRole()      const = 0;
    virtual std::string toFileString() const = 0;
};
