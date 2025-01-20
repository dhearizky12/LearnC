#include <stdio.h>
#include <string.h>

struct Student{
    char name[50];
    int age;
    float gpa;
};

int main()
{
    struct Student student1;

    //input data
    printf("Enter name : ");
    fgets(student1.name, sizeof(student1.name), stdin); // read string and stdin is the standard input
    student1.name[strcspn(student1.name, "\n")] = 0; // remove newline character

    printf("Enter age : ");
    scanf("%d", &student1.age);

    printf("Enter GPA : " );
    scanf("%f", &student1.gpa);

    //output data
    printf("\n===============================\n");
    printf("Name :  %s\n", student1.name);
    printf("Age  : %d\n", student1.age);
    printf("GPA  : %.2f\n", student1.gpa);
    printf("\n===============================");

    return 0;

}