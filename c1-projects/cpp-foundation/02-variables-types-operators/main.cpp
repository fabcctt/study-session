#include <iostream>
#include <iomanip>

#include "duration.hpp"

int main() {
    int total_seconds = 0;

    std::cout << "Enter duration in seconds: ";

    if (!(std::cin >> total_seconds) || total_seconds < 0) {
        std::cerr << "Invalid duration.\n";
        return 1;
    }

    const int hours = duration::get_hours(total_seconds);
    const int minutes = duration::get_minutes(total_seconds);
    const int seconds = duration::get_seconds(total_seconds);

    const double decimal_minutes =
        duration::to_minutes(total_seconds);

    const bool long_duration =
        duration::is_long_duration(total_seconds);

    const char category = long_duration ? 'L' : 'S';

    std::cout << "\nDuration information:\n";

    std::cout << "Hours: " << hours << '\n';
    std::cout << "Minutes: " << minutes << '\n';
    std::cout << "Seconds: " << seconds << '\n';

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total minutes: "
              << decimal_minutes << '\n';

    std::cout << std::boolalpha;
    std::cout << "At least one hour: "
              << long_duration << '\n';

    std::cout << "Category: " << category << '\n';

    return 0;
}
