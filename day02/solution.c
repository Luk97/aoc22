#include <stdio.h>

#define ROCK 0
#define PAPER 1
#define SCISSOR 2

#define LOSE 0
#define DRAW 1
#define WIN 2

void solve_problem_1()
{
    const char* filepath = "input.txt";
    FILE* f = NULL;
    char buffer[8];
    int points = 0;
    
    f = fopen(filepath, "r");
    if (f == NULL) return;

    while (fgets(buffer, sizeof(buffer), f))
    {
        int opponent = buffer[0] - 'A';
        int you = buffer[2] - 'X';

        switch (opponent) {
            case ROCK : {
                if (you == ROCK) points += 1 + 3;
                else if (you == PAPER) points += 2 + 6;
                else if (you == SCISSOR) points += 3 + 0;
                break;
            }
            case PAPER : {
                if (you == ROCK) points += 1 + 0;
                else if (you == PAPER) points += 2 + 3;
                else if (you == SCISSOR) points += 3 + 6;
                break;
            }
            case SCISSOR : {
                if (you == ROCK) points += 1 + 6;
                else if (you == PAPER) points += 2 + 0;
                else if (you == SCISSOR) points += 3 + 3;
                break;
            }
        }
    }
    printf("Solution 1: %d\n", points);
}

void solve_problem_2()
{
    const char* filepath = "input.txt";
    FILE* f = NULL;
    char buffer[8];
    int points = 0;

    f = fopen(filepath, "r");
    if (f == NULL) return;

    while (fgets(buffer, sizeof(buffer), f))
    {
        int opponent = buffer[0] - 'A';
        int you = buffer[2] - 'X';

        switch (opponent) {
            case ROCK : {
                if (you == LOSE) points += 0 + 3;
                else if (you == DRAW) points += 3 + 1;
                else if (you == WIN) points += 6 + 2;
                break;
            }
            case PAPER : {
                if (you == LOSE) points += 0 + 1;
                else if (you == DRAW) points += 3 + 2;
                else if (you == WIN) points += 6 + 3;
                break;
            }
            case SCISSOR : {
                if (you == LOSE) points += 0 + 2;
                else if (you == DRAW) points += 3 + 3;
                else if (you == WIN) points += 6 + 1;
                break;
            }
        }
    }
    printf("Solution 2: %d\n", points);
}

int main()
{
    solve_problem_1();
    solve_problem_2();
    return 0;
}