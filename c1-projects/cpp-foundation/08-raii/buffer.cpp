#include "buffer.hpp"

#include <stdexcept>

namespace resources {

IntBuffer::IntBuffer(std::size_t size)
    : data_(nullptr), size_(size) {

    if (size == 0)
        throw std::invalid_argument("Size must be greater than zero.");

    data_ = new int[size]{};
}

IntBuffer::~IntBuffer() {
    delete[] data_;
}

void IntBuffer::set(std::size_t index, int value) {
    if (index >= size_)
        throw std::out_of_range("Invalid buffer index.");

    data_[index] = value;
}

int IntBuffer::get(std::size_t index) const {
    if (index >= size_)
        throw std::out_of_range("Invalid buffer index.");

    return data_[index];
}

long long IntBuffer::sum() const {
    long long total = 0;

    for (std::size_t i = 0; i < size_; i++) {
        total += data_[i];
    }

    return total;
}

std::size_t IntBuffer::size() const {
    return size_;
}

}
