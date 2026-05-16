#include "FileManager.h"
#include "Book.h"
#include "Magazine.h"
#include "DVD.h"
#include <fstream>
#include <iostream>

const std::string FileManager::CATALOG_FILE = "data/catalog.txt";
const std::string FileManager::MEMBERS_FILE = "data/members.txt";
const std::string FileManager::ADMINS_FILE  = "data/admins.txt";
const std::string FileManager::RECORDS_FILE = "data/records.txt";

// ── SAVE ────────────────────────────────────

void FileManager::saveCatalog(const std::vector<Item*>& items) {
    std::ofstream f(CATALOG_FILE);
    for (auto* item : items)
        f << item->toFileString() << "\n";
}

void FileManager::saveMembers(const std::vector<Member*>& members) {
    std::ofstream f(MEMBERS_FILE);
    for (auto* m : members)
        f << m->toFileString() << "\n";
}

void FileManager::saveAdmins(const std::vector<Admin*>& admins) {
    std::ofstream f(ADMINS_FILE);
    for (auto* a : admins)
        f << a->toFileString() << "\n";
}

void FileManager::saveRecords(const std::vector<BorrowRecord*>& records) {
    std::ofstream f(RECORDS_FILE);
    for (auto* r : records)
        f << r->toFileString() << "\n";
}

// ── LOAD ────────────────────────────────────

std::vector<Item*> FileManager::loadCatalog() {
    std::vector<Item*> items;
    std::ifstream f(CATALOG_FILE);
    if (!f.is_open()) return items;

    std::string line;
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        if      (line.rfind("Book",     0) == 0) { auto* x = Book::fromFileString(line);     if (x) items.push_back(x); }
        else if (line.rfind("Magazine", 0) == 0) { auto* x = Magazine::fromFileString(line); if (x) items.push_back(x); }
        else if (line.rfind("DVD",      0) == 0) { auto* x = DVD::fromFileString(line);      if (x) items.push_back(x); }
    }
    return items;
}

std::vector<Member*> FileManager::loadMembers() {
    std::vector<Member*> members;
    std::ifstream f(MEMBERS_FILE);
    if (!f.is_open()) return members;

    std::string line;
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        auto* m = Member::fromFileString(line);
        if (m) members.push_back(m);
    }
    return members;
}

std::vector<Admin*> FileManager::loadAdmins() {
    std::vector<Admin*> admins;
    std::ifstream f(ADMINS_FILE);
    if (!f.is_open()) return admins;

    std::string line;
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        auto* a = Admin::fromFileString(line);
        if (a) admins.push_back(a);
    }
    return admins;
}

std::vector<BorrowRecord*> FileManager::loadRecords() {
    std::vector<BorrowRecord*> records;
    std::ifstream f(RECORDS_FILE);
    if (!f.is_open()) return records;

    std::string line;
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        auto* r = BorrowRecord::fromFileString(line);
        if (r) records.push_back(r);
    }
    return records;
}
