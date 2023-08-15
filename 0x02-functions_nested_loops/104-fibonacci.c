#include <stdio.h>

/**
 * main - main block
 * Print the first 50 fibonacci numbers, starting with 1 and 2.
 * Return: 0
 */

int main(void)
{
    int c = 3;

    long int a = 1, b= 2;
    long int d = a + b;

    printf("%lu,", a);
    printf(" %lu,", b);

    while (c <= 98)
    {
       
        if (c == 98)
        {
            printf("%lu \n", d);
         }
         else  
         { 
           printf(" %lu,", d); 
         }
        a = b;
        b = d;
        d = a + b; 
        c++;
    }

    return (0);
}

