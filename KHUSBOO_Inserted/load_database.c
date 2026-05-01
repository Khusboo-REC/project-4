#include "inverted_Search.h"

int load_database(Wlist *head[], const char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if(!fptr)
    {
        printf("Error: Cannot open file '%s'\n", filename);
        return FAILURE;
    }
    
    char line[256];
    int current_index = -1;
    char current_word[WORD_SIZE];
    Wlist *current_word_node = NULL;
    
    printf("Loading database from '%s'...\n", filename);
    
    while(fgets(line, sizeof(line), fptr))
    {
        if(line[0] == '#' || line[0] == '\n')
            continue;
            
        if(line[0] == '[')
        {
            int index, count;
            char word[WORD_SIZE];
            
            if(sscanf(line, "[%d]:%[^:]:%d", &index, word, &count) == 3)
            {
                current_index = index;
                strcpy(current_word, word);
                
                // Create word node
                Wlist *new_word = malloc(sizeof(Wlist));
                strcpy(new_word->word, word);
                new_word->file_count = count;
                new_word->Tlink = NULL;
                new_word->link = NULL;
                
                // Add to hash table
                if(head[current_index] == NULL)
                {
                    head[current_index] = new_word;
                }
                else
                {
                    Wlist *temp = head[current_index];
                    while(temp->link)
                        temp = temp->link;
                    temp->link = new_word;
                }
                current_word_node = new_word;
            }
        }
        else
        {
            char fname[FNAME_SIZE];
            int wcount;
            
            if(sscanf(line, "%*s %[^:]:%d", fname, &wcount) == 2)
            {
                // Create link table entry
                Ltable *new_link = malloc(sizeof(Ltable));
                strcpy(new_link->file_name, fname);
                new_link->word_count = wcount;
                new_link->table_link = NULL;
                
                // Add to word's link table
                if(current_word_node->Tlink == NULL)
                {
                    current_word_node->Tlink = new_link;
                }
                else
                {
                    Ltable *l_temp = current_word_node->Tlink;
                    while(l_temp->table_link)
                        l_temp = l_temp->table_link;
                    l_temp->table_link = new_link;
                }
            }
        }
    }
    
    fclose(fptr);
    printf("Database loaded successfully!\n");
    return SUCCESS;
}