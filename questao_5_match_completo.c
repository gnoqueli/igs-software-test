#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5

// this exercise counts for a perfect match on the slots. if the entire slot is equals, jackpot! you won.
// otherwise, the program will break before even finishes the whole algorithm
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

    // as stated above, this algorithm is for a whole match, so I removed unecessary variables and shortened the while loop.
    // of course it would be faster to remove all loops all together but it would make the code itself less change-efficient.
    int premio[LINHAS][COLUNAS] = {{1, 0, 0, 0, 1},
                                   {0, 1, 0, 1, 0},
                                   {0, 0, 1, 0, 0}};
    int lines = 0, cols = 0;
    int **slot = cria_slot(slot);
    while (lines < 3)
    {
        while (cols < 5)
        {
            // "break point" in case any value is different from what it should be
            if (slot[lines][cols] != premio[lines][cols])
            {
                free(slot);
                return 0;
            }
            cols++;
        }
        cols = 0;
        lines++;
    }
    free(slot);
    printf("Ganhou!\n");
    return 0;
}