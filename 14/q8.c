/*
 The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes
one flight daily. Write a seating reservation program with the following features:
 a. The program uses an array of 12 structures. Each structure should hold a seat
identification number, a marker that indicates whether the seat is assigned, the last
name of the seat holder, and the first name of the seat holder.
 b. The program displays the following menu:
    To choose a function, enter its letter label:
    a) Show number of empty seats
    b) Show list of empty seats
    c) Show alphabetical list of seats
    d) Assign a customer to a seat assignment
    e) Delete a seat assignment
    f) Quit
 c. The program successfully executes the promises of its menu. Choices d) and e)
require additional input, and each should enable the user to abort an entry.
 d. After executing a particular function, the program shows the menu again, except
for choice f) .
 e. Data is saved in a file between runs. When the program is restarted, it first loads in
the data, if any, from the file.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SEATS 12
#define MAX_NAME 20

// struct 结构体
struct seat
{
    int seat_num;
    int assigned;
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
};

// s_gets()输入字符串，遇到空格或回车结束
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find)                // if the address is not NULL,
            *find = '\0';        // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}

// 初始化座位记录
void init_seat_record(struct seat *seats)
{
    // 初始化座位记录
    for (int i = 0; i < MAX_SEATS; i++)
    {
        struct seat *current = seats + i;
        current->seat_num = i + 1;
        current->assigned = 0;
        strcpy(current->first_name, "");
        strcpy(current->last_name, "");
    }
}
int read_seat_record(struct seat *seats)
{
    FILE *fp;
    if ((fp = fopen("seat_record.txt", "r")) == NULL)
    {
        return -1;
    }
    fread(seats, sizeof(struct seat), MAX_SEATS, fp);
    fclose(fp);
    return 0;
}

int save_seat_record(struct seat *seats)
{
    FILE *fp;
    if ((fp = fopen("seat_record.txt", "w")) == NULL)
        return -1;
    fwrite(seats, sizeof(struct seat), MAX_SEATS, fp);
    puts("already saved");
    fclose(fp);
    return 0;
}

int show_empty_counts(struct seat seats[])
{
    int res = MAX_SEATS;
    for (int i = 0; i < MAX_SEATS; i++)
    {
        if (seats[i].assigned)
        {
            res--;
        }
    }
    return res;
}

void show_empty_list(struct seat seats[])
{
    for (int i = 0; i < MAX_SEATS; i++)
    {
        if (!seats[i].assigned)
        {
            printf("seat %d is empty\n", seats[i].seat_num);
        }
    }
}

int sort_seats(struct seat *seats)
{
    printf("Seats before sorting\n");
    for (int i = 0; i < MAX_SEATS; ++i)
    {
        printf("%d %d %s %s\n", seats[i].seat_num, seats[i].assigned, seats[i].first_name, seats[i].last_name);
    }
    for (int i = 0; i < MAX_SEATS - 1; ++i)
    {
        for (int j = i + 1; j < MAX_SEATS; ++j)
        {
            if (strcmp(seats[i].first_name, seats[j].first_name) > 0)
            {
                struct seat temp = seats[i];
                seats[i] = seats[j];
                seats[j] = temp;
            }
        }
    }
    printf("Seats sorted by first name\n");

    for (int i = 0; i < MAX_SEATS; ++i)
    {
        printf("%d %d %s %s\n", seats[i].seat_num, seats[i].assigned, seats[i].first_name, seats[i].last_name);
    }

    return 0;
}

int choice_seats(struct seat *seats)
{

    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    int num = -1;
    puts("Enter first name: ");
    s_gets(first_name, MAX_NAME);
    puts("Enter last name: ");
    s_gets(last_name, MAX_NAME);
    puts("Enter seat number: ");
    scanf("%d", &num);
    while (getchar() != '\n')
    {
        continue;
    }

    if (num > MAX_SEATS || num <= 0)
    {
        printf("Invalid choice, seat num must be 1-12 \n");
        return -1;
    }
    // 查找要分配的座位
    int i = 0;
    for (i = 0; i < MAX_SEATS; i++)
    {
        if (seats[i].seat_num == num)
        {
            break;
        }
    }

    if (seats[i].assigned)
    {
        printf("Seat %d is already assigned\n", num);
        return -1;
    }
    seats[i].assigned = 1;
    strcpy(seats[i].first_name, first_name);
    strcpy(seats[i].last_name, last_name);

    return 0;
}

int delete_seat(struct seat *seats)
{
    puts("Enter seat number: ");
    int num = -1;
    scanf("%d", &num);
    while (getchar() != '\n')
    {
        continue;
    }
    if (num > MAX_SEATS || num <= 0)
    {
        printf("Invalid choice, seat num must be 1-12 \n");
        return -1;
    }

    // 查找要删除的座位
    int i = 0;
    for (i = 0; i < MAX_SEATS; i++)
    {
        if (seats[i].seat_num == num)
        {
            break;
        }
    }

    if (seats[i].assigned == 0)
    {
        printf("Seat %d is not assigned\n", num);
        return -1;
    }
    seats[i].assigned = 0;
    strcpy(seats[i].first_name, "");
    strcpy(seats[i].last_name, "");

    return 0;
}

// main()主函数
int main(int argc, char *argv[])
{
    // 程序输出菜单
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");

    // 定义结构体数组，每个元素为12个结构体
    struct seat seats[MAX_SEATS];
    if (read_seat_record(seats) != 0)
    {
        printf("Can not read seat record from file, initing it \n");
        init_seat_record(seats);
    };

    // 定义指针变量，用于接收用户输入
    puts("Enter your choice: ");
    char choice;
    scanf("%c", &choice);
    while (1)
    {
        while (getchar() != '\n')
        {
            continue;
        }
        switch (choice)
        {
        case 'a':
            printf("empty seats: %d \n", show_empty_counts(seats));
            break;
        case 'b':
            show_empty_list(seats);
            break;
        case 'c':
            sort_seats(seats);
            break;
        case 'd':
            choice_seats(seats);
            break;
        case 'e':
            delete_seat(seats);
            break;
        case 'f':
            printf("quit program \n");
            // 保存数据到文件
            save_seat_record(seats);
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }

        // 重新输入用户选择
        puts("Enter your choice: ");
        puts("a) Show number of empty seats");
        puts("b) Show list of empty seats");
        puts("c) Show alphabetical list of seats");
        puts("d) Assign a customer to a seat assignment");
        puts("e) Delete a seat assignment");
        puts("f) Quit");
        scanf("%c", &choice);
    }

    return 0;
}