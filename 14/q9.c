/*
Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands
its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to
handle four flights. Have a top-level menu that offers a choice of flights and the option
to quit. Selecting a particular flight should then bring up a menu similar to that of
exercise 8. However, one new item should be added: confirming a seat assignment. Also,
the quit choice should be replaced with the choice of exiting to the top-level menu. Each
display should indicate which flight is currently being handled. Also, the seat assignment
display should indicate the confirmation status.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SEATS 12
#define MAX_NAME 20

enum fnum
{
    LINE1 = 1,
    LINE2,
    LINE3,
    LINE4
};
#define ALL_SEATS LINE4 *MAX_SEATS

// struct 结构体
struct seat
{
    enum fnum flight;
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
    int flight = 0;
    for (int i = 0; i < ALL_SEATS; i++)
    {
        flight = i / 12 + 1;
        struct seat *current = seats + i;
        current->flight = flight;
        current->seat_num = i + 1 - (flight - 1) * MAX_SEATS;
        current->assigned = 0;
        strcpy(current->first_name, "");
        strcpy(current->last_name, "");
    }
}
int read_seat_record(struct seat *seats)
{
    FILE *fp;
    char filename[20] = "flight-seats.txt";
    if ((fp = fopen(filename, "r")) == NULL)
    {
        return -1;
    }
    fread(seats, sizeof(struct seat), ALL_SEATS, fp);
    fclose(fp);
    return 0;
}

int save_seat_record(struct seat *seats)
{
    FILE *fp;
    char filename[20] = "flight-seats.txt";
    if ((fp = fopen(filename, "w")) == NULL)
        return -1;
    fwrite(seats, sizeof(struct seat), ALL_SEATS, fp);
    puts("Already saved data to file");
    fclose(fp);
    return 0;
}

int show_empty_counts(struct seat seats[], enum fnum flight)
{
    int res = MAX_SEATS;
    for (int i = 0; i < ALL_SEATS; i++)
    {
        if ((seats[i].flight == flight) && seats[i].assigned)
        {
            res--;
        }
    }
    return res;
}

void show_empty_list(struct seat seats[], enum fnum flight)
{
    for (int i = 0; i < ALL_SEATS; i++)
    {
        if ((seats[i].flight == flight) && !seats[i].assigned)
        {
            printf("Flight %d seat %d is empty\n", flight, seats[i].seat_num);
        }
    }
}

int sort_seats(struct seat *seats, enum fnum flight)
{
    printf("Seats before sorting\n");
    for (int i = 0; i < ALL_SEATS; ++i)
    {
        if (seats[i].flight == flight)
            printf("Flight %d %d %d %s %s\n", flight, seats[i].seat_num, seats[i].assigned, seats[i].first_name, seats[i].last_name);
    }
    for (int i = 0; i < ALL_SEATS; ++i)
    {
        for (int j = i + 1; j < ALL_SEATS; ++j)
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

    for (int i = 0; i < ALL_SEATS; ++i)
    {
        if (seats[i].flight == flight)
            printf("Flight %d %d %d %s %s\n", flight, seats[i].seat_num, seats[i].assigned, seats[i].first_name, seats[i].last_name);
    }

    return 0;
}

int choice_seats(struct seat *seats, enum fnum flight)
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
    for (i = 0; i < ALL_SEATS; i++)
    {
        if ((seats[i].seat_num == num) && (seats[i].flight == flight))
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

int delete_seat(struct seat *seats, enum fnum flight)
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
    for (i = 0; i < ALL_SEATS; i++)
    {
        if (seats[i].seat_num == num && (seats[i].flight == flight))
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

void print_flight_menu(void)
{
    puts("-------------Flight memu-------------");
    puts("a) Chooice a flight, avalible flight: 1,2,3,4");
    puts("b) Go to seat menu");
    puts("c) Quit");
}

void print_seat_menu(enum fnum flight)
{
    puts("-------------Seat memu-------------");
    printf("-------------Flight %d--------------\n", flight);
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Got to flight menu");
}

int choice_flights(int *flight)
{
    puts("Enter flight number:(1-4) ");
    scanf("%d", flight);
    while (getchar() != '\n')
    {
        continue;
    }
    if (*flight > LINE4 || *flight < LINE1)
    {
        printf("Invalid choice, please choose a number between 1-4 \n");
    }
    return -1;
    return 0;
}

int flight_operation()
{
    // 输出航班菜单
    print_flight_menu();
    int flight = 0;
    char f_choice;
    scanf("%c", &f_choice);
    while (1)
    {
        while (getchar() != '\n')
        {
            continue;
        }
        switch (f_choice)
        {
        case 'a':
            // 接收用户输入航班号
            choice_flights(&flight);
            break;
        case 'b':
            if (flight <= 0)
            {
                printf("Please choose a flight first \n");
            }
            else
            {
                printf("Now goting to seat menu \n");
                printf("Flight num is: %d \n", flight);
                goto seat_menu;
            }
            break;
        case 'c':
            printf("Quit program \n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        print_flight_menu();
        scanf("%c", &f_choice);
    }

seat_menu:
    return flight;
}

// main()主函数
int main(int argc, char *argv[])
{
    int flight = 0;
    flight = flight_operation();

    // 输出选座菜单
    print_seat_menu(flight);

    // 为航班定义结构体数组，每个元素为12个结构体
    struct seat seats[ALL_SEATS];
    if (read_seat_record(seats) != 0)
    {
        printf("Flight %d: can not read seat record from file, initing it \n", flight);
        init_seat_record(seats);
    };

    // 定义指针变量，用于接收用户输入
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
            printf("empty seats: %d \n", show_empty_counts(seats, flight));
            break;
        case 'b':
            show_empty_list(seats, flight);
            break;
        case 'c':
            sort_seats(seats, flight);
            break;
        case 'd':
            choice_seats(seats, flight);
            break;
        case 'e':
            delete_seat(seats, flight);
            break;
        case 'f':
            // 保存数据到文件
            save_seat_record(seats);
            printf("Now going to flight menu\n");
            flight = flight_operation();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        // 重新输入用户选择
        print_seat_menu(flight);
        scanf("%c", &choice);
    }

    return 0;
}