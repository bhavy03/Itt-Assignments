#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

typedef struct
{
    int id;
    char fname[100];
    char lname[100];
    int age;
} User;

void initializeFile()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        file = fopen(FILENAME, "a");
        printf("File has been created. \n");
    }
    fclose(file);
}

void addUser()
{
    User user;
    int id, found = 0;

    // first opening in read mode to check if the id is unique or not
    FILE *file = fopen(FILENAME, "r");

    printf("Enter User ID: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %d", &user.id, user.fname, user.lname, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            printf("User ID already exists. Please enter a new one.\n");
            break;
        }
    }

    if (found)
    {
        fclose(file);
        return;
    }
    fclose(file);

    // if new user id then append the user
    file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    user.id = id;
    getchar();
    printf("Enter First Name: ");
    fgets(user.fname, 100, stdin);
    user.fname[strcspn(user.fname, "\n")] = '\0';

    printf("Enter Last Name: ");
    fgets(user.lname, 100, stdin);
    user.lname[strcspn(user.lname, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &user.age);
    fprintf(file, "%d %s %s %d\n", user.id, user.fname, user.lname, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

void displayUsers()
{
    FILE *file = fopen(FILENAME, "r");
    User user;

    printf("\nAll Users:\n");
    printf("ID\tName\t\t\t\t\tAge\n");
    printf("--------------------------------------------------------------------------\n");
    while (fscanf(file, "%d %s %s %d", &user.id, user.fname, user.lname, &user.age) != EOF)
    {
        printf("%d\t%s %s\t\t\t\t%d\n", user.id, user.fname, user.lname, user.age);
    }

    fclose(file);
}

void updateUser()
{
    int id, found = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    printf("Enter User ID to update: ");
    scanf("%d", &id);
    getchar();

    while (fscanf(file, "%d %s %s %d", &user.id, user.fname, user.lname, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            printf("Enter new First Name: ");
            fgets(user.fname, 100, stdin);
            user.fname[strcspn(user.fname, "\n")] = '\0';
            printf("Enter new Last Name: ");
            fgets(user.lname, 100, stdin);
            user.lname[strcspn(user.lname, "\n")] = '\0';
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(tempFile, "%d %s %s %d\n", user.id, user.fname, user.lname, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User updated successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

void deleteUser()
{
    int id, found = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %d", &user.id, user.fname, user.lname, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d %s %s %d\n", user.id, user.fname, user.lname, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User deleted successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

int main()
{
    int choice;
    initializeFile();

    do
    {
        printf("\nUser Management System\n");
        printf("1. Add a new user\n");
        printf("2. Display all users\n");
        printf("3. Update a user by ID\n");
        printf("4. Delete a user by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addUser();
            break;
        case 2:
            displayUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}