#include <stdio.h>

#define MAX_SUBJECTS 3

// Fungsi untuk menghitung rata-rata nilai
float calculate_average(float marks[], int num_subjects) 
{
    float total = 0.0;
    for (int i = 0; i < num_subjects; i++) 
    {
        total += marks[i];
    }
    return total / num_subjects;
}

int main() {
    // Deklarasi variabel
    char student_name[100];
    int roll_number;
    float marks[MAX_SUBJECTS];
    int num_subjects;
    
    // Input nama lengkap siswa
    printf("Enter student's name: ");
    fgets(student_name, sizeof(student_name), stdin); // Menggunakan fgets untuk nama lengkap

    // Menghapus newline pada akhir input nama (jika ada)
    student_name[strcspn(student_name, "\n")] = '\0';

    // Input nomor induk
    printf("Enter roll number: ");
    scanf("%d", &roll_number);

    // Input jumlah mata pelajaran
    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &num_subjects);
    
    // Validasi jumlah mata pelajaran
    if (num_subjects > MAX_SUBJECTS) 
    {
        printf("The number of subjects can't be more than %d. Setting it to %d.\n", MAX_SUBJECTS, MAX_SUBJECTS);
        num_subjects = MAX_SUBJECTS;
    }

    // Input nilai untuk setiap mata pelajaran
    for (int i = 0; i < num_subjects; i++) 
    {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Menghitung rata-rata nilai
    float average = calculate_average(marks, num_subjects);

    // Output format
    printf("\n=== Student Details ===\n");
    printf("Name       : %s\n", student_name);
    printf("Roll Number: %d\n", roll_number);
    printf("Subjects   : %d\n", num_subjects);
    
    // Menampilkan nilai per mata pelajaran
    for (int i = 0; i < num_subjects; i++) 
    {
        printf("Marks for subject %d: %.2f\n", i + 1, marks[i]);
    }

    // Menampilkan rata-rata
    printf("Average Marks: %.2f\n", average);

    return 0;
}
