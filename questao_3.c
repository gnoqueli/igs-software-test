#include <stdio.h>


// this is probably the task I had the more fun with. I used lots (maybe too much) bitwise operators when doing criptos. very fun.

int main()
{

    unsigned int starting_color = 0x00;
    unsigned int final_color = 0x00;
    unsigned char steps = 0x00;
    printf("Input the starting color as a hexadecimal number (example 0xF02A08):\n");
    scanf("%x", &starting_color);
    printf("Now, input the final color as a hexadecimal number (example 0xFFFFFF):\n");
    scanf("%x", &final_color);
    printf("Now, input the amount of steps:\n");
    scanf("%hhu", &steps);

    // // we could do a bit shifting to use less memory and make it readable still
    // unsigned char starting_red = (starting_color & 0xFF0000) >> 16;
    // unsigned char final_red = (final_color & 0xFF0000) >> 16;

    // or we could make the bitshifting directly in the stepsize assignment to save memory
    unsigned char step_size = (((final_color & 0xFF0000) >> 16) - ((starting_color & 0xFF0000) >> 16)) / steps;

    while (starting_color < final_color)
    {
        // bit shifting it back to add it to starting value, using the same variables so it saves memory.
        starting_color += step_size << 16;
        printf("0x%06X\\n ", starting_color);
    }
    printf("\n");

    return 0;
}