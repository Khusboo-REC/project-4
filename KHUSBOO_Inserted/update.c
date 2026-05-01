#include "inverted_Search.h"

int update_database(Wlist *head[], Flist **f_head)
{
    char filename[FNAME_SIZE];
    printf("Enter the filename to update: ");
    scanf("%s", filename);
    
    // Check if file exists and is not empty
    int ret = isFileEmpty(filename);
    if(ret == FILE_NOTAVAILABLE)
    {
        printf("File %s is not available\n", filename);
        return FAILURE;
    }
    else if(ret == FILE_EMPTY)
    {
        printf("File %s is empty\n", filename);
        return FAILURE;
    }
    
    // Check for duplicates in file list
    Flist *temp = *f_head;
    while(temp)
    {
        if(strcmp(temp->file_name, filename) == 0)
        {
            printf("File %s already exists in database\n", filename);
            return FAILURE;
        }
        temp = temp->link;
    }
    
    // Add file to file linked list
    ret = to_create_list_of_files(f_head, filename);
    if(ret == SUCCESS)
    {
        printf("File %s added to file list\n", filename);
        
        // Process the new file and update database
        Flist *new_file = *f_head;
        while(new_file->link)
            new_file = new_file->link;
            
        read_datafile(new_file, head, filename);
        printf("Database updated successfully with %s\n", filename);
        return SUCCESS;
    }
    
    return FAILURE;
}