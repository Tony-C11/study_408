#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int Age;

typedef struct 
{
    char name[40];
    Age age;
} Student;

Student * creatInfoTable(void);

int main(void)
{
    Student * ptr = creatInfoTable();
    
    // printf("%d\n", ptr->age);
    char * ptrArr = (char *)malloc(sizeof(char) * 20);
    ptrArr[1] = 'a';
    ptrArr[0] = 'A';
    printf("%c, %c,%c,,,,\n", ptrArr[0], ptrArr[1], ptrArr[2]);

    free(ptrArr);
    free(ptr);

    return 0;
}

Student * creatInfoTable(void)
{
    Student * ptr_tab = (Student *)malloc(sizeof(Student) * 3);
    ptr_tab->age = 100;
    return ptr_tab;
}