//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài 01 - LAB01
/////////////////////////////////
#include <iostream>

using namespace std;

//Cau 1
//Buoc 1 - Tao cau truc Node
struct Node
{
    int data;
    Node* pNext;
};

//Buoc 2 - Tao cau truc danh sach
struct List
{
    Node* head;
    Node* tail;
};

//Cau 2
//Buoc 3 - Khoi tao node
Node* createNode(int x)
{
    Node *p = new Node;
    if(p == NULL)
        return NULL;

    p->data = x;
    p->pNext = NULL;

    return p;
}

//Buoc 4 - Khoi tao danh sach
void createList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

//Cau 3
void addHead(List &l, Node* p)
{
    if(l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->pNext = l.head;
        l.head = p;
    }
}

//Cau 4
void addTail(List &l, Node* p)
{
    if(l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->pNext = p;
        l.head = p;
    }
}

//Cau 5
void nhap(List &l)
{
    int soLhuong;
    cout << "Nhap so luong node can nhap";
    cin >> soLhuong;

    for(int i = 1; i <=5; i = i+1)
    {
        int tam;
        cout << "\tHay nhap gia tri cho node = ";
        cin >> tam;
        Node * p = createNode(tam);
        addHead(l, p);
    }
}

//Cau 11
void printList(List l)
{
    for(Node* i = l.head; i != NULL; i = i->pNext)
    {
        cout << i->data << "\t";
    }
}

void printListWhile(List l)
{
    Node * p = l.head;
    while(p != NULL)
    {
        cout << p << "\t";
        p = p -> pNext;
    }
}
int main()
{
    List l;
    createList(l);
//    Node *p1 = createNode(20);
//    Node *p2 = createNode(50);
//    Node *p3 = createNode(30);
//    addHead(l, p1);
//    addHead(l, p2);
//    addHead(l, p3);
//    addHead(l, createNode(80));
    nhap(l);
    printList(l);
//    rintListWhile(l);

}
