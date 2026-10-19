#include <stdio.h>

#include "structs.h"

int main(void) {
    StudentGroup group = {0};

    Student first;
    Student second;
    Student third;

    printf("=== Student Records Lab ===\n");

    if (!student_init(&first, 1, "Alex", 85) ||
        !student_init(&second, 2, "Maria", 70) ||
        !student_init(&third, 3, "John", 95)) {
        printf("Error initializing students.\n");
        return 1;
    }

    if (!group_add(&group, &first) ||
        !group_add(&group, &second) ||
        !group_add(&group, &third)) {
        printf("Error adding students.\n");
        return 1;
    }

    printf("\nSearching for student ID 2...\n");

    Student *found = group_find(&group, 2);

    if (found != NULL) {
        printf("Found: %s\n", found->name);

        if (student_set_grade(found, 90)) {
            printf("Grade updated to: %d\n", found->grade);
        }
    }

    group_print(&group);

    printf("\nAverage grade: %.2f\n",
           group_average(&group));

    return 0;
}
