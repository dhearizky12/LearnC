#include <stdio.h>

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
    scanf("%s", student1.name);

    printf("Enter age : ");
    scanf("%d", &student1.age);

    printf("Enter GPA : " );
    scanf("%f", &student1.gpa);

    //output data
    printf("Name :  %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA : %.2f\n", student1.gpa);

    return 0;

}