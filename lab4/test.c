#include <stdio.h> 
#include <stdlib.h>
#include "linkTable.h"


typedef struct Node
{
    tLinkTableNode* pNext;
    int data;
}tNode;

tNode* CreateNode(int data)
{
    tNode* ptr = (tNode*)malloc(sizeof(tNode));
    ptr->pNext = NULL;
    ptr->data = data;

    return ptr;
}

void FreeNode(tNode* ptr)
{
    free(ptr);
}

int main()
{
    tLinkTable* pLinkTable;
    tNode* pNode;
    tNode* deleteNode;
    int i;

    pLinkTable = CreateLinkTable();
    for(i = 0;i < 5;i++)
    {
        pNode = CreateNode(i);
        AddLinkTableNode(pLinkTable, (tLinkTableNode*)pNode);
    }

    pNode = (tNode*)GetLinkTableHead(pLinkTable);
    while(pNode != NULL)
    {
        printf("%d\n", pNode->data);
        pNode = (tNode*)GetNextLinkTableNode(pLinkTable, (tLinkTableNode*)pNode);
    }

    deleteNode = (tNode*)GetLinkTableHead(pLinkTable);
    while(deleteNode != NULL)
    {
        pNode = (tNode*)GetNextLinkTableNode(pLinkTable, (tLinkTableNode*)deleteNode);
        DeleteLinkTableNode(pLinkTable, (tLinkTableNode*)deleteNode);
        FreeNode(deleteNode);
        deleteNode = pNode;
    }

    DeleteLinkTable(pLinkTable);
    return 0;
}
