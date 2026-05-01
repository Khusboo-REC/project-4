#include "inverted_Search.h"

int update_word_count(Wlist **head, char *word, char *file_name)
{
    // Remove all DEBUG prints, keep only the logic
    if(head == NULL)
        return FAILURE;
    
    // Convert word to lowercase for consistency
    for(int i = 0; word[i]; i++)
        word[i] = tolower(word[i]);
    
    Wlist *temp = *head;
    
    // Search for the word in the main list
    while(temp)
    {
        if(strcmp(temp->word, word) == 0)
        {
            // Word found, now check if this file already exists in link table
            Ltable *l_temp = temp->Tlink;
            
            while(l_temp)
            {
                if(strcmp(l_temp->file_name, file_name) == 0)
                {
                    // File already exists, increment word count for this file
                    l_temp->word_count++;
                    return SUCCESS;
                }
                l_temp = l_temp->table_link;
            }
            
            // File not found in link table, create new entry
            Ltable *new_link = malloc(sizeof(Ltable));
            if(!new_link)
                return FAILURE;
            
            strcpy(new_link->file_name, file_name);
            new_link->word_count = 1;
            new_link->table_link = NULL;
            
            // Add to link table (at the end)
            if(temp->Tlink == NULL)
            {
                temp->Tlink = new_link;
            }
            else
            {
                l_temp = temp->Tlink;
                while(l_temp->table_link)
                    l_temp = l_temp->table_link;
                l_temp->table_link = new_link;
            }
            
            // Increment file count for this word
            temp->file_count++;
            
            return SUCCESS;
        }
        temp = temp->link;
    }
    
    // Word not found, create new word node
    Wlist *new_word = malloc(sizeof(Wlist));
    if(!new_word)
        return FAILURE;
    
    strcpy(new_word->word, word);
    new_word->file_count = 1;
    new_word->Tlink = NULL;
    new_word->link = NULL;
    
    // Create link table for this word
    Ltable *new_link = malloc(sizeof(Ltable));
    if(!new_link)
    {
        free(new_word);
        return FAILURE;
    }
    
    strcpy(new_link->file_name, file_name);
    new_link->word_count = 1;
    new_link->table_link = NULL;
    new_word->Tlink = new_link;
    
    // Add to the list
    if(*head == NULL)
    {
        *head = new_word;
    }
    else
    {
        temp = *head;
        while(temp->link)
            temp = temp->link;
        temp->link = new_word;
    }
    
    return SUCCESS;
}