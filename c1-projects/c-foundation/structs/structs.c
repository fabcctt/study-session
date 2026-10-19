#include "structs.h"

#include <stdio.h>
#include <string.h>

static bool valid_grade(int grade) {
    return grade >= 0 && grade <= 100;
}

bool student_init(
    Student *student,
    int id,
    const char *name,
    int grade
) {
    if (student == NULL || name == NULL)
        return false;

    if (id <= 0 || name[0] == '\0')
        return false;

    if (strlen(name) >= MAX_NAME_LENGTH)
        return false;

    if (!valid_grade(grade))
        return false;

    student->id = id;
    strcpy(student->name, name);
    student->grade = grade;

    return true;
}

bool student_set_grade(Student *student, int grade) {
    if (student == NULL || !valid_grade(grade))
        return false;

    student->grade = grade;

    return true;
}

Student *group_find(StudentGroup *group, int id) {
    if (group == NULL)
        return NULL;

    for (size_t i = 0; i < group->count; i++) {
        if (group->students[i].id == id)
            return &group->students[i];
    }

    return NULL;
}

bool group_add(StudentGroup *group, const Student *student) {
    if (group == NULL || student == NULL)
        return false;

    if (group->count >= MAX_STUDENTS)
        return false;

    if (student->id <= 0 || !valid_grade(student->grade))
        return false;

    if (student->name[0] == '\0')
        return false;

    if (memchr(student->name, '\0', MAX_NAME_LENGTH) == NULL)
        return false;

    if (group_find(group, student->id) != NULL)
        return false;

    group->students[group->count] = *student;
    group->count++;

    return true;
}

double group_average(const StudentGroup *group) {
    if (group == NULL || group->count == 0)
        return 0.0;

    int total = 0;

    for (size_t i = 0; i < group->count; i++) {
        total += group->students[i].grade;
    }

    return (double)total / group->count;
}

void group_print(const StudentGroup *group) {
    if (group == NULL)
        return;

    printf("\n=== Student Records ===\n");

    for (size_t i = 0; i < group->count; i++) {
        const Student *student = &group->students[i];

        printf("\nID: %d\n", student->id);
        printf("Name: %s\n", student->name);
        printf("Grade: %d\n", student->grade);
    }

    printf("\nTotal students: %zu\n", group->count);
}
