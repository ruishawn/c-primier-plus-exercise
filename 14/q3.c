// Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in
// the order entered, then alphabetized by title, and then in order of increased value.

#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
            {
                continue;
            }
    }
    return ret_val;
}

void sort_book_by_title(struct book *p, int n)
{
    int i, j;
    struct book temp;
    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
            if (strcmp(p[i].title, p[j].title) > 0)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

void sort_book_by_price(struct book *p, int n)
{
    int i, j;
    struct book temp;
    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
            if (p[i].value > p[j].value)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

void print_book_info(const struct book library[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
    }
}

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    printf("Here is the list of your books:\n");
    print_book_info(library, count);

    printf("Now sort the list by title.\n");
    sort_book_by_title(library, count);
    print_book_info(library, count);

    printf("Now sort by price:\n");
    sort_book_by_price(library, count);
    print_book_info(library, count);

    return 0;
}