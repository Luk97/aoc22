#include <stdio.h>
#include <stdlib.h>

void solve_problem_1()
{
    const char* filepath = "input.txt";
    FILE* f = NULL;
    char buffer[32];
    int max = 0, val = 0;

    f = fopen(filepath, "r");
    if (f == NULL) return;
    
    while(fgets(buffer, sizeof(buffer), f))
    {
        if (buffer[0] == '\n') val = 0;
        else val += atoi(buffer);
        if  (val > max) max = val;
    }

    fclose(f);
    printf("Solution 1: %d\n", max);
}

int find_lowest_index(int* arr, int val)
{
    if (arr[0] < val && arr[0] <= arr[1] && arr[0] <= arr[2]) return 0;
    if (arr[1] < val && arr[1] <= arr[0] && arr[1] <= arr[2]) return 1;
    if (arr[2] < val && arr[2] <= arr[0] && arr[2] <= arr[1]) return 2;
    return -1;
}

void solve_problem_2()
{
    const char* filepath = "input.txt";
    FILE* f = NULL;
    int val = 0, index;
    int tops[3] = {0};
    char buffer[32];

    f = fopen(filepath, "r");
    if (f == NULL) return;

    while(fgets(buffer, sizeof(buffer), f))
    {
        if (buffer[0] == '\n') {
            index = find_lowest_index(tops, val);
            if (index != -1) {
                tops[index] = val;
            }
            val = 0;
        } else {
            val += atoi(buffer);
        }
    }

    index = find_lowest_index(tops, val);
    if (index != -1) tops[index] = val;
    
    printf("Solution 2: %d\n", tops[0] + tops[1] + tops[2]);
}

int main()
{
    solve_problem_1();
    solve_problem_2();
    return 0;
}