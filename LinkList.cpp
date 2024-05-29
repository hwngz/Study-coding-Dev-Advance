#include "iostream"
using namespace std;
struct NODE
{
    int Key;
    NODE *pNext;
};
NODE *CreateNode(int Data)
{

    NODE *pNode;
    pNode = new NODE; 
    if (pNode == NULL)
        return NULL;
    pNode->Key = Data;
    pNode->pNext = NULL;
    return pNode;
}
bool AddHead(NODE *&pHead, int Data)
{
    NODE *pNode;
    pNode = CreateNode(Data);
    if (pNode == NULL)
        return false;

    NODE *temp;
    temp = pHead;
    while (temp != NULL)
    {
        if (Data == temp->Key)
            return false;
        temp = temp->pNext;
    }

    if (pHead == NULL)
        pHead = pNode;
    else
    {
        pNode->pNext = pHead;
        pHead = pNode;
    }
    return true;
}
bool AddTail(NODE *&pHead, int Data)
{
    NODE *pNode = CreateNode(Data);
    if (pNode == NULL)
        return false;

    NODE *temp;
    temp = pHead;
    while (temp != NULL)
    {
        if (Data == temp->Key)
            return false;
        temp = temp->pNext;
    }
    if (pHead == NULL)
    {
        pHead = pNode;
    }
    else
    {
        NODE *pTail = pHead;
        while (pTail->pNext != NULL)
        {
            pTail = pTail->pNext;
        }
        pTail->pNext = pNode;
    }
    return true;
}
void PrintList(NODE *pHead)
{
    NODE *pNode;
    pNode = pHead;
    while (pNode != NULL)
    {
        cout << pNode->Key << " ";
        pNode = pNode->pNext; 
    }
}
void RemoveHead(NODE *&pHead)
{
    NODE *pNode;
    if (pHead != NULL)
    {
        pNode = pHead;
        pHead = pHead->pNext;
        delete pNode;
    }
}
void RemoveTail(NODE *&pHead)
{
    if (pHead == NULL)
    {
        return;
    }

    if (pHead->pNext == NULL)
    {
        delete pHead;
        pHead = NULL;
        return;
    }

    NODE *pNode = pHead;
    while (pNode->pNext->pNext != NULL)
    {
        pNode = pNode->pNext;
    }

    delete pNode->pNext;
    pNode->pNext = NULL;
}
void RemoveAll(NODE *&pHead)
{
    NODE *pNode;
    while (pHead != NULL)
    {
        pNode = pHead;
        pHead = pHead->pNext;
        delete pNode;
    }
    pHead = NULL;
}
int SumList(NODE *pHead)
{
    int sum = 0;
    NODE *pNode;
    pNode = pHead;
    while (pNode != NULL)
    {
        sum += pNode->Key;
        pNode = pNode->pNext; 
    }
    return sum;
}
int MaxList(NODE *pHead)
{
    NODE *pNode;
    pNode = pHead;
    int max = pHead->Key;
    while (pNode != NULL)
    {
        if (max < pNode->Key)
            max = pNode->Key;
        pNode = pNode->pNext; 
    }
    return max;
}
int CountList(NODE *pHead)
{
    int cnt = 0;
    NODE *pNode;
    pNode = pHead;
    while (pNode != NULL)
    {
        cnt++;
        pNode = pNode->pNext; 
    }
    return cnt;
}
void Cau9(NODE *&a, NODE *&b, NODE *pHead, int x)
{
    NODE *temp;
    temp = pHead;
    while (temp != NULL)
    {
        if (temp->Key > x)
        {
            AddTail(a, temp->Key);
        }
        else if (temp->Key < x)
        {
            AddTail(b, temp->Key);
        }
        temp = temp->pNext;
    }
}
int Value(NODE *pHead, int x)
{
    NODE *pNode = pHead;
    int count = 0;
    while (pNode != NULL)
    {
        if (pNode->Key == x)
            count++;
        pNode = pNode->pNext;
    }
    return count;
}
int main()
{
    NODE *pRoot;
    pRoot = NULL;
    int Data;
    cout << "Nhap vao du lieu, -1 de ket thuc: ";
    do
    {
        cin >> Data;
        if (Data == -1)
            break;
        AddTail(pRoot, Data);
    } while (Data != -1);
    cout << "Du lieu da duoc nhap: ";
    PrintList(pRoot);
    cout << '\n'
         << "Tong: " << SumList(pRoot);
    cout << '\n'
         << "So lon nhat: " << MaxList(pRoot);
    cout << '\n'
         << "So luong: " << CountList(pRoot);

    NODE *a = NULL, *b = NULL;
    int x;
    cout << "\nnhap x: ";
    cin >> x;
    cout << "So luong phan tu bang x: " << Value(pRoot, x) << endl;
    Cau9(a, b, pRoot, x);
    cout << "Danh sach > x: ";
    PrintList(a);
    cout << endl;
    cout << "Danh sach < x: ";
    PrintList(b);

    RemoveAll(pRoot);
    return 0;
}