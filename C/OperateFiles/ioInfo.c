#include <stdio.h>

int main(void)
{
    char ch;
    int guess = 1;
    printf("%d?\n", guess);
    while ((ch = getchar()) != 'y' && guess <= 100)
    {
        while (getchar() != '\n')
            continue;
        if ('n' == ch)
            printf("Is it %d?\n", ++guess);
        else
            printf("Sorry, I can't understand your mean, please input again: ");
    } 
    printf("OK, I'm right!\n");
    return 0;
}
