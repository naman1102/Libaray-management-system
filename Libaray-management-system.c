#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Structure of the employee
struct emp
{
       char name[50];
       float isbn;
       char author[50];
       int id;
};
struct emp e;

// size of the structure
long int size = sizeof(e);

// In the start coordinates
// will be 0, 0
COORD cord = {0, 0};

// function to set the
// coordinates
void gotoxy(int x, int y)
{
       cord.X = x;
       cord.Y = y;
       SetConsoleCursorPosition(
           GetStdHandle(STD_OUTPUT_HANDLE),
           cord);
}

FILE *fp, *ft;

// Function to add the records
void addrecord()
{
       system("cls");
       fseek(fp, 0, SEEK_END);
       char another = 'y';

       while (another == 'y')
       {
              printf("\nEnter BOOK Name : ");
              scanf("%s", e.name);

              printf("\nEnter Author Name : ");
              scanf("%s", &e.author);

              printf("\nEnter ISBN-NO : ");
              scanf("%f", &e.isbn);

              printf("\nEnter ID : ");
              scanf("%d", &e.id);

              fwrite(&e, size, 1, fp);

              printf("\nWant to add another"
                     " record (Y/N) : ");
              fflush(stdin);

              scanf("%c", &another);
       }
}

// Function to delete the records
void deleterecord()
{
       system("cls");
       char empname[50];
       char another = 'y';

       while (another == 'y')
       {
              printf("\nEnter BOOK "
                     "name to delete : ");
              scanf("%s", empname);

              ft = fopen("temp.txt", "wb");
              rewind(fp);

              while (fread(&e, size,
                           1, fp) == 1)
              {
                     if (strcmp(e.name,
                                empname) != 0)
                            fwrite(&e, size, 1, ft);
              }

              fclose(fp);
              fclose(ft);
              remove("data.txt");
              rename("temp.txt", "data.txt");
              fp = fopen("data.txt", "rb+");

              printf("\nWant to delete another"
                     " record (Y/N) :");
              fflush(stdin);
              another = getchar();
       }
}

// Function to display the record
void displayrecord()
{
       system("cls");

       // sets pointer to start
       // of the file
       rewind(fp);

       printf("\n========================="
              "==========================="
              "======");
       printf("\nNAME\t\tAUTHOR\t\tISBN-NO\t\t"
              "\tID\n",
              e.name, e.author,
              e.isbn, e.id);
       printf("==========================="
              "==========================="
              "====\n");

       while (fread(&e, size, 1, fp) == 1)
              printf("\n%s\t\t%s\t\t%.2f\t%10d",
                     e.name, e.author, e.isbn, e.id);

       printf("\n\n\n\t");
       system("pause");
}



// Driver code
int main()
{
       int choice;

       // opening the file
       fp = fopen("data.txt", "rb+");

       // showing error if file is
       // unable to open.
       if (fp == NULL)
       {
              fp = fopen("data.txt", "wb+");
              if (fp == NULL)
              {
                     printf("\nCannot open file...");
                     exit(1);
              }
       }

       system("Color FF");
       printf("\n\n\n\n\t\t\t\t============="
              "============================="
              "=============================");
       printf("\n\t\t\t\t~~~~~~~~"
              "~~~~~~~~~~~~~~~~~~"
              "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
       printf("\n\t\t\t\t==================="
              "============================="
              "=======================");
       printf("\n\t\t\t\t[|:::>:::>:::>::>  "
              "LIBARAY MANAGEMENT SYSTEM  <::<:::<:::"
              "<:::|]\t");
       printf("\n\t\t\t\t===================="
              "=============================="
              "=====================");
       printf("\n\t\t\t\t~~~~~~~~"
              "~~~~~~~~~~~~~~~~~~"
              "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
       printf("\n\t\t\t\t========================="
              "==================================="
              "===========");
       printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
              "Developer : @Naman1102"
              "\n\n\t\t\t\t");

       system("pause");

       while (1)
       {
              // Clearing console and asking the
              // user for input
              system("cls");
              gotoxy(30, 10);
              printf("\n1. ADD BOOK\n");
              gotoxy(30, 12);
              printf("\n2. DELETE BOOK\n");
              gotoxy(30, 14);
              printf("\n3. DISPLAY BOOKS\n");
              gotoxy(30, 16);
              printf("\n4. EXIT\n");
              gotoxy(30, 20);
              printf("\nENTER YOUR CHOICE...\n");
              fflush(stdin);
              scanf("%d", &choice);

              // Switch Case
              switch (choice)
              {
              case 1:

                     // Add the records
                     addrecord();
                     break;

              case 2:

                     // Delete the records
                     deleterecord();
                     break;

              case 3:

                     // Display the records
                     displayrecord();
                     break;

              case 4:
                     fclose(fp);
                     exit(0);
                     break;

              default:
                     printf("\nINVALID CHOICE...\n");
              }
       }
       return 0;
}