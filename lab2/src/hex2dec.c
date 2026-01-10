#include <stdio.h>
#include <string.h>


int hexToDecDigit(char c);
int hexToDec(char * n);

int main() {
    printf("Source file running program: %s\n", __FILE__);
    // file handling
    FILE* in = fopen("data/hexvalues.txt", "r");
    if (!in) { puts("In file could not be opened!"); return 1; }
    
    FILE* out = fopen("results/hex_to_dec.txt", "w");
    if (!out) { puts("Out file could not be opened!"); return 1; }

    // main func
    ssize_t len = 0;
    size_t maxLen = 256;
    char * line = NULL;
    while ((len = getline(&line, &maxLen, in)) != -1) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        int result = hexToDec(line);
        fprintf(out, "%-8s = %d\n", line, result);
    }

    fclose(in); fclose(out);
}


int hexToDecDigit(char c) {
    if (c >= 'a') {
        return (int)(c - 'a') + 10;
    } else if (c >= 'A') {
        return (int)(c - 'A') + 10;
    } else if (c >= '0') {
        return c - '0';
    }
    return -1;
}

int hexToDec(char * n) {
    int out = hexToDecDigit(n[0]);

    for (int i = 1; n[i] != '\0'; i++) {
        out = out * 16 + hexToDecDigit(n[i]);
    }
    return out;
}
