#include "linkTable.h"
#include <stdlib.h>
#include <stdio.h>

/**
  Create LinkTable
**/
tLinkTable* CreateLinkTable()
{
    tLinkTable* p = (tLinkTable*)malloc(sizeof(tLinkTable));
    p->pHead = p->pTail = NULL;
    p->NodeNum = 0;

    return p;
}

/**
  Delete LinkTable
**/
void DeleteLinkTable(tLinkTable* pLinkTable)
{
    free(pLinkTable); 
}

/**
  Add LinkTable Node to the Tail of LinkTable
**/
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if(pNode == NULL)
    {
        printf("Error:Insert NULL Node!\n");
        return 0;
    }
    if(pLinkTable == NULL)
    {
        printf("Error:To insert Nul linkTable!\n");
        return 0;
    }

    if(pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pLinkTable->pTail = pNode;
    }
    else
    {
        pLinkTable->pTail->Next = pNode;
        pLinkTable->pTail = pNode;
    }

    return 1;
}
/**
  Delete LinkTable Node from the Head of LinkTable
**/
int DeleteLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    tLinkTableNode* PtrToNode;
    if(pLinkTable->pHead == NULL)
        return 0;
    if(pLinkTable->pHead == pLinkTable->pTail)
    {
        if(pLinkTable->pHead != pNode)
            return 0;
        else
            pLinkTable->pHead = pLinkTable->pTail = NULL;
    }
    else
    {
        PtrToNode = pLinkTable->pHead;
        if(PtrToNode == pNode){
            pLinkTable->pHead = PtrToNode->Next;
            return 1;
        }
        while(PtrToNode->Next != pNode)
        {
            if(PtrToNode == pLinkTable->pTail)
                return 0; 
            PtrToNode = PtrToNode->Next;
        }
        PtrToNode->Next = PtrToNode->Next->Next;
        return 1;
    }
}

/**
  Get LinkTable Head
**/
tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable)
{
    if(pLinkTable == NULL)
    {
        printf("Error:Link Table Is Empty!\n");
        return NULL;
    }
    return pLinkTable->pHead;
}

/**T
  Get the Next LinkTable Node of pNode from pLinkTable
**/
tLinkTableNode* GetNextLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    tLinkTableNode* PtrToNode = pLinkTable->pHead;

    if(pNode == NULL)
    {
        printf("Error: Insert NULL Pointer!\n");
        return NULL;
    }

    //verification
    while(PtrToNode != NULL)
    {
        if(PtrToNode == pNode)
            break;
        PtrToNode = PtrToNode->Next;
    }
    if(PtrToNode == NULL)
    {
        printf("Error: No Node In Link Table!\n");
        return NULL;
    }
    
    return pNode->Next;
}
