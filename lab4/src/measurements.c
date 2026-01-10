#include <stdlib.h>
#include <stdio.h>
#include <float.h>

int inputPomiary(const char* outPath);
int processPomiary(const char* inPath, const char* outPath);

int main(int argc, char* argv[]) {
    if (inputPomiary("data/measurements.txt"))   { return 1; }
    if (processPomiary("data/measurements.txt", "results/measurements_report.txt")) { return 1; }
    
    return 0;
}

int inputPomiary(const char* outPath) {
    FILE* out = fopen(outPath, "w");
    if (!out) { perror("Couldn't open the initial output file!"); return 1; }

    int N;
    printf("Podaj liczbe pomiarow: "); scanf("%d", &N);

    if (N < 1) { perror("Input a positive amount!"); return 1; }

    double* pomiary = (double*)malloc(N*sizeof(double));

    for (double* curPomiar = pomiary; curPomiar < pomiary+N; curPomiar++) {
        // printf("\nBegin address: %p,\tCurrent address: %p,\tEnd address: %p\n",
        //          pomiary, curPomiar, pomiary+N);
        printf("Pomiar nr %i: ", (curPomiar-pomiary)+1); scanf("%lf", curPomiar);
        fprintf(out, "%lf\n", *curPomiar);
    }

    fclose(out);
    free(pomiary);
    return 0;
}


int processPomiary(const char* inPath, const char* outPath) {
    FILE* in = fopen(inPath, "r");
    if (!in) { perror("Couldn't open the input file!"); return 1; }
    FILE* out = fopen(outPath, "w");
    if (!out) { perror("Couldn't open the processed output file!"); return 1; }

    int count = 0;
    double min = DBL_MAX;
    double max = DBL_MIN;
    double sum = 0;
    
    double curVal = 0;
    while (fscanf(in, "%lf\n", &curVal) != EOF) {
        count++;
        sum += curVal;
        if (curVal < min) min = curVal;
        if (curVal > max) max = curVal;
    }

    printf("Liczba pomiarów:\t%i\n", count);
    printf("Suma pomiarów:\t\t%.3lf\n", sum);
    printf("Minimalny pomiar:\t%.3lf\n", min);
    printf("Maksymalny pomiar:\t%.3lf\n", max);
    printf("Sredni pomiar:\t\t%.3lf\n", sum/count);

    fprintf(out, "Liczba pomiarów:\t%i\n", count);
    fprintf(out, "Suma pomiarów:\t\t%.3lf\n", sum);
    fprintf(out, "Minimalny pomiar:\t%.3lf\n", min);
    fprintf(out, "Maksymalny pomiar:\t%.3lf\n", max);
    fprintf(out, "Maksymalny pomiar:\t%.3lf\n", max);
    fprintf(out, "Sredni pomiar:\t\t%.3lf\n", sum/count);


    fclose(in);
    fclose(out);
    return 0;
}