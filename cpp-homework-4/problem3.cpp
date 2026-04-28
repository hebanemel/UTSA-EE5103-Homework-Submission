#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class LibraryItem {
private:
    std::string title_;
    int id_;

public:
    LibraryItem(const std::string& title, int id)
        : title_(title), id_(id) {}

    virtual ~LibraryItem() = default;

    std::string getTitle() const {
        return title_;
    }

    int getId() const {
        return id_;
    }

    virtual double lateFee(int days) const = 0;
    virtual LibraryItem* clone() const = 0;

    virtual void print(std::ostream& os) const {
        os << "Title: " << title_ << ", ID: " << id_;
    }
};

class Book : public LibraryItem {
private:
    double feePerDay_;

public:
    Book(const std::string& title, int id, double feePerDay)
        : LibraryItem(title, id), feePerDay_(feePerDay) {}

    double lateFee(int days) const override {
        return days * feePerDay_;
    }

    Book* clone() const override {
        return new Book(*this);
    }

    void print(std::ostream& os) const override {
        os << "Book: ";
        LibraryItem::print(os);
        os << ", Fee per day: $" << feePerDay_;
    }
};

class DVD : public LibraryItem {
private:
    double feePerDay_;
    double maxFee_;

public:
    DVD(const std::string& title, int id, double feePerDay, double maxFee)
        : LibraryItem(title, id), feePerDay_(feePerDay), maxFee_(maxFee) {}

    double lateFee(int days) const override {
        double fee = days * feePerDay_;
        return std::min(fee, maxFee_);
    }

    DVD* clone() const override {
        return new DVD(*this);
    }

    void print(std::ostream& os) const override {
        os << "DVD: ";
        LibraryItem::print(os);
        os << ", Fee per day: $" << feePerDay_
           << ", Max fee: $" << maxFee_;
    }
};

// Polymorphic output operator
std::ostream& operator<<(std::ostream& os, const LibraryItem& item) {
    item.print(os);   // dynamic binding
    return os;
}

int main() {
    std::vector<LibraryItem*> items;

    items.push_back(new Book("C++ Primer", 101, 0.25));
    items.push_back(new DVD("Inception", 202, 1.50, 10.00));

    // Derived-to-base conversion
    Book book("Clean Code", 303, 0.30);
    LibraryItem* basePtr = &book;

    std::cout << "Derived-to-base conversion:\n";
    std::cout << *basePtr << '\n';
    std::cout << "Late fee for 5 days: $" << basePtr->lateFee(5) << "\n\n";

    std::cout << "Library checkout items:\n";

    for (LibraryItem* item : items) {
        std::cout << *item << '\n';
        std::cout << "Late fee for 7 days: $"
                  << item->lateFee(7) << "\n\n";
    }

    // Demonstrating clone
    LibraryItem* copy = items[0]->clone();
    std::cout << "Cloned item:\n";
    std::cout << *copy << '\n';

    delete copy;

    // Release dynamically allocated memory
    for (LibraryItem* item : items) {
        delete item;
    }

    return 0;
}