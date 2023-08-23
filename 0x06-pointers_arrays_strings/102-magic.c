#include <stdio.h>

/*
   * write your line of code here...
   * Remember:
   * - you are not allowed to use a
   * - you are not allowed to modify p
   * - only one statement
   * - you are not allowed to code anything else than this line of code
   */
int main(void)
{
int i;
int j[5];
int *k;

j[2] = 1024;
k = &i;
*(k + 5) = 98;
printf("j[2] = %d\n", j[2]);
return (0);
}
