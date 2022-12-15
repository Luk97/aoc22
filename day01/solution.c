#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char* filepath = "input.txt";
    FILE* f = fopen(filepath, "r");
    if (f == NULL) return -1;
    
    char buffer[256];
    int max = 0, val = 0;
    while(fgets(buffer, sizeof(buffer), f))
    {
        if (buffer[0] == '\n') {
            if  (val > max) max = val;
            val = 0;
        }
        else val += atoi(buffer);
    }

    fclose(f);
    printf("Solution: %d\n", max);


 
    return 0;
}