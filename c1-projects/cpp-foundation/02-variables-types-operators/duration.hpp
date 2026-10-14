#ifndef DURATION_HPP
#define DURATION_HPP

namespace duration {

int get_hours(int total_seconds);
int get_minutes(int total_seconds);
int get_seconds(int total_seconds);

double to_minutes(int total_seconds);

bool is_long_duration(int total_seconds);

}

#endif
