#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5

// this exercise counts for n singular matches in the slots, this case we count 5 matches. if it matches 5 times, jackpot! you won.
int **cria_slot(int **slot)
{
    int col, line = 0;

    // refac'ed it so it goes through the loop less times. I could've made so the input would be single lined but it would make the code itself heavier.
    slot = malloc(sizeof(int *) * 3);
    while (line < 3)
    {
        col = 0;
        slot[line] = malloc(sizeof(int));
        printf("Insira os valores da linha %d:\n", (line + 1));
        while (col < 5)
            scanf("%d", &slot[line][col++]);
        line++;
    }
    return (slot);
}

int main(void)
{

    // as stated above, this algorithm is for a set number of matches, so I removed unecessary variables and shortened the while loop.
    // of course it would be faster to remove all loops all together but it would make the code itself less change-efficient.
    int premio[LINHAS][COLUNAS] = {{1, 0, 0, 0, 1},
                                   {0, 1, 0, 1, 0},
                                   {0, 0, 1, 0, 0}};
    int lines = 0, cols = 0, match = 0;
    int **slot = cria_slot(slot);
    while (lines < 3)
    {
        while (cols < 5)
        {
            if (slot[lines][cols] == premio[lines][cols])
            {
                if (match++ >= 4)
                {
                    printf("Ganhou!\n");
                    break;
                }
            }
            cols++;
        }
        cols = 0;
        lines++;
    }
    free(slot);
    return 0;
}