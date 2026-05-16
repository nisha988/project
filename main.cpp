#include <iostream>
#include <string>
#include <limits>
#include "Library.h"
#include "Member.h"
#include "Admin.h"

// ─────────────────────────────────────────────
//  Utility: read a clean line (no leftover \n)
// ─────────────────────────────────────────────
static std::string readLine(const std::string& prompt) {
    std::cout << "  " << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

static int readInt(const std::string& prompt) {
    int n;
    while (true) {
        std::cout << "  " << prompt;
        if (std::cin >> n) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return n;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Invalid input, try again.\n";
    }
}

// ─────────────────────────────────────────────
//  Member Menu
// ─────────────────────────────────────────────
void memberMenu(Library& lib, Member* member) {
    while (true) {
        std::cout << "\n╔══════════════════════════════╗\n"
                  << "║  MEMBER MENU — " << member->getName() << "\n"
                  << "║  1. View Catalog\n"
                  << "║  2. Borrow Item\n"
                  << "║  3. Return Item\n"
                  << "║  4. My Borrowed Items\n"
                  << "║  0. Logout\n"
                  << "╚══════════════════════════════╝\n";

        int choice = readInt("Choice: ");
        switch (choice) {
            case 1:
                lib.viewCatalog();
                break;
            case 2: {
                lib.viewCatalog();
                std::string itemID = readLine("Enter Item ID to borrow: ");
                lib.borrowItem(member->getID(), itemID);
                break;
            }
            case 3: {
                lib.viewMemberBorrows(member->getID());
                std::string itemID = readLine("Enter Item ID to return: ");
                lib.returnItem(member->getID(), itemID);
                break;
            }
            case 4:
                lib.viewMemberBorrows(member->getID());
                break;
            case 0:
                std::cout << "  Logged out.\n";
                return;
            default:
                std::cout << "  Invalid option.\n";
        }
    }
}

// ─────────────────────────────────────────────
//  Admin Menu
// ─────────────────────────────────────────────
void adminMenu(Library& lib, Admin* admin) {
    while (true) {
        std::cout << "\n╔══════════════════════════════╗\n"
                  << "║  ADMIN MENU — " << admin->getName() << "\n"
                  << "║  CATALOG\n"
                  << "║    1. View Catalog\n"
                  << "║    2. Add Book\n"
                  << "║    3. Add Magazine\n"
                  << "║    4. Add DVD\n"
                  << "║    5. Remove Item\n"
                  << "║  MEMBERS\n"
                  << "║    6. View All Members\n"
                  << "║    7. Register Member\n"
                  << "║    8. Remove Member\n"
                  << "║  RECORDS\n"
                  << "║    9. View All Borrow Records\n"
                  << "║  0. Logout\n"
                  << "╚══════════════════════════════╝\n";

        int choice = readInt("Choice: ");
        switch (choice) {

            case 1: lib.viewCatalog(); break;

            case 2: {
                std::string id     = readLine("Book ID:     ");
                std::string title  = readLine("Title:       ");
                std::string author = readLine("Author:      ");
                std::string isbn   = readLine("ISBN:        ");
                std::string genre  = readLine("Genre:       ");
                lib.addBook(id, title, author, isbn, genre);
                break;
            }
            case 3: {
                std::string id        = readLine("Magazine ID:  ");
                std::string title     = readLine("Title:        ");
                std::string publisher = readLine("Publisher:    ");
                std::string issueDate = readLine("Issue Date:   ");
                std::string category  = readLine("Category:     ");
                lib.addMagazine(id, title, publisher, issueDate, category);
                break;
            }
            case 4: {
                std::string id       = readLine("DVD ID:      ");
                std::string title    = readLine("Title:       ");
                std::string director = readLine("Director:    ");
                int         duration = readInt ("Duration (min): ");
                std::string genre    = readLine("Genre:       ");
                lib.addDVD(id, title, director, duration, genre);
                break;
            }
            case 5: {
                lib.viewCatalog();
                std::string id = readLine("Item ID to remove: ");
                lib.removeItem(id);
                break;
            }
            case 6: lib.viewAllMembers(); break;

            case 7: {
                std::string id    = readLine("Member ID:  ");
                std::string name  = readLine("Name:       ");
                std::string email = readLine("Email:      ");
                std::string pw    = readLine("Password:   ");
                lib.registerMember(id, name, email, pw);
                break;
            }
            case 8: {
                lib.viewAllMembers();
                std::string id = readLine("Member ID to remove: ");
                lib.removeMember(id);
                break;
            }
            case 9: lib.viewAllRecords(); break;

            case 0:
                std::cout << "  Logged out.\n";
                return;
            default:
                std::cout << "  Invalid option.\n";
        }
    }
}

// ─────────────────────────────────────────────
//  Main
// ─────────────────────────────────────────────
int main() {
    Library lib;
    lib.loadAll();
    lib.seedData();   // seeds only if files were empty

    std::cout << "\n╔══════════════════════════════════╗\n"
              << "║   LIBRARY BORROWING SYSTEM       ║\n"
              << "╚══════════════════════════════════╝\n";

    while (true) {
        std::cout << "\n  1. Login as Member\n"
                  << "  2. Login as Admin\n"
                  << "  0. Exit\n";
        int choice = readInt("Choice: ");

        if (choice == 0) {
            std::cout << "  Goodbye!\n";
            break;
        }

        std::string email = readLine("Email:    ");
        std::string pw    = readLine("Password: ");

        if (choice == 1) {
            Member* m = lib.loginMember(email, pw);
            if (m) memberMenu(lib, m);
            else   std::cout << "  [ERROR] Invalid credentials.\n";
        }
        else if (choice == 2) {
            Admin* a = lib.loginAdmin(email, pw);
            if (a) adminMenu(lib, a);
            else   std::cout << "  [ERROR] Invalid credentials.\n";
        }
    }
    return 0;
}
