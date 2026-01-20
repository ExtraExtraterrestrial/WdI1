#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#include "utils.h"

#define GRADES_AMOUNT 5

#if defined(__GNUC__) || defined(__clang__)
    #define _msize(ptr)     malloc_usable_size(ptr)
#elif defined(_MSC_VER)
    // no need to redefine it
#else
    #pragma message("Unknown compiler. The program likely won't work.")
#endif


int main() {
    // Zad 1-2
    srand(time(NULL));
    double* grades = (double*)malloc(GRADES_AMOUNT * sizeof(double));
    if (!grades) { perror("Couldn't allocate space for grades."); return 1; }

    for (
        double* grade = grades;
        grade < grades+(_msize(grades)/sizeof(*grade));
        grade++
    ) {
        *grade = (rand()%10)-2.5;
    }


    printf("Grades max: %.1lf\nGrades min: %.1lf\nGrades average: %.1lf\n\n\n", getMax(grades, 5), getMin(grades, 5), getAverage(grades, 5));

    for (double* grade = grades; grade < grades+5; grade++) {
        normalizeGrade(&(*grade)); // uzywam operatora &
    }

    printf(
        "Grade stats after normalization:\n"
        "Grades max: %.1lf\n"
        "Grades min: %.1lf\n"
        "Grades average: %.1lf\n\n\n", 
        getMax(grades, 5), getMin(grades, 5), getAverage(grades, 5)
    );

    free(grades);

    // Zad 3
    Student students[] = {
        createStudent("Orla Gartland", 6),
        createStudent("Olivia Rodrigo", 3),
        createStudent("Hikaru Utada", 4.5),
        createStudent("Nicki Minaj", -1),
        createStudent("Aurora", 5),
        createStudent("Dawid Podsiadlo", 2)
    };

    for (
        Student* student = students;
        student < students + sizeof(students)/sizeof(*student);
        student++
    ) {
        printf(
            "---------------------------------------\n"
            "Student before normalization:\n"
        );
        printStudent(*student);
        normalizeStudentsGrade(student);
        printf("Student after normalization:\n");
        printStudent(*student);
    } printf("\n\n");

}
