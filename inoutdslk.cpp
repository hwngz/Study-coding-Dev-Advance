#include<bits/stdc++.h>
using namespace std;

struct NODE
{
    int x;
    NODE *pNext;
};

NODE *CreateNode(int Data){
        NODE *pNode;
        pNode = new Node;
        if( pNode == NULL)
            return NULL;   
        pNode.x = Data;
        pNode.pNext = NULL;
        return pNode;
}

bool AddHead (NODE* &pHead, int Data){
    NODE *pNode;
    pNode = CreateNode(Data);
    if(pNode == NULL)
        return false;
    if(pHead == NULL)
        pHead = pNode;
    else{
        pNode.pNext = pHead;
        pHead = pNode;
    }
    return true;
}

void PrintList(NODE *pHead){
    NODE *pNode;
    pNode = pHead;
    while (pNode != NULL){
        cout << pNode .x;
        pNode = pNode.pNext;
    }
}

void RemoveAll(NODE* &pHead){
    NODE *pNode;
    while (pHead != NULL){
        pNode = pHead;
        pHead = pHead.pNext;
        delete pNode;
    }
    pHead = NULL;
}

int main(){
    NODE *pRoot;
    pRoot = NULL;
    int dt;
    do {
        cin >> &dt;
        if (dt == -1)
            break;
        AddHead(pRoot, dt);
    }
    while (dt != -1);
    PrintList(pRoot);
    RemoveAll(pRoot);
}

