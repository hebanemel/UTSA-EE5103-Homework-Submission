#include <iostream>
#include <stdexcept>

class NumberList {
private:
    int* data_;
    std::size_t size_;

public:
    NumberList(std::size_t size = 0)
        : data_(new int[size]{}), size_(size) {}

    NumberList(const int arr[], std::size_t size)
        : data_(new int[size]), size_(size) {
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = arr[i];
        }
    }

    // Copy constructor
    NumberList(const NumberList& other)
        : data_(new int[other.size_]), size_(other.size_) {
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Copy-assignment operator
    NumberList& operator=(const NumberList& rhs) {
        if (this != &rhs) {
            int* newData = new int[rhs.size_];

            for (std::size_t i = 0; i < rhs.size_; ++i) {
                newData[i] = rhs.data_[i];
            }

            delete[] data_;

            data_ = newData;
            size_ = rhs.size_;
        }

        return *this;
    }

    // Destructor
    ~NumberList() {
        delete[] data_;
    }

    std::size_t size() const {
        return size_;
    }

    // Subscript operators
    int& operator[](std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        return data_[index];
    }

    const int& operator[](std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        return data_[index];
    }

    // += operator
    NumberList& operator+=(const NumberList& rhs) {
        int* newData = new int[size_ + rhs.size_];

        for (std::size_t i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }

        for (std::size_t i = 0; i < rhs.size_; ++i) {
            newData[size_ + i] = rhs.data_[i];
        }

        delete[] data_;

        data_ = newData;
        size_ += rhs.size_;

        return *this;
    }

    // Prefix ++
    NumberList& operator++() {
        for (std::size_t i = 0; i < size_; ++i) {
            ++data_[i];
        }

        return *this;
    }

    // Postfix ++
    NumberList operator++(int) {
        NumberList old = *this;
        ++(*this);
        return old;
    }

    friend NumberList operator+(const NumberList& lhs, const NumberList& rhs);
    friend bool operator==(const NumberList& lhs, const NumberList& rhs);
    friend bool operator<(const NumberList& lhs, const NumberList& rhs);
    friend std::ostream& operator<<(std::ostream& os, const NumberList& list);
};

// + operator
NumberList operator+(const NumberList& lhs, const NumberList& rhs) {
    NumberList result = lhs;
    result += rhs;
    return result;
}

// == operator
bool operator==(const NumberList& lhs, const NumberList& rhs) {
    if (lhs.size_ != rhs.size_) {
        return false;
    }

    for (std::size_t i = 0; i < lhs.size_; ++i) {
        if (lhs.data_[i] != rhs.data_[i]) {
            return false;
        }
    }

    return true;
}

// < operator: lexicographical comparison
bool operator<(const NumberList& lhs, const NumberList& rhs) {
    std::size_t minSize = lhs.size_ < rhs.size_ ? lhs.size_ : rhs.size_;

    for (std::size_t i = 0; i < minSize; ++i) {
        if (lhs.data_[i] < rhs.data_[i]) {
            return true;
        }

        if (lhs.data_[i] > rhs.data_[i]) {
            return false;
        }
    }

    return lhs.size_ < rhs.size_;
}

// << operator
std::ostream& operator<<(std::ostream& os, const NumberList& list) {
    os << "[ ";

    for (std::size_t i = 0; i < list.size_; ++i) {
        os << list.data_[i] << " ";
    }

    os << "]";

    return os;
}

int main() {
    int aData[] = {1, 2, 3};
    int bData[] = {4, 5};
    int cData[] = {6, 7};

    NumberList a(aData, 3);
    NumberList b(bData, 2);
    NumberList c(cData, 2);

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "c: " << c << '\n';

    NumberList d = a + b;
    std::cout << "\na + b: " << d << '\n';

    a += b + c;
    std::cout << "After a += b + c: " << a << '\n';

    ++b;
    std::cout << "\nAfter prefix ++b: " << b << '\n';

    NumberList oldC = c++;
    std::cout << "Old c from postfix c++: " << oldC << '\n';
    std::cout << "New c after postfix c++: " << c << '\n';

    std::cout << "\na[0]: " << a[0] << '\n';
    a[0] = 100;
    std::cout << "After modifying a[0]: " << a << '\n';

    if (b == c) {
        std::cout << "\nb and c are equal.\n";
    } else {
        std::cout << "\nb and c are not equal.\n";
    }

    if (b < c) {
        std::cout << "b is less than c.\n";
    } else {
        std::cout << "b is not less than c.\n";
    }

    return 0;
}