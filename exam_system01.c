#include <stdio.h>

// Feature: Student details
struct Student {
    int rollNo;
    char name[50];
    float marks[5];       // Feature: Subject marks
    float total;          // Feature: Total marks
    float percentage;     // Feature: Percentage
    char grade;           // Feature: Grade calculation
};

int main() {
    int n, i, j;

    printf("Examination Management System \n");
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Valid number of students required.\n");
        return 1;
    }

    struct Student s[n];

    // Input and Calculations
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);
        
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);
        
        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter marks for 5 subjects (out of 100): ");
        s[i].total = 0;
        for (j = 0; j < 5; j++) {
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = (s[i].total / 500.0) * 100.0;

        if (s[i].percentage >= 90) {
            s[i].grade = 'A';
        } else if (s[i].percentage >= 75) {
            s[i].grade = 'B';
        } else if (s[i].percentage >= 50) {
            s[i].grade = 'C';
        } else {
            s[i].grade = 'F';
        }
    }

    //Result generation
    printf("\n\n----GENERATED RESULTS---- \n");
    printf("Roll\tName\tTotal\tPercent\tGrade\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.1f\t%.2f%%\t%c\n", 
               s[i].rollNo, s[i].name, s[i].total, s[i].percentage, s[i].grade);
    }

    // Feature: Topper identification
    int topperIndex = 0;
    for (i = 1; i < n; i++) {
        if (s[i].total > s[topperIndex].total) {
            topperIndex = i;
        }
    }

    printf("\n----TOPPER OF THE CLASS---- \n");
    printf("Name        : %s\n", s[topperIndex].name);
    printf("Roll Number : %d\n", s[topperIndex].rollNo);
    printf("Total Marks : %.1f\n", s[topperIndex].total);
    printf("Percentage  : %.2f%%\n", s[topperIndex].percentage);

    return 0;
}