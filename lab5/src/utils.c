#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <string.h>

/********
* ZAD 3 *
********/
Student createStudent(const char* name, double grade) {
    static int nextId = 0;
    Student student = {nextId++, "a", grade};
    strncpy(student.name, name, 32);
    return student;
}

void printStudent(Student student) {
    printf("%i.\t%-32s\t%.1lf\n", student.id, student.name, student.grade);
}

void normalizeStudentsGrade(Student *student) {
    normalizeGrade(&student->grade);
}

/********
* ZAD 1 *
*********/

double getMin(double* grades, size_t size) {
    double min = DBL_MAX;

    for (double* grade = grades; grade < grades+size; grade++) {
        if (*grade < min)
            min = *grade;
    }

    return min;
}

double getMax(double* grades, size_t size) {
    double max = DBL_MIN;

    for (double* grade = grades; grade < grades+size; grade++) {
        if (*grade > max)
            max = *grade;
    }

    return max;
}

double getAverage(double* grades, size_t size) {
    double sum = 0;

    for (double* grade = grades; grade < grades+size; grade++) {
        sum += *grade;
    }

    return sum/size;
}



/********
* ZAD 2 *
*********/

void normalizeGrade(double* grade) {
    *grade = *grade > 5. ? (5.) : (*grade < 3. ? 3. : *grade);
}
