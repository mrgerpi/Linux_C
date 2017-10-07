#include <stdio.h>
#include <string.h>
#include "linkList.h"

tDataNode* FindCmd(tDataNode* head, char* cmd)
{
    tDataNode* p = head;

    while(p != NULL)
    {
        if(strcmp(p->cmd, cmd) == 0)
            break;
        p = p->next;
    }

    return p;
}

int ShowCmds(tDataNode* head)
{
    while(head != NULL)
    {
        printf("%s <--> %s\n", head->cmd, head->decr);
        head = head->next;
    }
    
    return 0;
}

