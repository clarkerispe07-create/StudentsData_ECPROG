#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

int studentIDs[MAX_STUDENTS];
char studentNames[MAX_STUDENTS][50];
float studentGPAs[MAX_STUDENTS];
char studentMajors[MAX_STUDENTS][50];
int studentCount = 0;

void displayMenu(){
    printf("===============Menu===============\n");
    printf("1. Add New Student. \n");
    printf("2. Display All Students.\n");
    printf("3. search Students by ID.\n");
    printf("4. Search Students by GPA.\n");
    printf("5. Search Students by Major.\n");
    printf("6. Exit\n");
    printf("==================================\n");
}

void addStudent(){
    char name[50];
    int id;
    float gpa;
    char major[50];
    int duplicate = 0;
    
    if(studentCount >= MAX_STUDENTS){
        printf("Error: THe database is full.");
        return;
    }
    
    printf("Enter Students Name: ");
    scanf("%d", &name);
    
}
    
int main(){
    
    displayMenu();
    addStudent();
    
    
    
    return 0;
}