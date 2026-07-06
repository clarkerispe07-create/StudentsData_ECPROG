#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

int studentIDs[MAX_STUDENTS];
char studentNames[MAX_STUDENTS][50];
float studentGPAs[MAX_STUDENTS];
char studentMajors[MAX_STUDENTS][50];
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
    int id;
    char name[50];
    float gpa;
    char major[50];
    int duplicate = 0;
    
    if (studentCount >= MAX_STUDENTS) {
        printf("Error: Student database is full!\n");
        return;
    }
    
    printf("Enter Student ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < studentCount; i++) {
        if (studentIDs[i] == id) {
            duplicate = 1;
        }
    }
    
    if (duplicate == 1) {
        printf("Error: Student with ID %d already exists!\n", id);
        return;
    }
    
    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);
    
    printf("Enter Student GPA: ");
    scanf("%f", &gpa);
    
    printf("Enter Student Major: ");
    scanf(" %[^\n]", major);
    
    studentIDs[studentCount] = id;
    strcpy(studentNames[studentCount], name);
    studentGPAs[studentCount] = gpa;
    strcpy(studentMajors[studentCount], major);
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
               studentIDs[i], 
               studentNames[i], 
               studentGPAs[i], 
               studentMajors[i]);
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
        if (studentIDs[i] == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", studentIDs[i]);
            printf("Name: %s\n", studentNames[i]);
            printf("GPA: %.2f\n", studentGPAs[i]);
            printf("Major: %s\n", studentMajors[i]);
            found = 1;
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
        if (studentGPAs[i] >= minGPA && studentGPAs[i] <= maxGPA) {
            printf("%-10d %-20s %-10.2f %-15s\n", 
                   studentIDs[i], 
                   studentNames[i], 
                   studentGPAs[i], 
                   studentMajors[i]);
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
    scanf(" %[^\n]", major);
    
    printf("\n========== Students in %s ==========\n", major);
    printf("%-10s %-20s %-10s\n", "ID", "Name", "GPA");
    printf("------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentMajors[i], major) == 0) {
            printf("%-10d %-20s %-10.2f\n", 
                   studentIDs[i], 
                   studentNames[i], 
                   studentGPAs[i]);
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
        
        if (choice == 1) {
            addStudent();
        }
        else if (choice == 2) {
            displayAllStudents();
        }
        else if (choice == 3) {
            searchByID();
        }
        else if (choice == 4) {
            searchByGPA();
        }
        else if (choice == 5) {
            searchByMajor();
        }
        else if (choice == 6) {
            printf("Exiting program...\n");
        }
        else {
            printf("Invalid choice! Please select 1-6.\n");
        }
    } while (choice != 6);
    
    return 0;
} 