#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_AMNT 5

typedef struct Student {
    int id;
    char name[32];
    double grade;
} Student;

Student createStudent(const char* name, double grade);


int outputStudents(const char* outPath);
int processStudents(const char* inPath, double progOceny);

int main(int argc, char* argv[]) {
    if (argc <= 1) { perror("Retry with a prog oceny!"); return 1; }

    double progOceny;
    sscanf(argv[1], "%lf", &progOceny);

    if (outputStudents("data/students.bin")) return 1;
    if (processStudents("data/students.bin", progOceny)) return 1;
}

Student createStudent(const char* name, double grade) { // chyba nie trzeba używać move schemantics
    static int nextId = 0;
    Student student = {nextId++, "a", grade};
    strncpy(student.name, name, 32);
    return student;
}

int outputStudents(const char* outPath) {
    FILE* out = fopen("data/students.bin", "wb");
    if (!out) { perror("Couldn't open the output file!"); return 1; }

    Student students[STUDENT_AMNT] = {
        createStudent("Hozier", 3),
        createStudent("Kenshi Yonezu", 4),
        createStudent("Chapelle Roan", 4.5),
        createStudent("Paris Paloma", 5),
        createStudent("Kenny Chesney", 2)
    };

    fwrite(students, sizeof(Student), STUDENT_AMNT, out);
    
    fclose(out);
    return 0;
}

int processStudents(const char* inPath, double progOceny) {
    FILE* in = fopen("data/students.bin", "rb");
    if (!in) { perror("Couldn't open the input file!"); return 1; }

    Student students[STUDENT_AMNT];
    Student* failedStudents[STUDENT_AMNT] = {NULL, NULL, NULL, NULL, NULL};

    fread(students, sizeof(Student), STUDENT_AMNT, in);

    for (Student* student = students; student < students+STUDENT_AMNT; student++) {
        printf("%3i\t%-31s\t%3.1lf\n", student->id, student->name, student->grade);

        if (student->grade < progOceny) {
            failedStudents[student->id] = student;
        }
    }

    {
        printf("\nFailed students:\n");
        for (Student** studentPtr = failedStudents; studentPtr < (failedStudents)+STUDENT_AMNT; studentPtr++) {
            if (*studentPtr) {
                #ifdef RODO
                    printf("\t%i\n", (*studentPtr)->id);
                #else
                    printf("\t%s\n", (*studentPtr)->name);
                #endif
            }
        }
    }

    fclose(in);
    return 0;
}