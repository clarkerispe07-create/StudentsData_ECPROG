#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float gpa;
    char major[50];
} Student;

Student studentDB[MAX_STUDENTS];
int studentCount = 0;

void displayMenu() {
    printf("\n==========Menu==========\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Students by ID\n");
    printf("4. Search Students by GPA\n");
    printf("5. Search Student by Major\n");
    printf("6. Exit\n");
    printf("=======================\n");
}

void addStudent() {
    Student newStudent;
    int duplicate = 0;
    
    if (studentCount >= MAX_STUDENTS) {
        printf("ERROR: Student database is full!\n");
        return;
    }
    
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    
    for (int i = 0; i < studentCount; i++) {
        if (studentDB[i].id == newStudent.id) {
            duplicate = 1;
            break;
        }
    }
    
    if (duplicate == 1) {
        printf("ERROR: Student with ID %d already exists!\n", newStudent.id);
        return;
    }
    
    printf("Enter Student Name: ");
    scanf(" %s", newStudent.name);
    
    printf("Enter Student GPA: ");
    scanf("%f", &newStudent.gpa);
    
    printf("Enter Student Major: ");
    scanf(" %s", newStudent.major);
    
    studentDB[studentCount] = newStudent;
    studentCount++;
    
    printf("\nStudent added successfully!\n");
}

void displayAllStudents() {
    if (studentCount == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    printf("\n========== All Students ==========\n");
    printf("%-10s %-20s %-10s %-15s\n", "ID", "Name", "GPA", "Major");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-20s %-10.2f %-15s\n", 
               studentDB[i].id, 
               studentDB[i].name, 
               studentDB[i].gpa, 
               studentDB[i].major);
    }
    printf("===================================\n");
    printf("Total Students: %d\n", studentCount);
}

void searchByID() {
    int id, found = 0;
    
    if (studentCount == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < studentCount; i++) {
        if (studentDB[i].id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", studentDB[i].id);
            printf("Name: %s\n", studentDB[i].name);
            printf("GPA: %.2f\n", studentDB[i].gpa);
            printf("Major: %s\n", studentDB[i].major);
            found = 1;
            break;
        }
    }
    
    if (found == 0) {
        printf("Student with ID %d not found!\n", id);
    }
}

void searchByGPA() {
    float minGPA, maxGPA;
    int found = 0;
    
    if (studentCount == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    printf("Enter minimum GPA: ");
    scanf("%f", &minGPA);
    printf("Enter maximum GPA: ");
    scanf("%f", &maxGPA);
    
    printf("\n========== Students with GPA %.2f - %.2f ==========\n", minGPA, maxGPA);
    printf("%-10s %-20s %-10s %-15s\n", "ID", "Name", "GPA", "Major");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        if (studentDB[i].gpa >= minGPA && studentDB[i].gpa <= maxGPA) {
            printf("%-10d %-20s %-10.2f %-15s\n", 
                   studentDB[i].id, 
                   studentDB[i].name, 
                   studentDB[i].gpa, 
                   studentDB[i].major);
            found = 1;
        }
    }
    
    if (found == 0) {
        printf("No students found with GPA in that range!\n");
    }
    printf("==================================================\n");
}

void searchByMajor() {
    char major[50];
    int found = 0;
    
    if (studentCount == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    printf("Enter Major to search: ");
    scanf(" %s", major);
    
    printf("\n========== Students in %s ==========\n", major);
    printf("%-10s %-20s %-10s\n", "ID", "Name", "GPA");
    printf("------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentDB[i].major, major) == 0) {
            printf("%-10d %-20s %-10.2f\n", 
                   studentDB[i].id, 
                   studentDB[i].name, 
                   studentDB[i].gpa);
            found = 1;
        }
    }
    
    if (found == 0) {
        printf("No students found with major: %s\n", major);
    }
    printf("==========================================\n");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchByID(); break;
            case 4: searchByGPA(); break;
            case 5: searchByMajor(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please select 1-6.\n");
        }
    } while (choice != 6);
    
    return 0;
}
