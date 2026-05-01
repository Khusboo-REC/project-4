#include "inverted_Search.h"

int save_database(Wlist *head[])
{
    char filename[50];
    printf("Enter filename to save database: ");
    scanf("%s", filename);
    
    FILE *fptr = fopen(filename, "w");
    if(!fptr)
    {
        printf("Error: Cannot create file\n");
        return FAILURE;
    }

    // Write header with format information
    fprintf(fptr, "# Inverted Index Database\n");
    fprintf(fptr, "# Format: [index]:word:file_count\n");
    fprintf(fptr, "#         filename:word_count\n\n");

    // Traverse all 27 indices (0-25 for a-z, 26 for non-alphabetic)
    for(int i = 0; i < 27; i++)
    {
        Wlist *temp = head[i];
        
        while(temp != NULL)
        {
            // Save the word entry with its index
            fprintf(fptr, "[%d]:%s:%d\n", i, temp->word, temp->file_count);
            
            // Save all files containing this word
            Ltable *l_temp = temp->Tlink;
            while(l_temp != NULL)
            {
                fprintf(fptr, "    %s:%d\n", l_temp->file_name, l_temp->word_count);
                l_temp = l_temp->table_link;
            }
            
            temp = temp->link;
        }
    }

    fclose(fptr);
    printf("Database saved to '%s' successfully\n", filename);
    printf("Total words saved with their file associations\n");
    
    return SUCCESS;
}