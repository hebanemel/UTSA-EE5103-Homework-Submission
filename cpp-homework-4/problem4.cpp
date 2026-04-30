#include <iostream>
#include <vector>
#include <algorithm>

class SmartBuffer {
private:
    int* data_;
    std::size_t size_;

public:
    SmartBuffer(std::size_t size = 0)
        : data_(size > 0 ? new int[size]{} : nullptr), size_(size) {
        std::cout << "Constructor called\n";
    }

    // Copy constructor
    SmartBuffer(const SmartBuffer& other)
        : data_(other.size_ > 0 ? new int[other.size_] : nullptr),
          size_(other.size_) {
        std::copy(other.data_, other.data_ + size_, data_);
        std::cout << "Copy constructor called\n";
    }

    // Copy assignment
    SmartBuffer& operator=(const SmartBuffer& rhs) {
        std::cout << "Copy assignment called\n";

        if (this != &rhs) {
            int* newData = rhs.size_ > 0 ? new int[rhs.size_] : nullptr;
            std::copy(rhs.data_, rhs.data_ + rhs.size_, newData);

            delete[] data_;

            data_ = newData;
            size_ = rhs.size_;
        }

        return *this;
    }

    // Move constructor
    SmartBuffer(SmartBuffer&& other) noexcept
        : data_(other.data_), size_(other.size_) {
        other.data_ = nullptr;
        other.size_ = 0;

        std::cout << "Move constructor called\n";
    }

    // Move assignment
    SmartBuffer& operator=(SmartBuffer&& rhs) noexcept {
        std::cout << "Move assignment called\n";

        if (this != &rhs) {
            delete[] data_;

            data_ = rhs.data_;
            size_ = rhs.size_;

            rhs.data_ = nullptr;
            rhs.size_ = 0;
        }

        return *this;
    }

    // Destructor
    ~SmartBuffer() {
        delete[] data_;
        std::cout << "Destructor called\n";
    }

    std::size_t size() const {
        return size_;
    }
};

SmartBuffer createBuffer() {
    SmartBuffer temp(100);
    return temp;   // may move, or compiler may apply copy elision
}

int main() {
    std::cout << "Returning SmartBuffer by value:\n";
    SmartBuffer a = createBuffer();

    std::cout << "\nCopy example:\n";
    SmartBuffer b = a;

    std::cout << "\nMove example:\n";
    SmartBuffer c = std::move(a);

    std::cout << "\nVector example:\n";
    std::vector<SmartBuffer> buffers;

    buffers.reserve(2);

    buffers.push_back(SmartBuffer(10));
    buffers.push_back(SmartBuffer(20));

    std::cout << "\nAdding third buffer may cause reallocation:\n";
    buffers.push_back(SmartBuffer(30));

    return 0;
}