//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài 05 - LAB02
/////////////////////////////////

#include <iostream>
#define MAX 100

using namespace std;

struct stack
{
    int n;
    int e[MAX];
};

void init(stack &s)
{
    s.n=-1;
}

int isempty (stack s)
{
    if(s.n==-1)
        return 1;
    return 0;
}

/*
* Kiem tra ngan xep day
*/
int isfull(stack s)
 {
     return (s.n==MAX-1);
 }

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
