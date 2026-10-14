#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <array>
#include <cstddef>
#include <string>

namespace catalog {

struct Product {
    std::string name;
    double price;
    int stock;
};

class Inventory {
public:
    bool add_product(const Product &product);

    const Product *find_product(
        const std::string &name
    ) const;

    double total_value() const;

    void print_all() const;

private:
    static constexpr std::size_t MAX_PRODUCTS = 5;

    std::array<Product, MAX_PRODUCTS> products_{};
    std::size_t count_ = 0;
};

}

#endif
