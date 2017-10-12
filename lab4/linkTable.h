/**
Author  : WeiYafeng
Time    : 2017/10/10 
Decription  : To reuse, Modularize the LinkTable
  */

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

/**
  LinkTableNode Type
**/
typedef struct LinkTableNode
{
    struct LinkTableNode* Next;    
}tLinkTableNode;

/**
  LinkTable Type
**/
typedef struct LinkTable
{
    tLinkTableNode* pHead;
    tLinkTableNode* pTail;
    int      NodeNum;
}tLinkTable;

/**
  Create LinkTable
**/
tLinkTable* CreateLinkTable();

/**
  Delete LinkTable
**/
void DeleteLinkTable(tLinkTable* pLinkTable);

/**
  Add LinkTable Node
**/
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);
/**
  Delete LinkTable Node
**/
int DeleteLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);

/**
  Get LinkTable Head
**/
tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable);

/**T
  Get the Next LinkTable Node of pNode from pLinkTable
**/
tLinkTableNode* GetNextLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);

#endif
