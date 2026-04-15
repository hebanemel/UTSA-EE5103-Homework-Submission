#include <iostream>
#include <string>

class InventoryItem {
private:
  std::string name_;
  int quantity_{0};
  double unit_price_{0.0};
  static int object_count_; // counts how many objects currently exist

public:
    // Default constructor
    InventoryItem() : name_(""), quantity_(0), unit_price_(0.0)
    {
        object_count_++;
    }

    // Parameterized constructor
    InventoryItem(const std::string& name, int quantity, double price)
        : name_(name),
          quantity_(quantity >= 0 ? quantity : 0),
          unit_price_(price >= 0 ? price : 0.0)
    {
        object_count_++;
    }

    // Destructor
    ~InventoryItem() {
        object_count_;
    }

    // Observers
    const std::string& name() const { return name_; }
    int quantity() const { return quantity_; }
    double price() const { return unit_price_; }

    double totalValue() const {
        return quantity_ * unit_price_;
    }

    // Static observer
    static int objectCount() {
        return object_count_;
    }

    // Mutators
    bool restock(int amount) { // amount > 0
        if (amount <= 0) return false;
        quantity_ += amount;
        return true;
    }

    bool sell(int amount) { // 0 < amount <= quantity_
        if (amount <= 0 || amount > quantity_) return false;
        quantity_ -= amount;
        return true;
    }
};
// Static member definition/initialization to allocate memory
int InventoryItem::object_count_ = 0;


int main() {
    std::cout << "Initial object count: "
              << InventoryItem::objectCount() << "\n";

    InventoryItem item1("Apples", 10, 1.50);
    InventoryItem item2("Bananas", 5, 0.75);

    std::cout << "Object count after creation: "
              << InventoryItem::objectCount() << "\n";

    // Demonstrate restocking
    item1.restock(5);
    std::cout << item1.name() << " quantity after restock: "
              << item1.quantity() << "\n";

    // Demonstrate selling
    item2.sell(3);
    std::cout << item2.name() << " quantity after selling: "
              << item2.quantity() << "\n";

    // Demonstrate total value
    std::cout << item1.name() << " total value: $"
              << item1.totalValue() << "\n";

    std::cout << "Final object count before program ends: "
              << InventoryItem::objectCount() << "\n";

    return 0;
}
