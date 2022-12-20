#include  <stdio.h>
#include <stdlib.h>

void solve_problem_1_and_2()
{
    const char* filepath = "input.txt";
    FILE* f = NULL;
    char buffer[16], num_buffer[3];
    int i = 0, min1, max1, min2, max2, counter1 = 0, counter2 = 0;

    f = fopen(filepath, "r");
    if (f == NULL) return;

    num_buffer[2] = '\0';

    while (fgets(buffer, sizeof(buffer), f))
    {
        i = 0;

        // min1
        num_buffer[0] = buffer[i];
        if (buffer[++i] != '\0') {
            num_buffer[1] = buffer[i];
        }
        min1 = atoi(num_buffer);

        if (buffer[i] != '-') i++;
        num_buffer[1] = '\0';

        // max1
        num_buffer[0] = buffer[++i];
        if (buffer[++i] != '\0') {
            num_buffer[1] = buffer[i];
        }
        max1 = atoi(num_buffer);

        if (buffer[i] != ',') i++;
        num_buffer[1] = '\0';

        // min2
        num_buffer[0] = buffer[++i];
        if (buffer[++i] != '\0') {
            num_buffer[1] = buffer[i];
        }
        min2 = atoi(num_buffer);

        if (buffer[i] != '-') i++;
        num_buffer[1] = '\0';

        // max2
        num_buffer[0] = buffer[++i];
        if (buffer[++i] != '\0') {
            num_buffer[1] = buffer[i];
        }
        max2 = atoi(num_buffer);

        num_buffer[0] = '\0';
        num_buffer[1] = '\0';


        if (min1 <= min2 && max1 >= max2) counter1++;
        else if (min2 <= min1 && max2 >= max1) counter1++;

        for (int j = min1; j <= max1; ++j) {
            if (j >= min2 && j <= max2) {
                counter2++;
                break;
            }
        }
    }

    printf("Solution 1: %d\n", counter1);
    printf("Solution 2: %d\n", counter2);

    fclose(f);
}

int main()
{
    solve_problem_1_and_2();
    return 0;
}