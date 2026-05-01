#include "inverted_Search.h"

int main(int argc, char *argv[])
{
    system("clear");

    // Validate CLA
    if(argc <= 1)
    {
        printf("Enter Valid files to proceed with further operation\n");
        printf("Input should be passed as ./a.out file1.txt file2.txt...\n");
        return 0;
    }

    // Create the file linked list
    Flist *f_head = NULL;

    // Validate files (availability, content, duplicates)
    file_validation_n_file_list(&f_head, argv);

    if(f_head == NULL)
    {
        printf("No files added to file linked list\n");
        printf("Hence process got terminated\n");
        return 1;
    }

    // Create hash table (26 for letters + 1 for non-alphabetic)
    Wlist *head[27] = {NULL};
    
    int choice;
    char word[WORD_SIZE];
    
    do
    {
        printf("\n1.Create Database\n");
        printf("2.Display Database\n");
        printf("3.Search Database\n");
        printf("4.Update Database\n");
        printf("5.Save Database\n");
        printf("6.Exit\n");
        printf("Enter a Choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                create_database(f_head, head);
                printf("Database created successfully!\n");
                break;
                
            case 2:
                display_database(head);
                break;
                
            case 3:
                printf("Enter the word to search: ");
                scanf("%s", word);
                search(head, word);  // Note: head is array, need to update search prototype
                break;
                
            case 4:
                update_database(head, &f_head);
                break;
                
            case 5:
                save_database(head);
                break;
                
            case 6:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}