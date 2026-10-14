#include "inventory.hpp"

#include <iostream>
#include <iomanip>

namespace catalog {

bool Inventory::add_product(const Product &product) {
    if (product.name.empty() ||
        product.price < 0 ||
        product.stock < 0 ||
        count_ >= MAX_PRODUCTS) {
        return false;
    }

    if (find_product(product.name) != nullptr)
        return false;

    products_[count_] = product;
    count_++;

    return true;
}

const Product *Inventory::find_product(
    const std::string &name
) const {
    for (std::size_t i = 0; i < count_; i++) {
        if (products_[i].name == name)
            return &products_[i];
    }

    return nullptr;
}

double Inventory::total_value() const {
    double total = 0.0;

    for (std::size_t i = 0; i < count_; i++) {
        total += products_[i].price * products_[i].stock;
    }

    return total;
}

void Inventory::print_all() const {
    std::cout << "\n=== Inventory ===\n";

    std::cout << std::fixed << std::setprecision(2);

    for (std::size_t i = 0; i < count_; i++) {
        const Product &product = products_[i];

        std::cout << "\nProduct: " << product.name << '\n';
        std::cout << "Price: $" << product.price << '\n';
        std::cout << "Stock: " << product.stock << '\n';
    }

    std::cout << "\nTotal products: " << count_ << '\n';
}

}