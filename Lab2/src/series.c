#include <stdio.h>
#include <stdlib.h>
#include <math.h> // don't forget to link the math library with -lm parameter

int main(int argc, char* argv[]) {
    printf("Source file running program: %s\n", __FILE__);
    // input handling
    int in;
    if (argc <= 1) {
        printf("Please provide an integer:\n\t");
        scanf("%d", &in);
    } else {
        in = atoi(argv[1]);
    }

    // file handling
    FILE* out = fopen("results/series.txt", "w");
    if (!out) { puts("File could not be opened!"); return 1; }

    // func
    double tot = 0;
    for (int i = 0; i <= in; i++) {
        tot += pow(M_E, i);
        fprintf(out, "%.6f\n", tot);
    }


    fclose(out);
}