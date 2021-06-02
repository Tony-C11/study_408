#include <stdio.h>
#include <string.h>

#define WIDTH   40
#define NAME    "Tony"
#define ADDRESS "101 Megebuck Plaza"
#define PLACE   "Megapolis, CA 94904"
#define SPACE   ' '

void show_n_char(char ch, int number);

int main(void)
{
    int space;
    show_n_char('*', WIDTH);
    putchar('\n');

    space = (WIDTH - strlen(NAME)) / 2;
    show_n_char(SPACE, space);
    printf("%s", NAME);
    putchar('\n');
    
    space = (WIDTH - strlen(ADDRESS)) / 2;
    show_n_char(SPACE, space);
    printf("%s", ADDRESS);
    putchar('\n');

    space = (WIDTH - strlen(PLACE)) / 2;
    show_n_char(SPACE, space);
    printf("%s", PLACE);
    putchar('\n');

    show_n_char('*', WIDTH);
    putchar('\n');
    
    return 0;
}

void show_n_char(char ch, int number)
{
    int count;
    for (count = 1; count <= number; ++count)
    {
        printf("%c", ch);
    }

    return ;
}
