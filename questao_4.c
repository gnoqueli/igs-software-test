#include <stdio.h>
#include <stdlib.h>

struct NodeList
{
    int *data;
    int data_size;
    struct NodeList *next;
};

int cmpfunc(const void *a, const void *b)
{
    // compare function for qsort. its everywhere around the internet as well.
    return (*(int *)a - *(int *)b);
}

void clearList(struct NodeList *n)
{
    // basic list interaction
    while (n != NULL)
    {
        // clearing it, save them memories.
        struct NodeList *tmp = n;
        n = n->next;
        free(tmp);
    }
}

void printList(struct NodeList *n)
{
    // // // I was using dynamic memory here as well. things worked out fine for paramaters but shenaniganry and litle to no time made it hard to test all things through.
    // // // hope i can visit it again for closure.
    // int *data_list

    // actually had to give it a limit. sad.
    int data_list[100];
    int data_list_index = 0;
    // basic list interaction
    while (n != NULL)
    {
        int c = 0;
        // // // leftover from dynamism.
        // int *increase_data_list = realloc(data_list, sizeof(int) * (data_list_index + 1));
        while (c < n->data_size)
        {
            // code changed here as well, was using the dynamic allocation above for it, now its fixed.
            data_list[data_list_index++] = n->data[c++];
            // data_list = increase_data_list;
        }
        n = n->next;
    }
    // qsort because its simple and efficient. (would love to use pogo to see how long it would take)
    qsort(data_list, data_list_index, sizeof(int), cmpfunc);
    int final_length = 0;
    while (final_length < data_list_index)
    {
        // printing the sorted list.
        printf("%d ", data_list[final_length++]);
    }
}

int main()
{

    // first and foremost, i ensure any false statement (anything that C reads as a value of 0) goes to user input.
    char input_choice = 1;
    printf("digite 1 para usar ser usado o parâmetro do programa, 0 para os paramentros serem por input:\n");
    scanf("%hhu", &input_choice);
    if (input_choice)
    {
        // inputs through paramaters in code, using the example from the task given.
        // allocating memory for the node and its side.
        unsigned char list_size = 3;
        struct NodeList *paramenter_head = (struct NodeList *)malloc(sizeof(struct NodeList));
        struct NodeList *paramenter_second = (struct NodeList *)malloc(sizeof(struct NodeList));
        struct NodeList *paramenter_tail = (struct NodeList *)malloc(sizeof(struct NodeList));
        paramenter_head->data = malloc(sizeof(int) * 3);
        // I gave it data_size cause at first I used dynamic memory in the printList function, there's still some leftover code i'll talk about there.
        paramenter_head->data_size = 3;
        paramenter_head->data[0] = 1;
        paramenter_head->data[1] = 3;
        paramenter_head->data[2] = 8;
        paramenter_head->next = paramenter_second;
        paramenter_second->data = malloc(sizeof(int) * 3);
        paramenter_second->data_size = 3;
        paramenter_second->data[0] = 1;
        paramenter_second->data[1] = 3;
        paramenter_second->data[2] = 6;
        paramenter_second->next = paramenter_tail;
        paramenter_tail->data = malloc(sizeof(int) * 2);
        paramenter_tail->data_size = 2;
        paramenter_tail->data[0] = 8;
        paramenter_tail->data[1] = 9;
        paramenter_tail->next = NULL;
        // calling it to print followed by a clear, to free the memory.
        printList(paramenter_head);
        clearList(paramenter_head);
    }
    else
    {
        // starting with one because of while, its more charming than using do/while
        int input_size = 1;
        // on this end, things get a litle trickier. also using alloc magic to make it dynamic, using head to mantain start point and tail for everything else.
        struct NodeList *input_tail = (struct NodeList *)malloc(sizeof(struct NodeList));
        struct NodeList *input_head = input_tail;
        while (input_size)
        {
            printf("digite o tamanho da lista que sera colocada em listas. digite 0 para finalizar.\n");
            scanf("%d", &input_size);
            if (input_size)
            {
                // basically the samething that happaned above, the difference is using user input to create array size.
                input_tail->data_size = input_size;
                input_tail->data = malloc(sizeof(int) * input_size);
                printf("digite o numeros da lista, um input por vez.\n");
                for (int i = 0; i < input_size; i++)
                {
                    scanf("%d", &input_tail->data[i]);
                }
                // setting next node's address so it don't get lost in limbo
                input_tail->next = (struct NodeList *)malloc(sizeof(struct NodeList));
                input_tail = input_tail->next;
            }
        }
        // killing last node next, which was declared above, freeing it can lead to some shenanigans.
        input_tail = NULL;
        // same thing as parameters, use it then free it.
        printList(input_head);
        clearList(input_head);
    }
}