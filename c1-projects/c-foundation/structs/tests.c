#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "structs.h"

static void test_student_init(void) {
    Student student = {0};

    assert(student_init(&student, 1, "Alex", 85));

    assert(student.id == 1);
    assert(strcmp(student.name, "Alex") == 0);
    assert(student.grade == 85);

    assert(!student_init(NULL, 1, "Alex", 85));
    assert(!student_init(&student, 0, "Alex", 85));
    assert(!student_init(&student, 2, "", 85));
    assert(!student_init(&student, 2, NULL, 85));
    assert(!student_init(&student, 2, "Alex", 101));
    assert(!student_init(&student, 2, "Alex", -1));
}

static void test_grade_update(void) {
    Student student;

    assert(student_init(&student, 1, "Alex", 80));

    assert(student_set_grade(&student, 95));
    assert(student.grade == 95);

    assert(!student_set_grade(&student, 150));
    assert(student.grade == 95);

    assert(!student_set_grade(NULL, 50));
}

static void test_group(void) {
    StudentGroup group = {0};

    Student first;
    Student second;

    assert(student_init(&first, 1, "Alex", 80));
    assert(student_init(&second, 2, "Maria", 90));

    assert(group_add(&group, &first));
    assert(group_add(&group, &second));

    assert(group.count == 2);

    assert(!group_add(&group, &first));

    Student *found = group_find(&group, 2);

    assert(found != NULL);
    assert(strcmp(found->name, "Maria") == 0);

    assert(group_find(&group, 99) == NULL);

    assert(group_average(&group) == 85.0);
}

static void test_empty_group(void) {
    StudentGroup group = {0};

    assert(group.count == 0);
    assert(group_average(&group) == 0.0);
    assert(group_find(&group, 1) == NULL);
}

static void test_group_capacity(void) {
    StudentGroup group = {0};

    for (int i = 1; i <= MAX_STUDENTS; i++) {
        Student student;

        assert(student_init(&student, i, "Student", 70));
        assert(group_add(&group, &student));
    }

    assert(group.count == MAX_STUDENTS);

    Student extra;

    assert(student_init(&extra, 99, "Extra", 80));
    assert(!group_add(&group, &extra));
}

int main(void) {
    test_student_init();
    test_grade_update();
    test_group();
    test_empty_group();
    test_group_capacity();

    puts("All struct tests passed.");

    return 0;
}
