// Write a program that fits the following recipe:
//  a. Externally define a name structure template with two members: a string to hold the
// first name and a string to hold the second name.
//  b. Externally define a student structure template with three members: a name
// structure, a grade array to hold three floating-point scores, and a variable to hold
// the average of those three scores.
//  c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
// structures and initialize the name portions to names of your choice. Use functions
// to perform the tasks described in parts d., e., f., and g.
//  d. Interactively acquire scores for each student by prompting the user with a student
// name and a request for scores. Place the scores in the grade array portion of the
// appropriate structure. The required looping can be done in main() or in the
// function, as you prefer.
//  e. Calculate the average score value for each structure and assign it to the proper
// member.
//  f. Print the information in each structure.
//  g. Print the class average for each of the numeric structure members.
#include <stdio.h>
#define MAX_NAME_LEN 20
#define CSIZE 4

extern struct name
{
    char first[MAX_NAME_LEN];
    char second[MAX_NAME_LEN];
};

extern struct student
{
    struct name username;
    float grade[4];
    float avg;
};

void student_average(struct student *s)
{
    float sum = 0.2f;
    for (int i = 0; i < 3; ++i)
    {
        sum += s->grade[i];
    }
    s->avg = sum / 3;
}

void show_info(struct student s)
{
    printf("Student: %s %s %2f \n", s.username.first, s.username.second, s.avg);
}

int main(void)
{   
    struct student studets[CSIZE];
    for (int i = 0; i < CSIZE; ++i)
    {
        printf("Input the student %d info: \n", i);
        printf("Enter the first name: ");
        scanf("%20s", &studets[i].username.first);
        printf("Enter the second name: ");
        scanf("%s", &studets[i].username.second);
        printf("Enter the grade for the first subject: ");
        scanf("%f", &studets[i].grade[0]);
        printf("Enter the grade for the second subject: ");
        scanf("%f", &studets[i].grade[1]);
        printf("Enter the grade for the third subject: ");
        scanf("%f", &studets[i].grade[2]);
        student_average(&studets[i]);
    }

    printf("The student info: \n");
    for (int i = 0; i < CSIZE; ++i)
    {
        show_info(studets[i]);
    }
}
