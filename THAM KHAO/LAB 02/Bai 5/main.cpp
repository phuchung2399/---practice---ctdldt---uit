//Ho va ten: Ung Quoc Cuong
//Buoi 04 - Bai 05
//Lop HC.K2022.1

#include <iostream>
#define MAX 100

using namespace std;

//cau truc stack
struct stack
{
    int n;
    int e[MAX];
};

// Ham khoi tao
void init(stack &s)
{
    s.n=-1;
}

// Kiem tra ngan xep rong
int isempty (stack s)
{
    if(s.n==-1)
        return 1;
    return 0;
}

// Kiem tra ngan xep day
int isfull(stack s)
 {
     return (s.n==MAX-1);
 }

 // Them mot phan tu vao stack
 void push(stack &s, int x)
 {
     if (isfull(s))
        cout <<" Ngan xep day !";
     else
     {
         s.n++;
         s.e[s.n]=x;
     }
 }

 // Lay mot phan tu ra khoi stack
 int pop (stack &s)
 {
     if(isempty(s))
     {
         cout <<"Ngan xep rong !";
         return -1;
     }
     else
        return s.e[s.n--];
 }

int main()
{
    stack s;
    init(s);
    int m,k;
    cout << "Chuong trinh chuyen doi thap phan sang nhi phan!" << endl;
    do
    {
        cout << "Nhap so thap phan can chuyen: ";
        cin >> m ;
    }
    while (m<=0);
    while (m!=0)
    {
        k=m%2;
        push(s,k);
        m=m/2;
    }
    cout << "So nhi phan la: ";
    while (isempty(s)==0)
        cout << pop(s);
}
