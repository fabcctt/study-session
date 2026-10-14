#include <iostream>
#include <exception>

#include "buffer.hpp"

int main() {
    std::cout << "=== RAII Buffer Manager ===\n";

    try {
        {
            resources::IntBuffer buffer(5);

            for (std::size_t i = 0; i < buffer.size(); i++) {
                buffer.set(i, static_cast<int>((i + 1) * 10));
            }

            std::cout << "\nBuffer values: ";

            for (std::size_t i = 0; i < buffer.size(); i++) {
                std::cout << buffer.get(i) << " ";
            }

            std::cout << "\nBuffer size: "
                      << buffer.size() << '\n';

            std::cout << "Sum: "
                      << buffer.sum() << '\n';

            std::cout << "\nLeaving buffer scope...\n";
        }

        std::cout << "Memory released automatically.\n";
    }
    catch (const std::exception &error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
