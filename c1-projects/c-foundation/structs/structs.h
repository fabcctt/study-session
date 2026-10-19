#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_NAME_LENGTH 40
#define MAX_STUDENTS 5

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int grade;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    size_t count;
} StudentGroup;

bool student_init(
    Student *student,
    int id,
    const char *name,
    int grade
);

bool student_set_grade(Student *student, int grade);

bool group_add(StudentGroup *group, const Student *student);

Student *group_find(StudentGroup *group, int id);

double group_average(const StudentGroup *group);

void group_print(const StudentGroup *group);

#endif
