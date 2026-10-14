#include "duration.hpp"

namespace duration {

int get_hours(int total_seconds) {
    return total_seconds / 3600;
}

int get_minutes(int total_seconds) {
    return (total_seconds % 3600) / 60;
}

int get_seconds(int total_seconds) {
    return total_seconds % 60;
}

double to_minutes(int total_seconds) {
    return static_cast<double>(total_seconds) / 60.0;
}

bool is_long_duration(int total_seconds) {
    return total_seconds >= 3600;
}

}
