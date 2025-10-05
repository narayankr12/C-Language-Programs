#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float score;
} Student;


int compareScores(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return (s2->score - s1->score) * 100; 
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Score: ");
        scanf("%f", &students[i].score);
    }

    
    qsort(students, n, sizeof(Student), compareScores);


    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("File creation failed.\n");
        free(students);
        return 1;
    }

    fprintf(fp, "Sorted Student Records (by Score):\n");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s, Age: %d, Score: %.2f\n", students[i].name, students[i].age, students[i].score);
    }

    fclose(fp);
    free(students);
    printf("\n✅ Student records saved to 'students.txt'\n");

    return 0;
}
