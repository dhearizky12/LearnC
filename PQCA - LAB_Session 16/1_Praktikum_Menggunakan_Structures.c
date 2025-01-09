/*
    Buatlah program yang meminta pengguna untuk memasukkan data beberapa siswa
    (nama, umur, dan nilai), menyimpannya dalam array of structures, dan kemudian
    mencetak data tersebut.
*/

#include <stdio.h>

struct Student{
    char name[50];
    int age;
    float grade;
};

int main()
{
    int n;
    printf("Enter the number of students : ");
    scanf("%d", &n);

    struct Student students[n];

    for ( int i = 0; i < n; i++ )
    {
        printf("Enter name, age, and grade for student %d : \n", i+1);

        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].grade );
    }

    printf ("\nStudent Details:\n");

    for (int i = 0; i < n; i++ )
    {
        printf("Name : %s, Age : %d, Grade : %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    return 0;
}