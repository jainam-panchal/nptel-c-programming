#include <stdio.h>

#include <stdlib.h>

struct course
{
    int code;
    int credits;
};

typedef struct course course;

course science = {1001, 10};
course maths = {1002, 5};
course literature = {1003, 5};
course philosophy = {1004, 1};

struct student
{
    char name[20];
    course courses[3];
    int grades[3];
};

typedef struct student student;

float calculate_gpa(student s)
{
    int totalCredit = 0;
    float creditIntoGrades = 0.0;

    for (int i = 0; i < 3; i++)
    {
        creditIntoGrades += s.courses[i].credits * s.grades[i];
        totalCredit += s.courses[i].credits;
    }

    return creditIntoGrades / totalCredit;
}

void print(student *s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s %.1f\n", s[i].name, calculate_gpa(s[i]));
    }
}

int main()
{
    int i, j, n;
    scanf("%d", &n);
    student *student_info = (student *)malloc(sizeof(student) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", student_info[i].name);
        for (j = 0; j < 3; j++)
        {
            int coursecode;
            scanf("%d", &coursecode);
            switch (coursecode)
            {
            case 1001:
                student_info[i].courses[j] = science;
                break;
            case 1002:
                student_info[i].courses[j] = maths;
                break;
            case 1003:
                student_info[i].courses[j] = literature;
                break;
            case 1004:
                student_info[i].courses[j] = philosophy;
                break;
            }
            scanf("%d", &student_info[i].grades[j]);
        }
    }
    print(student_info, n);
    return 0;
}