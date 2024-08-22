// Modify Listing 14.14 so that as each record is read from the file and shown to you, you
// are given the chance to delete the record or to modify its contents. If you delete the
// record, use the vacated array position for the next record to be read. To allow changing
// the existing contents, you’ll need to use the "r+b" mode instead of the "a+b" mode, and
// you’ll have to pay more attention to positioning the file pointer so that appended records
// don’t overwrite existing records. It’s simplest to make all changes in the data stored in
// program memory and then write the final set of information to the file. One approach to
// keeping track is to add a member to the book structure that indicates whether it is to be
// deleted

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

// ------- modified program -----------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */
char *s_gets(char *st, int n);
struct book
{
    int num;
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{

    struct book library[MAXBKS];
    int count = 0;
    FILE *fpbooks;
    int size = sizeof(struct book);
    if ((fpbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    // read existing book records
    rewind(fpbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, fpbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("book num: %d %s by %s: $%.2f\n", library[count].num, library[count].title, library[count].author, library[count].value);
        count++;
    }

    // add new book
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    puts("Please add new book titles.");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        library[count].num = count;
        while (getchar() != '\n')
            continue; /* clear input line */
        count++;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    // show book records
    printf("Here is the list of books:\n");
    for (int i = 0; i < count; i++)
    {
        printf("book num: %d %s by %s: $%.2f\n", library[i].num, library[i].title, library[i].author, library[i].value);
    }

    // delete book records
    struct book final_books[MAXBKS];
    int delete_num = -1;
    printf("Enter the book number to delete (-1 quit): ");
    scanf("%d", &delete_num);

    while (delete_num < count && delete_num >= 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (library[i].num == delete_num)
            {
                library[i].num = -1;
            }
        }
        while (getchar() != '\n')
            continue;
        puts("Enter the book number to delete (-1 quit).");
        scanf("%d", &delete_num);
    }

    printf("Here is the final list of books:\n");
    int keep = 0;
    for (int i = 0; i < count; i++)
    {
        if (library[i].num != -1)
        {
            final_books[keep] = library[i];
            final_books[keep].num = keep;
            printf("book num: %d %s by %s: $%.2f\n", final_books[keep].num, final_books[keep].title,
                   final_books[keep].author, final_books[keep].value);
            keep++;
        }
    }

    // write book records
    rewind(fpbooks);
    fwrite(final_books, size, keep, fpbooks);
    // 截断去掉多余的记录
    ftruncate(fileno(fpbooks), keep * size);
    fclose(fpbooks);
}

// --------- original listing 14.14 ---------
/* booksave.c -- saves structure contents in a file */
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAXTITL 40
// #define MAXAUTL 40
// #define MAXBKS 10 /* maximum number of books */
// char *s_gets(char *st, int n);
// struct book
// { /* set up book template */
//     char title[MAXTITL];
//     char author[MAXAUTL];
//     float value;
// };
// int main(void)
// {
//     struct book library[MAXBKS]; /* array of structures */
//     int count = 0;
//     int keep, filecount;
//     FILE *fpbooks;
//     int size = sizeof(struct book);
//     if ((fpbooks = fopen("book.dat", "a+b")) == NULL)
//     {
//         fputs("Can't open book.dat file\n", stderr);
//         exit(1);
//     }
//     rewind(fpbooks); /* go to start of file */
//     while (count < MAXBKS && fread(&library[count], size,
//                                    1, fpbooks) == 1)
//     {
//         if (count == 0)
//             puts("Current contents of book.dat:");
//         printf("%s by %s: $%.2f\n", library[count].title,
//                library[count].author, library[count].value);
//         count++;
//     }
//     filecount = count;
//     if (count == MAXBKS)
//     {
//         fputs("The book.dat file is full.", stderr);
//         exit(2);
//     }
//     puts("Please add new book titles.");
//     puts("Press [enter] at the start of a line to stop.");
//     while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
//     {
//         puts("Now enter the author.");
//         s_gets(library[count].author, MAXAUTL);
//         puts("Now enter the value.");
//         scanf("%f", &library[count++].value);
//         while (getchar() != '\n')
//             continue; /* clear input line */
//         if (count < MAXBKS)
//             puts("Enter the next title.");
//     }
//     if (count > 0)
//     {
//         puts("Here is the list of your books:");
//         for (keep = 0; keep < count; keep++)
//             printf("%s by %s: $%.2f\n", library[keep].title,
//                    library[keep].author, library[keep].value);
//         fwrite(&library[filecount], size, count - filecount,
//                fpbooks);
//     }
//     else
//         puts("No books? Too bad.\n");
//     puts("Bye.\n");
//     fclose(fpbooks);
//     return 0;
// }
