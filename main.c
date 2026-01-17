#include <stdio.h>
#include <string.h>

typedef struct student
{
    char firstname[50];
    char lastname[50];
    int rollno;
    float CGPA;
    int courseid[5];
} student;

void addstudent(student[], int *, int);
void findbyrollno(student[], int *);
void findbyname(student[], int *);
void findregisteredstudents(student[], int *);
void totalcount(int *);
void deletestudent(student[], int *);
void updatestudent(student[], int *);

int main()
{
    int i = 0;
    student st[50];
    while (1)
    {
        printf("\n");
        printf("---------------- STUDENT MANAGEMENT SYSTEM! ----------------\n\n");
        printf("Choose the operation you want to perform: \n"
               "1. add a student: \n"
               "2. find a student by roll no: \n"
               "3. find a student by name: \n"
               "4. find a student by courseid: \n"
               "5. find total number of students: \n"
               "6. delete a student: \n"
               "7. update a student detail: \n"
               "8. Exit the system\n");
        int c;
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            addstudent(st, &i, i);
            break;
        case 2:
            findbyrollno(st, &i);
            break;
        case 3:
            findbyname(st, &i);
            break;
        case 4:
            findregisteredstudents(st, &i);
            break;
        case 5:
            totalcount(&i);
            break;
        case 6:
            deletestudent(st, &i);
            break;
        case 7:
            updatestudent(st, &i);
            break;
        case 8:
            return 0;
        default:
            printf("No valid input\n");
            break;
        }
    }
}

void addstudent(student a[], int *b, int c)
{
    printf("---------------- ADD A STUDENT! ----------------\n\n");
    printf("Enter the first name: \n");
    scanf("%s", a[c].firstname);
    printf("Enter the last name: \n");
    scanf("%s", a[c].lastname);
    printf("Enter the rollno: \n");
    scanf("%d", &a[c].rollno);
    printf("Enter the CGPA: \n");
    scanf("%f", &a[c].CGPA);
    printf("Enter the course id for 5 subjects: \n");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &a[c].courseid[j]);
    }
    *b = *b + 1;
}

void findbyrollno(student a[], int *b)
{
    int temp;
    printf("---------------- FIND A STUDENT BY ROLLNO! ----------------\n\n");
    printf("Enter the rollno of the student: \n");
    scanf("%d", &temp);
    for (int j = 0; j < *b; j++)
    {
        if (temp == a[j].rollno)
        {
            printf("The name of the student is: %s %s\n", a[j].firstname, a[j].lastname);
            printf("The rollno of the student is: %d\n", a[j].rollno);
            printf("The CGPA of the student is: %f\n", a[j].CGPA);
            printf("The courseid for 5 subjects is: \n");
            for (int k = 0; k < 5; k++)
            {
                printf("%d\n", a[j].courseid[k]);
            }
        }
    }
}

void findbyname(student a[], int *b)
{
    char temp[50];
    printf("---------------- FIND A STUDENT BY NAME! ----------------\n\n");
    printf("Enter the first name of the student: \n");
    scanf("%s", temp);
    for (int j = 0; j < *b; j++)
    {
        if (strcmp(a[j].firstname, temp) == 0)
        {
            printf("The name of the student is: %s %s\n", a[j].firstname, a[j].lastname);
            printf("The rollno of the student is: %d\n", a[j].rollno);
            printf("The CGPA of the student is: %f\n", a[j].CGPA);
            printf("The courseid for 5 subjects is: \n");
            for (int k = 0; k < 5; k++)
            {
                printf("%d\n", a[j].courseid[k]);
            }
        }
    }
}

void findregisteredstudents(student a[], int *b)
{
    int temp;
    printf("---------------- FIND A STUDENT BY COURSEID! ----------------\n\n");
    printf("Enter the course id of the student: \n");
    scanf("%d", &temp);
    for (int j = 0; j < *b; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (temp == a[j].courseid[k])
            {
                printf("The name of the student is: %s %s\n", a[j].firstname, a[j].lastname);
                printf("The rollno of the student is: %d\n", a[j].rollno);
                printf("The CGPA of the student is: %f\n", a[j].CGPA);
                printf("The courseid for 5 subjects is: \n");
                for (int p = 0; p < 5; p++)
                {
                    printf("%d\n", a[j].courseid[p]);
                }
            }
        }
    }
}

void totalcount(int *b)
{
    printf("---------------- FIND TOTAL NO OF STUDENT! ----------------\n\n");
    printf("The total number of student is: %d\n", *b);
}

void deletestudent(student a[], int *b)
{
    printf("---------------- REMOVE A STUDENT! ----------------\n");
    int temp;
    printf("Enter the rollno of the student you want to remove: \n");
    scanf("%d", &temp);
    for (int j = 0; j < *b; j++)
    {
        if (temp == a[j].rollno)
        {
            for (int k = j; k < *b - 1; k++)
            {
                a[k] = a[k + 1];
            }
            *b = *b - 1;
            printf("The student has been removed successfully!\n");
            break;
        }
    }
}

void updatestudent(student a[], int *b)
{
    printf("---------------- UPDATE STUDENT INFO! ----------------\n\n");
    int temp;
    printf("Enter the rollno of the student record you want to update: \n");
    scanf("%d", &temp);
    for (int j = 0; j < *b; j++)
    {
        if (temp == a[j].rollno)
        {
            printf("Choose the category you want to update: \n\n");
            printf("1. Update first name:\n"
                   "2. Update last name:\n"
                   "3. Update rollno:\n"
                   "4. Update CGPA:\n"
                   "5. Update all subject course id:\n");
            int c;
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                printf("Enter first name: \n");
                scanf("%s", a[j].firstname);
                break;
            case 2:
                printf("Enter last name: \n");
                scanf("%s", a[j].lastname);
                break;
            case 3:
                printf("Enter rollno: \n");
                scanf("%d", &a[j].rollno);
                break;
            case 4:
                printf("Enter CGPA: \n");
                scanf("%f", &a[j].CGPA);
                break;
            case 5:
                printf("Enter 5 subject course id: \n");
                scanf("%d %d %d %d %d", &a[j].courseid[0], &a[j].courseid[1], &a[j].courseid[2], &a[j].courseid[3], &a[j].courseid[4]);
                break;
            }
            printf("Student details updated successfully!\n");
            break;
        }
    }
}
