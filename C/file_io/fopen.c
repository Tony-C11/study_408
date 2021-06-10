#include <stdio.h>
#include <stdlib.h>

#define NAME    20

int main(int argc, char * argv[])
{
    FILE * fp1;
    FILE * fp2;
    unsigned long count = 0;
    char ch;
    char file[NAME];

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "We can't open this %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fp2 = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "We can't open this %s!\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp1)) != EOF)
    {
        putc(ch, fp2);
        count++;
    }
    
    printf("%s has %d characters!!!\n", argv[1], count);
    

    return 0;
}
