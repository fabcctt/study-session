#include <iostream>
#include <iomanip>

#include "inventory.hpp"

int main() {
    catalog::Inventory inventory;

    const catalog::Product products[] = {
        {"Keyboard", 35.50, 4},
        {"Mouse", 18.25, 6},
        {"Monitor", 170.00, 2}
    };

    for (const catalog::Product &product : products) {
        if (!inventory.add_product(product)) {
            std::cerr << "Error adding product.\n";
            return 1;
        }
    }

    inventory.print_all();

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nTotal inventory value: $"
              << inventory.total_value() << '\n';

    const catalog::Product *found =
        inventory.find_product("Mouse");

    if (found != nullptr) {
        std::cout << "\nProduct found: "
                  << found->name << '\n';

        std::cout << "Available stock: "
                  << found->stock << '\n';
    } else {
        std::cout << "Product not found.\n";
    }

    return 0;
}
