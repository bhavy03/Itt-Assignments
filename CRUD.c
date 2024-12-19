#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

typedef struct
{
    int id;
    char name[100];
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

    FILE *file = fopen(FILENAME, "r");

    printf("Enter User ID: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
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

    file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    user.id = id;
    getchar();
    printf("Enter Name: ");
    fgets(user.name, 100, stdin);
    for (int i = 0; user.name[i] != '\0'; i++)
    {
        if (user.name[i] == '\n')
        {
            user.name[i] = '\0';
            break;
        }
    }

    printf("Enter Age: ");
    scanf("%d", &user.age);
    fprintf(file, "%d\t%s\t%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

void displayUsers()
{
    FILE *file = fopen(FILENAME, "r");
    User user;

    int foundUser = 0;
    printf("\n--- User List ---\n");
    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
    {
        foundUser = 1;
        printf("{\n");
        printf("    User ID: %d\n", user.id);
        printf("    Name: %s \n", user.name);
        printf("    Age: %d\n", user.age);
        printf("}\n");
    }
    if (!foundUser)
    {
        printf("No user found  \n");
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

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            printf("Enter new Name: ");
            fgets(user.name, 100, stdin);
            for (int i = 0; user.name[i] != '\0'; i++)
            {
                if (user.name[i] == '\n')
                {
                    user.name[i] = '\0';
                    break;
                }
            }
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(tempFile, "%d\t%s\t%d\n", user.id, user.name, user.age);
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

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d\t%s\t%d\n", user.id, user.name, user.age);
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