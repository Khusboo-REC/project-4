#include "inverted_Search.h"  // ADD THIS LINE

int create_database(Flist *f_head, Wlist *head[])
{
    while(f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }

    printf("Database created successfully\n");
    return SUCCESS;
}