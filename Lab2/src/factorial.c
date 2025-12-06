#include <stdio.h>

int factorial_iter(int n);
int factorial_rec(int n);


int main(int argc, char* argv[]) {
    printf("Source file running program: %s\n", __FILE__);
    int n;
    #ifdef FAC_ITER
    n = factorial_iter(500);
    #else
    n = factorial_rec(500);
    #endif

    
    FILE* out = fopen("results/int_overflow.txt", "w");
    if (!out) { puts("Couldn't open file;\n"); return -1; }
    fprintf(out, "%d\n", n);
    fclose(out);
    
}


int factorial_iter(int n) {
    int retVal = 1;
    for (int i = 1; i<n && retVal > retVal*i; retVal*=i, i++) {
        printf("%d\n", retVal);
    }
    return retVal;
}

int factorial_rec(int n) {
    if (n<=1) return 1;
    int res = n * factorial_rec(n-1);
    if (res < n) { return n; }
    return res;
}