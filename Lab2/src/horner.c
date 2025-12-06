#include <stdio.h>
#include <stdlib.h>

#define DOUBLE_PRINT(f, str, ...) fprintf(f, str, __VA_ARGS__); printf(str, __VA_ARGS__)


int main(int argc, char* argv[]) {
    printf("Source file running program: %s\n", __FILE__);
    // input handling
    double poly[5];
    double x;
    if (argc >= 6) {
        x = atof(argv[6]);
        for (char i = 1; i <= 5; i++) {
            poly[i-1] = atof(argv[i]);
        }
    } else {
        printf("Please provide 5 numbers for the polynomial and one for the x:\n\t");
        for (int i = 0; i <= 4; i++)
            scanf("%lf", &poly[i]);
        scanf("%lf", &x);
    }

    // file handling
    FILE* out = fopen("results/poly.txt", "a");
    if (!out) { puts("File could not be opened!"); return 1; }
    DOUBLE_PRINT(out, "%g*(%g)^4 %+g*(%g)^3 %+g*(%g)^2 %+g*%g %+g\t=", poly[0], x, poly[1], x, poly[2], x, poly[3], x, poly[4]);

    // func
    double result = *poly;
    for (int i = 1; i < 5; i++) {
        result = result*x + poly[i];
    }
    DOUBLE_PRINT(out, " %f\n\n", result);

    fclose(out);
}
