#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "library.dat"

struct library
{
    char bookName[100];
    char authorName[100];
    int publicationYear;
    int pages;
    float price;
};

void printBook(struct library *book, int index)
{
    printf("\n--- Book %d ---\n", index);
    printf("Name   : %s\n", book->bookName);
    printf("Author : %s\n", book->authorName);
    printf("Year   : %d\n", book->publicationYear);
    printf("Pages  : %d\n", book->pages);
    printf("Price  : %.2f\n", book->price);
}

int countBooks()
{
    FILE *f = fopen(FILENAME, "rb");

    if (f == NULL)
        return 0;

    fseek(f, 0, SEEK_END);

    long bytes = ftell(f);

    fclose(f);

    return bytes / sizeof(struct library);
}

void addBook()
{
    int n;

    printf("How many books do you want to add? ");

    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input!\n");

        while (getchar() != '\n');

    return;
    }

    getchar();

    FILE *f = fopen(FILENAME, "ab");

    if (f == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        
        struct library book;

        printf("\nEnter name of book %d: ", i + 1);
        fgets(book.bookName, sizeof(book.bookName), stdin);
        book.bookName[strcspn(book.bookName, "\n")] = '\0';

        printf("Enter author of book %d: ", i + 1);
        fgets(book.authorName, sizeof(book.authorName), stdin);
        book.authorName[strcspn(book.authorName, "\n")] = '\0';

        printf("Enter publication year of book %d: ", i + 1);
        scanf("%d", &book.publicationYear);

        printf("Enter number of pages of book %d: ", i + 1);
        scanf("%d", &book.pages);

        printf("Enter price of book %d: ", i + 1);
        scanf("%f", &book.price);

        getchar();

        fwrite(&book, sizeof(struct library), 1, f);
    }

    fclose(f);

    printf("\n%d book(s) added successfully!\n", n);
}

struct library *loadBooks(int *count)
{
    *count = countBooks();

    if (*count == 0)
        return NULL;

    FILE *f = fopen(FILENAME, "rb");

    if (f == NULL)
    {
        *count = 0;
        return NULL;
    }

    struct library *books =
        malloc(*count * sizeof(struct library));

    if (books == NULL)
    {
        printf("Memory allocation failed!\n");
        fclose(f);

        *count = 0;

        return NULL;
    }

    fread(books, sizeof(struct library), *count, f);

    fclose(f);

    return books;
}

void viewBooks()
{
    int count;

    struct library *books = loadBooks(&count);

    if (count == 0)
    {
        printf("No books in the library yet.\n");
        return;
    }

    printf("\nList of books in the library:\n");

    for (int i = 0; i < count; i++)
    {
        printBook(&books[i], i + 1);
    }

    free(books);
}

void searchByName()
{
    char searchName[100];

    printf("Enter the book name to search: ");

    getchar();

    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int count;

    struct library *books = loadBooks(&count);

    if (count == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].bookName, searchName) == 0)
        {
            printBook(&books[i], i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("No book found with that name.\n");

    free(books);
}

void searchByAuthor()
{
    char searchAuthor[100];

    printf("Enter the author name to search: ");

    getchar();

    fgets(searchAuthor, sizeof(searchAuthor), stdin);
    searchAuthor[strcspn(searchAuthor, "\n")] = '\0';

    int count;

    struct library *books = loadBooks(&count);

    if (count == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].authorName, searchAuthor) == 0)
        {
            printBook(&books[i], i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("No book found by that author.\n");

    free(books);
}

void searchByYear()
{
    int searchYear;

    printf("Enter the publication year to search: ");
    scanf("%d", &searchYear);

    int count;

    struct library *books = loadBooks(&count);

    if (count == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (books[i].publicationYear == searchYear)
        {
            printBook(&books[i], i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("No book found from that year.\n");

    free(books);
}

void searchByPriceRange()
{
    float minPrice;
    float maxPrice;

    printf("Enter minimum price: ");
    scanf("%f", &minPrice);

    printf("Enter maximum price: ");
    scanf("%f", &maxPrice);

    int count;

    struct library *books = loadBooks(&count);

    if (count == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (books[i].price >= minPrice &&
            books[i].price <= maxPrice)
        {
            printBook(&books[i], i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("No book found in that price range.\n");

    free(books);
}

void totalBooks()
{
    printf(
        "Total number of books in the library: %d\n",
        countBooks());
}

void printMenu()
{
    printf("\n========================================\n");
    printf("      Library Management System\n");
    printf("========================================\n");
    printf("1 - Add a new book\n");
    printf("2 - View all books\n");
    printf("3 - Search by name\n");
    printf("4 - Search by author\n");
    printf("5 - Search by publication year\n");
    printf("6 - Search by price range\n");
    printf("7 - Total number of books\n");
    printf("0 - Exit\n");
    printf("Your choice: ");
}

int main()
{
    int choice;

    do
    {
        printMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            viewBooks();
            break;

        case 3:
            searchByName();
            break;

        case 4:
            searchByAuthor();
            break;

        case 5:
            searchByYear();
            break;

        case 6:
            searchByPriceRange();
            break;

        case 7:
            totalBooks();
            break;

        case 0:
            printf("\nExiting the program...\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
