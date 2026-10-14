#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <cstddef>

namespace resources {

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size);

    ~IntBuffer();

    IntBuffer(const IntBuffer &) = delete;
    IntBuffer &operator=(const IntBuffer &) = delete;

    void set(std::size_t index, int value);

    int get(std::size_t index) const;

    long long sum() const;

    std::size_t size() const;

private:
    int *data_;
    std::size_t size_;
};

}

#endif
