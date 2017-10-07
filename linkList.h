/*
author:Mrgerpi
time:2017/10/7
decription:A common cmd, Data Structrue and Operation
*/

typedef struct DataNode{
    char*           cmd;
    char*           decr;
    int             (*handler)();
    struct DataNode* next; 
} tDataNode;

tDataNode* FindCmd(tDataNode* head, char* cmd);

int ShowCmds(tDataNode* head);
