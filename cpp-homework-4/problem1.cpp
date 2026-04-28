#include <iostream>
#include <cstring>
#include <stdexcept>

class SimpleString {
private:
    char* data_;
    std::size_t size_;

public:
    // Constructor from const char*
    SimpleString(const char* str = "") {
        size_ = std::strlen(str);
        data_ = new char[size_ + 1];
        std::strcpy(data_, str);
    }

    // Copy constructor
    SimpleString(const SimpleString& other) {
        size_ = other.size_;
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
    }

    // Copy-assignment operator
    SimpleString& operator=(const SimpleString& rhs) {
        if (this != &rhs) {
            char* newData = new char[rhs.size_ + 1];
            std::strcpy(newData, rhs.data_);

            delete[] data_;

            data_ = newData;
            size_ = rhs.size_;
        }

        return *this;
    }

    // Destructor
    ~SimpleString() {
        delete[] data_;
    }

    // size function
    std::size_t size() const {
        return size_;
    }

    // Non-const [] operator
    char& operator[](std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // Const [] operator
    const char& operator[](std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // Equality operator
    bool operator==(const SimpleString& rhs) const {
        return std::strcmp(data_, rhs.data_) == 0;
    }

    // Inequality operator
    bool operator!=(const SimpleString& rhs) const {
        return !(*this == rhs);
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const SimpleString& str) {
        os << str.data_;
        return os;
    }
};

int main() {
    SimpleString s1("Hello");
    SimpleString s2 = s1;      // copy constructor
    SimpleString s3("World");

    s3 = s1;                   // copy assignment

    std::cout << "Original s1: " << s1 << '\n';
    std::cout << "Copied s2:   " << s2 << '\n';
    std::cout << "Assigned s3: " << s3 << '\n';

    s2[0] = 'Y';

    std::cout << "\nAfter modifying s2:\n";
    std::cout << "s1: " << s1 << '\n';
    std::cout << "s2: " << s2 << '\n';

    if (s1 != s2) {
        std::cout << "\ns1 and s2 are different.\n";
    }

    std::cout << "Size of s1: " << s1.size() << '\n';

    return 0;
}