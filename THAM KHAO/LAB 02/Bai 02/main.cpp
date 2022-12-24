//Ho va ten: Ung Quoc Cuong
//Buoi 04 - Bai 05
//Lop HC.K2022.1

#include <iostream>

using namespace std;

//B1
struct Node
{
    int data;
    Node* pNext;
};

//B2
struct Queue
{
    Node* Front;
    Node* Rear;
};

//B3 Bien gia tri thanh Node
Node* createNode(int x)
{
    Node *p = new Node;
    if(p == NULL)
        return NULL;
    p->data = x;
    p->pNext = NULL;

    return p;
}

//B4 Khoi tao ds
void createQueue(Queue &q)
{
    q.Front = q.Rear = NULL ;
}

//Cau 3
void deQueue(Queue &q, int &value)
{
    if(q.Front == NULL)
        return;

    Node * p = q.Front;
    q.Front = p->pNext;
    value = p->data;
    delete p;
}

//Cau 4
void enQueue(Queue &q, Node* p)
{
    if(q.Front == NULL)
    {
        q.Front = p;
        q.Rear = p;
    }
    else
    {
        q.Rear->pNext = p;
        q.Rear = p;
    }
}

void printQueue(Queue q)
{
    cout << "QUEUE = <<Front<< ";
    for(Node* i = q.Front; i != NULL; i = i->pNext)
    {
        cout<< i->data << " ";
    }
    cout << "<<Rear<<" << endl;
}

bool isEmpty(Queue q)
{
    if(q.Front == NULL)
        return true;
        return false;
}
int main()
{
    Queue q;
    createQueue(q);
    while(true)
    {
        cout<< endl;
        cout<< "==========Bai 02==========" << endl;
        cout<< "\t1. EnQueue" << endl;
        cout<< "\t2. DeQueue" << endl;
        cout<< "\t3. Front and Rear" << endl;
        cout<< "\t4. Checking empty" << endl;
        cout<< "\t5. Checking full" << endl;
        cout<< "===========================" << endl;
        printQueue(q);
        cout<< "===========================" << endl;
        cout<< "\tPlease input: ";
        int chon;
        cin>> chon;
        cout<< endl << endl;

        switch(chon)
        {
            case 1:
            {
                cout<< "Them gia tri vao Queue. Value = ";
                int x;
                cin >> x;
                Node *p = createNode(x);
                enQueue(q, p);
                break;
            }

            case 2:
            {
                cout<< "Lay 1 value ra khoi queue." << endl;
                int x;

                deQueue(q, x);

                cout<< "\tValue = " << x << endl;

                break;
            }

            case 3:
            {
                if(!isEmpty(q))
                {
                    cout<< "Front and Rear: " << q.Front->data << " - " << q.Rear->data << endl;
                }
                break;
            }

            case 4:
            {
                cout<< "Stack is empty: " << isEmpty(q) << endl;
                break;
            }

            case 5:
            {
                break;
            }
        }
    }
    return 0;
}
