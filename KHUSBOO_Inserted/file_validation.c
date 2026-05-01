#include "inverted_Search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File : %s is not available \n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File : %s is not having any content \n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head , argv[i]);

            if(ret_val == SUCCESS)
            {
                printf("Successfully inserted the file %s into file linked list\n", argv[i]);
            }
            else if(ret_val == REPEATATION )
            {
                printf("This file %s is repeated . Do not add that file to file linked list\n" , argv[i]);
            }
            else
            {
                printf("Failure\n");
            }
            i++;
            continue;
        }
    }
}

// Function to check file availability and file contents
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }
    
    fseek(fptr , 0 , SEEK_END);
    if(ftell(fptr) == 0)
    {
        fclose(fptr);
        return FILE_EMPTY;
    }
    
    fclose(fptr);
    return SUCCESS;
}

// Function to create file linked list (insert at end) and check for duplicates
int to_create_list_of_files(Flist **f_head, char *name)
{
    // Check for duplicate files
    Flist *temp = *f_head;
    while(temp != NULL)
    {
        if(strcmp(temp->file_name, name) == 0)
        {
            return REPEATATION;  // Duplicate file found
        }
        temp = temp->link;
    }
    
    // Create new node
    Flist *new_node = (Flist*)malloc(sizeof(Flist));
    if(new_node == NULL)
    {
        return FAILURE;
    }
    
    strcpy(new_node->file_name, name);
    new_node->link = NULL;
    
    // Insert at the end of linked list
    if(*f_head == NULL)
    {
        // First node
        *f_head = new_node;
    }
    else
    {
        temp = *f_head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
    }
    
    return SUCCESS;
}