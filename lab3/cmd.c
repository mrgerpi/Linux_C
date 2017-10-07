/*************************************************************************************************
  *
  *Author:MrGerpi
  *Time:2017/9/25
  *Description:A common CMD, Business Logic Layer 
  *
*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkList.h"

#define MAX_CMD_LEN 128
#define MAX_DECR_LEN 1000
#define MAX_CMD_NUM 10

int help();
int quit();

static tDataNode head[] = 
{
    {"help", "This is help cmd!", help, &head[1]},
    {"version", "Common Cmd V1.0", NULL, &head[2]}, 
    {"quit", "Quit Common Cmd!", quit, NULL}
};


int main()
{
    char cmd[MAX_CMD_LEN]; 
    tDataNode* p;
    while(1)
    {
        printf("Enter a Cmd>>>");
        scanf("%s", cmd);
        p = FindCmd(head, cmd);
        if(p != NULL)
        {
            printf("%s <--> %s\n", p->cmd, p->decr);
            if(p->handler != NULL)
            {
                p->handler();
            }
        }
    }
    return 0;
}

int help()
{
    return ShowCmds(head);
}

int quit()
{
    printf("Bye!\n");
    exit(0);
}
