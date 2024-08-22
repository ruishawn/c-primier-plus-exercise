// Redo Review Question 5, but make the argument the spelled-out name of the month
// instead of the month number. (Don’t forget about strcmp().) Test the function in a
// simple program.

#include <stdio.h>
#include <string.h>

struct month
{
    char name[10];
    char abbrev[4];
    int days;
    int month;
};

// int get_days_by_mon_num(int mon);
int get_days_by_mon_name(struct month mons[], char *name);
int main(void)
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
    printf("Enter the month name: ");
    char name[10];
    scanf("%9s", name);
    printf("days: %d\n ", get_days_by_mon_name(mons, name));
}

int get_days_by_mon_name(struct month mons[], char *mon_name)
{
    for (int i = 0; i < 12; ++i)
    {
        int sum = 0 ;
        if (strcmp(mons[i].name, mon_name) == 0)
        {
            for (int j = i; j < 12; ++j)
            {
                sum += mons[j].days;
            }
            return sum;
        }
    }
    return -1;
}