//Ho va ten: Ung Quoc Cuong
//Buoi 04 - Bai 01
//Lop HC.K2022.1

#include <iostream>

using namespace std;
//B1: Cau truc node
struct Node
{
    int data;
    Node* pNext;
};

//B2: Cau truc stack
struct Stack{
    Node * Top;
};

//B3: Bien gia tri thanh Node
Node* createNode(int x)
{
    Node *p = new Node;
    if(p == NULL)
        return NULL;
    p->data = x;
    p->pNext = NULL;

    return p;
}

//B4: Khoi tao stack
void createStack(Stack &s)
{
    s.Top = NULL;
}

void push(Stack &s, Node * p)
{
    if(s.Top == NULL)
    {
        s.Top = p;
    }
    else
    {
        p->pNext = s.Top;
        s.Top = p;
    }
}

void pop(Stack &s, int &value)
{
    if(s.Top == NULL)
        return;
    Node * p = s.Top;
    s.Top = s.Top->pNext;
    value = p->data;
    delete p;
}

void printStack(Stack s)
{
    cout<< "STACK = Top< ";
    for(Node * i = s.Top; i != NULL; i=i->pNext)
    {
        cout << i->data << " ";
    }
    cout << ">" << endl;
}

bool isEmpty(Stack s)
{
    if(s.Top == NULL)
        return true;
        return false;
}

int main()
{
    Stack s;
    createStack(s);

    while(true)
    {
        cout<< endl;
        cout<< "==========Bai 01==========" << endl;
        cout<< "\t1. Push" << endl;
        cout<< "\t2. Pop" << endl;
        cout<< "\t3. Top" << endl;
        cout<< "\t4. Checking empty" << endl;
        cout<< "\t5. Checking full" << endl;
        cout<< "===========================" << endl;
        printStack(s);
        cout<< "===========================" << endl;
        cout<< "\tPlease input: ";
        int chon;
        cin>> chon;
        cout<< endl << endl;

        switch(chon)
        {
            case 1:
            {
                int x;
                cout << "Nhap gia tri vao stack: ";
                cin >> x;

                push(s, createNode(x));
            }
            break;

            case 2:
            {
                int x;
                pop(s, x);
                cout << "Da lay ra gia tri la: " << x << endl;
            }
            break;

            case 3:
            {
                cout << "Top: " << s.Top->data << endl;
            }
            break;

            case 4:
            {
                if(isEmpty(s))
                    cout << "Empty\n";
                else
                    cout << "No Empty\n";
            }
            break;

            case 5:
            {


            }
            break;
        }
    }
    printStack(s);
}
