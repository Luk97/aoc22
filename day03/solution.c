#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 128

void solve_problem_1()
{
    const char* filepath = "input.txt";
    FILE* f = NULL;
    char buffer[BUFFER_SIZE];
    int n = 0, sum = 0;
    bool found_duplicate = false;

    f = fopen(filepath, "r");
    if (f == NULL) return;

    while (fgets(buffer, sizeof(buffer), f))
    {
        for (size_t i = 0; i < 128; ++i) {
            if (buffer[i] == '\0') {
                n = i - 1;
                break;
            }
        }

        found_duplicate = false;
        for (size_t i = 0; i < n/2; ++i) {
            for (size_t j = n/2; j < n; ++j) {
                if (buffer[i] == buffer[j]) {
                    if (buffer[i] < 'a') {
                        sum += buffer[i] - 'A' + 27;
                    } else {
                        sum += buffer[i] - 'a' + 1;
                    }
                    found_duplicate = true;
                    break;
                }
            }
            if (found_duplicate) break;
        }
    }
    fclose(f);
    printf("Solution 1: %d\n", sum);
}

void copy_buffer(char* src, char* dst, int n)
{
    for (size_t i = 0; i < n; ++i) {
        dst[i] = src[i];
    }
}

void solve_problem_2()
{
    const char* filepath = "input.txt";
    FILE* f = NULL;
    char buffer[BUFFER_SIZE];
    char members[3][BUFFER_SIZE];
    int member_sizes[3];
    int n = 0, sum = 0, group_index = 0;
    bool found_batch = false;

    f = fopen(filepath, "r");
    if (f == NULL) return;

    while (fgets(buffer, sizeof(buffer), f))
    {
        for (size_t i = 0; i < 128; ++i) {
            if (buffer[i] == '\0') {
                n = i - 1;
                break;
            }
        }

        copy_buffer(buffer, members[group_index % 3], n);
        member_sizes[group_index % 3] = n;

        if (group_index % 3 == 2) {
            found_batch = false;
            for (size_t i = 0; i < member_sizes[0]; ++i) {
                for (size_t j = 0; j < member_sizes[1]; ++j) {
                    if (members[0][i] == members[1][j]) {
                        for (size_t k = 0; k < member_sizes[2]; ++k) {
                            if (members[0][i] == members[2][k]) {
                                if (members[0][i] < 'a') {
                                    sum += members[0][i] - 'A' + 27;
                                } else {
                                    sum += members[0][i] - 'a' + 1;
                                }
                                found_batch = true; 
                                break;
                            }
                        }
                    }
                    if (found_batch) break;
                }
                if (found_batch) break;
            }
        }
        group_index++;
        
    }
    fclose(f);
    printf("Solution 2: %d\n", sum);
}

int main()
{
    solve_problem_1();
    solve_problem_2();
    return 0;
}