// A text file holds information about a softball team. Each line has data arranged as
// follows:
//  4 Jessie Joybat 5 2 1 1
//  The first item is the player’s number, conveniently in the range 0–18. The second item
// is the player’s first name, and the third is the player’s last name. Each name is a single
// word. The next item is the player’s official times at bat, followed by the number of hits,
// walks, and runs batted in (RBIs). The file may contain data for more than one game,
// so the same player may have more than one line of data, and there may be data for
// other players between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and last names, the
// at bats, hits, walks, and RBIs (runs batted in), and the batting average (to be calculated
// later). You can use the player number as an array index. The program should read to endof-file, and it should keep cumulative totals for each player.
//  The world of baseball statistics is an involved one. For example, a walk or reaching base
// on an error doesn’t count as an at-bat but could possibly produce an RBI. But all this
// program has to do is read and process the data file, as described next, without worrying
// about how realistic the data is.
// The simplest way for the program to proceed is to initialize the structure contents to
// zeros, read the file data into temporary variables, and then add them to the contents of
// the corresponding structure. After the program has finished reading the file, it should
// then calculate the batting average for each player and store it in the corresponding
// structure member. The batting average is calculated by dividing the cumulative number
// of hits for a player by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each player along
// with a line showing the combined statistics for the entire team.

#include <stdio.h>
#include <string.h>
#define MAX_LEN 19

struct player
{
    int number;
    char firstname[20];
    char lastname[20];
    int atbat;
    int hits;
    int walks;
    int rbis;
    float batting_average;
};

void show_info(struct player *players, int size)
{   

    for (int i = 0; i < size; i++)
    {
        struct player *current = players + i;
        current->batting_average = (float)current->hits / current->atbat;
        printf("%d %s %s %d %d %d %d %.2f\n", current->number, current->firstname,
               current->lastname, current->atbat, current->hits,
               current->walks, current->rbis, current->batting_average);
    }
}

int main(void)
{
    FILE *fp = fopen("baseball.txt", "r");
    if (fp == NULL)
    {
        printf("File open failed!\n");
    }
    struct player players[MAX_LEN] = {
        {0, "", "", 0, 0, 0, 0},
        {1, "", "", 0, 0, 0, 0},
        {2, "", "", 0, 0, 0, 0},
        {3, "", "", 0, 0, 0, 0},
        {4, "", "", 0, 0, 0, 0},
        {5, "", "", 0, 0, 0, 0},
        {6, "", "", 0, 0, 0, 0},
        {7, "", "", 0, 0, 0, 0},
        {8, "", "", 0, 0, 0, 0},
        {9, "", "", 0, 0, 0, 0},
        {10, "", "", 0, 0, 0, 0},
        {11, "", "", 0, 0, 0, 0},
        {12, "", "", 0, 0, 0, 0},
        {13, "", "", 0, 0, 0, 0},
        {14, "", "", 0, 0, 0, 0},
        {15, "", "", 0, 0, 0, 0},
        {16, "", "", 0, 0, 0, 0},
        {17, "", "", 0, 0, 0, 0},
        {18, "", "", 0, 0, 0, 0}};

    int number;
    char firstname[20];
    char lastname[20];
    int atbat, hits, walks, rbis;

    while (fscanf(fp, "%d %s %s %d %d %d %d", &number, &firstname, &lastname, &atbat, &hits, &walks, &rbis) != EOF)
    {
        if (number > MAX_LEN || number < 0)
        {
            printf("Play number %d is out of range, ignore it!\n", number);
            continue;
        }
        if (strcmp(players[number].firstname, "") == 0)
        {
            strcpy(players[number].firstname, firstname);
            strcpy(players[number].lastname, lastname);
        }
        players[number].atbat += atbat;
        players[number].hits += hits;
        players[number].walks += walks;
        players[number].rbis += rbis;
    }
    fclose(fp);
    
    printf("Show players info:\n");
    show_info(players, MAX_LEN);
}