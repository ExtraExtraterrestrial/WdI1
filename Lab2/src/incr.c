#include <stdio.h>

void incrPtr(int* x) { 
    printf("\nincrPtr called!\nx before incr: %d\n", (*x)++);
    printf("x after incr: %d", *x);
}
void incrVal(int x) {
    printf("\nincrVal called!\nx before incr: %d\n", x++);
    printf("x after incr: %d", x);
}

int main() {
    printf("Source file running program: %s\n", __FILE__);
    int x = 0;

    printf("\nx in main scope: %d\n", x);
    incrPtr(&x);
    printf("\nx in main scope: %d\n", x);
    incrVal(x);
    printf("\nx in main scope: %d\n", x);
    incrPtr(&x);
    printf("\nx in main scope: %d\n", x);
    incrVal(x);
    printf("\nx in main scope: %d\n", x);

}