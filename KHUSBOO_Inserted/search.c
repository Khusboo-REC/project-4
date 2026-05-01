#include "inverted_Search.h"

int search(Wlist *head[], char *word)
{
    // Clean the search word
    char clean_word[WORD_SIZE];
    int j = 0;
    for(int i = 0; word[i] && i < WORD_SIZE-1; i++)
    {
        if(isalpha(word[i]))
        {
            clean_word[j++] = tolower(word[i]);
        }
    }
    clean_word[j] = '\0';
    
    if(j == 0)
    {
        printf("Invalid search word\n");
        return FAILURE;
    }
    
    int index = hash_function(clean_word);
    Wlist *temp = head[index];

    while(temp)
    {
        if(strcmp(temp->word, clean_word) == 0)
        {
            printf("Word '%s' found in %d file(s):\n", 
                   temp->word, temp->file_count);
            
            Ltable *l_temp = temp->Tlink;
            while(l_temp)
            {
                printf("   → %s (%d occurrences)\n", 
                       l_temp->file_name, l_temp->word_count);
                l_temp = l_temp->table_link;
            }
            return SUCCESS;
        }
        temp = temp->link;
    }

    printf("Word '%s' not found in database\n", clean_word);
    return FAILURE;
}