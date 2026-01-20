#ifndef __student_h__
#define __student_h__

#include <stddef.h> // minimal required instead of stdlib.h

/********
* ZAD 3 *
********/

typedef struct Student {
    int id;
    char name[32];
    double grade;
} Student;

Student createStudent(const char* name, double grade);

void printStudent(Student student);

void normalizeStudentsGrade(Student *student);


/********
* ZAD 2 *
********/

double getMin(double* grades, size_t size);

double getMax(double* grades, size_t size);

double getAverage(double* grades, size_t size);


/********
* ZAD 3 *
********/

void normalizeGrade(double* grade);


#endif // #ifndef __student_h__
