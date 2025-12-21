#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substrAmount(char* cursor, const char* substr);


int main(int argc, char* argv[]) {
    // input management
    char *logPath, *raportPath;
    if (argc < 3) {
        perror("Not enough parameters!\n");
        return 1;
    } else {
        logPath = argv[1];
        raportPath = argv[2];
    }

    // file management
    FILE* in = fopen(logPath, "r");
    if (!in) { perror("Couldn't open the input file!\n"); return 1; }

    FILE* out = fopen(raportPath, "w");
    if (!out) { perror("Couldn't open the output file!\n"); return 1; }
    
    // main func
    char *buff;
    size_t buffLen;

    int lineNum = 0;
    int warnNum = 0;
    int errNum = 0;

    
    { // allocating buffer
        fseek(in, 0, SEEK_END);
        buffLen = ftell(in);
        fseek(in, 0, SEEK_SET);

        buff = (char*)malloc(buffLen + 1);

        if (!buffLen || fread(buff, 1, buffLen, in) != buffLen) { // making sure the file has been read correctly
            free(buff); fclose(in); fclose(out);
            perror("Couldn't wholly read the file!");
            return 1;
        }
        
        buff[buffLen] = '\0';
    }

    errNum = substrAmount(buff, " ERROR ");
    warnNum = substrAmount(buff, " WARN ");
    lineNum = substrAmount(buff, "\n");
    
    {
        char outString[128];
        sprintf(outString, "Log file: %s\nLines: %i\nWarnings: %i\nErrors: %i\n", logPath, lineNum, warnNum, errNum);

        fprintf(
            out,
            outString
        );
    }

    // closing
    free(buff);
    fclose(in);
    fclose(out);
}


int substrAmount(char* cursor, const char* substr) {
    int retVal = 0;

    for (
        char* subPos = strstr(cursor, substr); 
        subPos >= cursor;
        cursor = subPos+1, subPos = strstr(cursor, substr), retVal++
    ) {}

    return retVal;
}