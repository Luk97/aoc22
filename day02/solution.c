#include <stdio.h>

#define ROCK 0 //rock
#define PAPER 1 //paper
#define SCISSOR 2 //scissor

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

int main()
{
    solve_problem_1();
    return 0;
}