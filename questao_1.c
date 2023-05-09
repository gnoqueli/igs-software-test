#include <stdio.h>
#include <string.h>

// there's no such thing as a 0 sized palindrome. a single letter such as "a" is a palindrome of size 1.
// do not, by any means, reinvent the wheel. this function works and can be found anywhere on the internet.
// Function to print a substring str[low..high]
void printSubStr(const char *str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        printf("%c", str[i]);
}

// this function returns the length of the longest palindrome
int longestPalSubstr(const char *str)
{
    // Get length of input string
    int n = strlen(str);

    // All substrings of length 1 are palindromes
    int maxLength = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int flag = 1;

            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            // Palindrome
            if (flag && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    // Return length of LPS
    return maxLength > 1 ? maxLength : 0;
}

// Driver Code
int main()
{
    char *filename = "strings_01.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fp))
        printf("%d\n", longestPalSubstr(buffer));

    // close the file
    fclose(fp);
    return 0;
}