
//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài 01 - LAB04
/////////////////////////////////

#include <iostream>
#include <time.h>

using namespace std;

struct NODE{
    int data;
    NODE* pLeft;
    NODE* pRight;
};

struct tree{
    NODE *root;
};

NODE* createNODE(int x){
    NODE* p = new NODE;
       if(p==NULL){
        return NULL;
    }
    p->data =x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
};

void createTree(tree &t){
    t.root = NULL;
};

void addNODE(tree &t, NODE *p){
    if(t.root == NULL){
        t.root = p;
    }else{
        NODE *f = NULL;
        NODE *i = t.root;
        while (i != NULL)
        {
             f=i;
            if (p->data < i->data)
            {
                i = i->pLeft;
            }else if (p->data > i->data)
            {
                i = i->pRight;
            }
        }
        if(p->data < f->data )
        {
            f->pLeft = p;
        }else if (p->data > f->data )
        {
            f->pRight = p;
        }
        else{

        }
    }      
}

void run(NODE *p){
    if (p == NULL){
    return;
    }

    run(p->pLeft);
    cout << p->data  << "\t";
    run(p->pRight);    
};

void countNODE(NODE *p, int &c){
    if (p == NULL)
    return;
    countNODE(p->pLeft,c);
    c++;
    countNODE(p->pRight,c);    
};

void countX(NODE *p, int &c ,int x){
    if (p == NULL){
    return;
    }

    countX(p->pLeft,c,x);
    if (p->data < x)
    {
        c++;
    }

    countX(p->pRight,c,x);    
};

void countY(NODE *p, int &c ,int x){
    if (p == NULL){
    return;
    }

    countY(p->pLeft,c,x);
    if (p->data > x)
    {
        c++;
    }

    countY(p->pRight,c,x);    
};

void sumAll(NODE *p, int &s){
    if (p == NULL){
    return;
    }

    sumAll(p->pLeft,s);

        s+= p->data;

    sumAll(p->pRight,s);    
};

bool search(tree t, int x){
    NODE * p = t.root;
    while (p->pLeft == NULL)
    {
        if (x == p->data)
        {
            return true;
        }else if (x < p->data)
        {
            p= p->pLeft;
        }else if (x> p->data)
        {
            p =p->pRight;
        }
    }
   return false;
}

int main()
{
    tree t;
    createTree(t);
    while (1) {
        cout<<"-------"<<endl;
        cout<<"1. Chen NODE bang cach nhap thu cong."<<endl;
        cout<<"2. Tao Tree tu gia tri ngau nhien." << endl;
        cout<<"3. Viet ham tìm kiem do nguoi dung nhap vao: " << endl;
        cout<<"4. Viet ham tim kiem mot so ngau nhien[300:800]." << endl;
        cout<<"5. In ra toan bo NODE." << endl;
        cout<<"6. Dem toan bo so NODE cua cay." << endl;
        cout<<"7. Dem so nho hon X nhap tu ban phim." << endl;
        cout<<"8. Dem so lon hon X nhap tu ban phim." << endl;
        cout<<"9. Tinh tong so NODE trong cay." << endl;
        int c;
        cout<<"Nhap lua chon: ";
        cin>>c;
            switch (c){
            case 1:{
            int num;
            cout << "Hay nhap so muon chen: ";
            cin >> num;
            addNODE(t, createNODE(num));
                    }break;
            case 2:{
                    srand(time(0));
                    int n = 10+ rand() %11;
                    for (int i = 0; i<n;i++){
                    int value = 358 + rand() % 1001;
                    addNODE(t, createNODE(value));
                        }
                cout <<"Hoan thanh"<<endl;
                    }break;
            case 3:{
                int num;
                cout << "Hay nhap so muon tim: ";
                cin >> num;
                if (search(t,num))
                    {
                    cout <<   "Co so nay trong cay nhi phan" <<endl;
                }else{
                        cout <<  "Khong co so nay" <<endl;
                    }
                    }break;
            case 4:{
                int n = 300+ rand() %501;
                cout << "So ngau nhien la: "<< n<<endl;
                 if (search(t,n))
                    {
                    cout <<   "Co so nay trong cay nhi phan" <<endl;
                }else{
                        cout <<  "Khong co so nay" <<endl;
                    }
                     }break;
            case 5:{
                cout << "Danh sach toan bo NODE: "<<endl;
                run(t.root);
                   cout << endl;
                    
                     }break;
            case 6:{
                int c=0;
                countNODE(t.root,c);
                cout << "So luong NODE la: " << c <<endl;
                     }break;
            case 7:{
                int c=0;
                int x;
                cout << "Nhap so X: "<<endl;
                cin >> x;
                countX(t.root,c,x);
                cout << "So luong NODE nho hon X la: " << c <<endl;
                     }break;
             case 8:{
                int c=0;
                int x;
                cout << "Nhap so X: "<<endl;
                cin >> x;
                countY(t.root,c,x);
                cout << "So luong NODE lon hon X la: " << c <<endl;
										 }break;
             case 9:{
                int s=0;
                sumAll(t.root,s);
                cout << "Tong so NODE trong cay la: " << s <<endl;
                     }break;
            default:
                break;
        }
    }
}
