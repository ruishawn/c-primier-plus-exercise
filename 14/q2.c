// Write a program that prompts the user to enter the day, month, and year. The month
// can be a month number, a month name, or a month abbreviation. The program then
// should return the total number of days in the year up through the given day. (Do take
// leap years into account.)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct month
{
    char name[10];
    char abbrev[4];
    int days;
    int month;
};

int is_leap(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    return -1;
}

int get_days_by_input(int year, char *month, int day)
{
    struct month mons[12] = {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}};

    // process year
    int leap = is_leap(year);
    if (leap == 1)
    {
        mons[1].days = 29;
    }

    // process month
    int month_num = 0;
    for (int i = 0; i < 12; ++i)
    {
        char month_str[3];
        sprintf(month_str, "%d", mons[i].month);
        if (strcmp(month, mons[i].name) == 0 || strcmp(month, mons[i].abbrev) == 0 || strcmp(month, month_str) == 0)
        {
            month_num = mons[i].month;
            break;
        }
    }

    if (month_num < 1 || month_num > 12)
    {
        printf("Invalid month number\n");
        return -1;
    }

    // process day
    if (day < 1 || day > mons[month_num - 1].days)
    {
        printf("Invalid day number\n");
        return -1;
    }

    int result = mons[month_num - 1].days - day;
    for (int j = month_num; j < 12; j++)
    {
        result += mons[j].days;
    }
    return result;
}

int main(void)
{
    int year, day;
    char month[10];
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month: ");
    scanf("%s", month);
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("The total number of days in the year up through the given day is %d\n", get_days_by_input(year, month, day));
}