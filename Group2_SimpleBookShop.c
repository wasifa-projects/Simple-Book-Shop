#include<stdio.h>
#include<string.h>


struct library
{
    char title[50];
    char author_name[30];
    float price;
    int copies;

};

struct library book[50];




void showWelcomeMessage()
{
    printf("                             ************************************************************\n");
    printf("\n");
    printf("                                      Welcome to Simple Book Management System\n");
    printf("\n");
    printf("                             ************************************************************\n");
    printf("\n");

}
void showGoodByeMessage()
{
    printf("                             ************************************************************\n");
    printf("\n");
    printf("                                   Thank you for using Simple Book Management System\n");
    printf("\n");
    printf("                             ************************************************************\n");

}



void showBooks( int index)
{
    printf("\nList of books:\n\n");
    for(int i=0; i<index; i++)
    {
        printf("\nBook title: %s",book[i].title);
        printf("\nBook author: %s",book[i].author_name);
        printf("\nBook price: %f",book[i].price);
        printf("\nBook copies: %d\n",book[i].copies);

    }
}

void addBook(int index)
{
    getchar();
    printf("\nEnter book title: ");
    gets(book[index].title);

    printf("Enter book author: ");
    gets(book[index].author_name);

    printf("Enter book price: ");
    scanf("%f", &book[index].price);

    printf("Enter number of copies: ");
    scanf("%d", &book[index].copies);
    printf("\n");
}

void searchBook(int index)
{
    printf("\nEnter book title to search: ");
    getchar();
    char titlename[50];
    gets(titlename);

    int flag; ///flag used for searching book

    for(int i=0; i<index; i++)
    {
        flag=0;
        for(int j=0; book[i].title[j]!='\0'; j++)
        {
            if(titlename[j]!=book[i].title[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("\n\nBook title: %s\n", book[i].title);
            printf("Book author: %s\n",book[i].author_name);
            printf("Book price: %f\n",book[i].price);
            printf("Book copies: %d\n",book[i].copies);
            printf("\n\n");
            break;
        }


    }
    if(flag==1)
    {
        printf("\nBook not found!!!\n");
    }


}

void showNumberOfBooks(int index)
{
    printf("\nTotal number of books in the shop: %d\n", index);

}

void showMenuOptions()
{
    int index=0;

    int option;
    do
    {
        printf("\n");
        printf("Please select a menu option number: \n");
        printf("1) Display this menu.\n");
        printf("2) Show all the available books.\n");
        printf("3) Add a book to the book shop.\n");
        printf("4) Search a book by title.\n");
        printf("5) Display the total number of books.\n");
        printf("6) Exit from the book shop system.\n");
        printf("\n");
        printf("\n");
        printf("\n");

        printf("\nEnter your choice: ");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
        {
            showMenuOptions();///calling menu options
            break;
        }

        case 2:
        {
            showBooks(index);///calling showing all books
            break;

        }

        case 3:
            addBook(index);///calling add book
            index++;
            break;

        case 4:
            searchBook(index);///calling book searching
            break;

        case 5:
            showNumberOfBooks(index);///calling total numbers of books
            break;

        case 6:
            showGoodByeMessage();///calling goodbye message
            break;

        default:
            printf("\nWrong input");///for wrong input
            printf("\nPlease Try again, Thank You\n");

        }

    }
    while(option!=6);
}

int main()
{
    showWelcomeMessage();///calling welcome message
    showMenuOptions(); ///calling menu options
}



