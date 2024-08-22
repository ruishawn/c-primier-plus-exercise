// Write a program that creates a structure template with two members according to the
// following criteria:
//  a. The first member is a social security number. The second member is a structure
// with three members. Its first member contains a first name, its second member
// contains a middle name, and its final member contains a last name. Create and
// initialize an array of five such structures. Have the program print the data in this
// format:
//  Dribble, Flossie M. –– 302039823
// Only the initial letter of the middle name is printed, and a period is added. Neither the
// initial (of course) nor the period should be printed if the middle name member is empty.
// Write a function to do the printing; pass the structure array to the function.
//  b. Modify part a. by passing the structure value instead of the address.

#include <stdio.h>
#include <ctype.h>
#define MAX_NAME 30

struct username
{
    char first[MAX_NAME];
    char middle[MAX_NAME];
    char last[MAX_NAME];
};

struct user
{
    long ssn;
    struct username name;
};

void print_user(struct user users[], int);
void print_user_byp(struct user *userp, int);

void print_user_byp(struct user *userp, int size)
{   
    printf("print user info by input user struct pointer\n");
    for (int i = 0; i < size; i++)
    {   
        struct user *currentuser = userp + i;
        char middle_name[3] = "";
        if (currentuser->name.middle[0] != '\0')
        {
            sprintf(middle_name, "%c.", toupper(currentuser->name.middle[0]));
        }

        printf("%s, %s –– %ld\n",
               currentuser->name.first,
               middle_name,
               currentuser->ssn);
    }
}

void print_user(struct user users[], int size)
{
    printf("print user info by input user struct array\n");
    for (int i = 0; i < size; i++)
    {
        char middle_name[3] = "";
        if (users[i].name.middle[0] != '\0')
        {
            sprintf(middle_name, "%c.", toupper(users[i].name.middle[0]));
        }

        printf("%s, %s –– %ld\n",
               users[i].name.first,
               middle_name,
               users[i].ssn);
    }
}

int main()
{
    struct user users[5] =
        {
            {302039823, {"Dri", "lossie", "UK"}},
            {302039824, {"Eri", "interl", "AB"}},
            {302039825, {"Groggle", "", "HM"}},
            {302039826, {"Frib", "kmoss", "CN"}},
            {302039827, {"Hkniu", "ssie", "HK"}}};
    print_user(users, 5);
    struct user *userp = users;
    print_user_byp(userp, 5);

    return 0;
}