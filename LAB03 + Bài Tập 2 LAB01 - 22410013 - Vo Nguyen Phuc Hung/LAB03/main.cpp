//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài tập LAB03
/////////////////////////////////

#include <iostream>
using namespace std;

#define M 7

struct Node{
    int data;
    Node *Pnext;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *createNode(int x){
    Node *p =new Node;
    if(p==NULL){
        return NULL;
    }
    p->data = x;
    p->Pnext =NULL;
    return p;
}

void createList(List &l){
    l.head =NULL;
    l.tail = NULL;
}

void addTail(List &l, Node *p){
    if (l.head==  NULL)
    {
        l.head = l.tail = p;
    }else{
        l.tail->Pnext = p; // l.tail luc nay la node thu 2
        l.tail = p;
    }
};

void printList(List &l){
    for (Node* i = l.head; i !=NULL; i = i->Pnext)
    {
        cout << i ->data <<"\t";
    }
    return;
}

struct HashTable{
    List bucket[M];
};

void createHashTable(HashTable &h){
    for(int i =0; i <7; i++){
        createList(h.bucket[i]);
    }
}

int hashFunction(int value){
   return value % M;
}

void printHashTable(HashTable &h){
       for(int i =0; i <7; i++){
           cout << "h.bucket["<< i <<"]";
        printList( h.bucket[i]);
         cout<<endl;
    }
}

void insertValue(HashTable &h, int value){
    
    int addrTable = hashFunction(value);
    addTail(h.bucket[addrTable],createNode(value));
}

void createTable(HashTable &h){
    srand(time(0));
    int n =45+(rand()%51); //so luong value dua vao HashTable
    for(int i=0;i<n;i++){
        int value =856+rand()%(989-856);
        insertValue(h,value);
    }
 
}

void addValueFromArr(HashTable &h, int Arr[],int size){

    for (int countN = 0; countN < size ; countN++)
    {
        insertValue(h, Arr[countN]);
    }
    
}

int findX(HashTable h,int Xvalue){
    int vitri = hashFunction(Xvalue);
    List b = h.bucket[vitri];
    for (Node* i = b.head; i !=NULL; i = i->Pnext)
    {
        if(i->data == Xvalue){
            return true;
        }
    };
    return false;
};

void deleValue(HashTable &h, int Xvalue){
    int vitri = hashFunction(Xvalue);
    List b = h.bucket[vitri];
    //kiem tra so phan tu = gia tri dau vao
    int DSnode = 0;
    for (Node* coutI = h.bucket[vitri].head->Pnext ;coutI != h.bucket[vitri].tail; coutI= coutI->Pnext)
    {
        if (coutI->data == Xvalue )
        {
            DSnode +=1;
        }
        
    }

    if (Xvalue == h.bucket[vitri].head->data && h.bucket[vitri].tail !=  NULL )
    {
       Node * temp = h.bucket[vitri].head;
       h.bucket[vitri].head = temp->Pnext;
       delete temp;
    }
    if(Xvalue==h.bucket[vitri].tail->data)

    {
       Node* a = h.bucket[vitri].head;
       
    for (Node* a = h.bucket[vitri].head ;a != NULL; a= a->Pnext)
      if(a->Pnext ==h.bucket[vitri].tail){
        Node *temp = h.bucket[vitri].tail;
        a->Pnext= NULL;
        h.bucket[vitri].tail = a;
      }

    }
    
        for (int i = 0; i < DSnode; i++)
        {
        Node * t = h.bucket[vitri].head;
        while (t->Pnext != NULL )
        {
            if (t->Pnext->data==Xvalue)
            {
                break;
            }
            t = t->Pnext;
        }
        Node * p = t->Pnext; 
        t->Pnext = p->Pnext;
        }
}

int generalTable(HashTable &h, int CheckNum){
    int total =0;
    for(int item =0; item <7; item++){
        for(Node *i = h.bucket[item].head ; i!= NULL ; i = i->Pnext){
            switch (CheckNum)
            {
                case 1:{
                    // tinh tong gia tri chan
                    if ( i->data%2==0)
                    {
                        total +=i->data;
                    }break;
                case 2:{
                    // tinh tong gia tri le
                    if ( i->data%2!=0)
                    {
                        total +=i->data;
                    }}break;
                case 3:{
                    // dem gia tri chan
                    if ( i->data%2==0)
                    {
                        total +=1;
                    }}break;
                
                case 4:{
                    // dem gia tri le
                    if ( i->data%2!=0)
                    {
                        total +=1;
                    }}break;
                case 5:{
                    // dem gia am
                    if ( i->data%2 < 0)
                    {
                        total +=1;
                    }}break;
                
                case 6:{
                    // dem gia tri duong
                    if ( i->data%2 > 0)
                    {
                        total +=1;
                    }}break;
                
                default:
                    break;
                }
            
            }
        }
    }
 return total;
}

int isEmpty(HashTable &h){
    int countItem;
    for(int item =0; item <7; item++){
        for(Node *i = h.bucket[item].head ; i!= NULL ; i = i->Pnext){
            if (i!= NULL)
            {
              return true;
            }   
        }
      
    }
    return false;
}

//====================================================MAIN====================================//
int main(){
    HashTable h;
    createHashTable(h);
 while (1) {
        cout<<"-------"<<endl;
        cout<<"1. Tao gia tri ngau nhien cho bang BAM"<<endl;
        cout<<"2. Tao gia tri cho bang BAM mot chieu " << endl;
        cout<<"3. Tao du lieu dang nhap thu cong tu ban phim" << endl;
        cout<<"4. In ra bang bam" << endl;
        cout<<"5. Xoa 1 gia tri trong bang BAM" << endl;
        cout<<"6. Tim ham gia tri trong bang BAM" << endl;
        cout<<"7. Ham tim tong gia tri chan le trong bang BAM" << endl;
        cout<<"8. Kiem tra bang bam co rong hay khong" << endl;
        cout<<"9. Xu ly bang BAM theo dieu kien" << endl;
        int c;
        cout<<"Nhap lua chon: ";
        cin>>c;
            switch (c){
            case 1:{
               
                createTable(h);
                 cout << "\n"<< "===> Hoan thanh "<<endl;
                    }break;
            case 2:{
                int Arr[]= {30,50,10};
                addValueFromArr(h,Arr,3);
            	  cout << "\n"<< "===> Hoan thanh "<<endl;
                    }break;
            case 3:{
                int inputValue;
                cout << "Hay nhap vao gia tri: ";
                cin >> inputValue;
                insertValue(h,inputValue);
                cout <<  "\n"<<"===> Hoan thanh "<<endl;
                    }break;
            case 4:{
                printHashTable(h);
                    }break;
            case 5:{
                int inputValue;
                cout << "Nhap gia tri muon xoa: ";
                cin >> inputValue;
                if(findX(h, inputValue)){
                     deleValue(h,inputValue);   
                }else{
                    cout << "\n"<<"Khong co gia tri";
                } }break;  
            case 6:{
                 int Xvalue;
                cout <<"Nhap vao gia tri ";
                cin >> Xvalue;
                if(findX(h, Xvalue)){
                    cout << "\n"<<"===> Co gia tri nay" <<endl;
                }else{
                    cout << "\n"<<"===> Khong co gia tri"<<endl;
                }   
                }break;
            case 7:{
                cout <<  "\n"<<"Gia tri chan le cua bang BAM" << endl;
                cout << "===> Tong gia tri chan: " << generalTable(h,1)<<endl;
                cout << "===> Tong gia tri le: " << generalTable(h,2)<<endl;
                }break;
            case 8:{
                if(isEmpty(h)){
                cout << "===> Bang BAM nay khong rong"<<endl;
                }else{
                cout << "===> Bang BAM nay rong"<<endl;}
                    }break;
            case 9:{
                cout<<"\n"<<"-------"<<endl;
                cout<<"9.1. Tinh tong gia tri CHAN"<<endl;
                cout<<"9.2. Tinh tong gia tri LE"<<endl;
                cout<<"9.3. Dem so pham tu co gia tri CHAN"<<endl;
                cout<<"9.4. Dem so pham tu co gia tri LE"<<endl;
                cout<<"9.5. Dem so pham tu co gia tri AM"<<endl;
                cout<<"9.6. Dem so pham tu co gia tri DUONG"<<endl;
                cout<<"Vui long nhap lua chon: ";
                int value;
                cin >>value;
                switch (value)
                {
                case 1: {
                    cout <<  "\n"<<"===> Tong gia tri CHAN: " << generalTable(h,value) << endl;
                }break;
                
                case 2: {
                    cout << "\n"<< "===> Tong gia tri LE: " << generalTable(h,value) << endl;
                }break;
                
                case 3: {
                    cout <<  "\n"<<"===> So phan tu gia tri CHAN: " << generalTable(h,value) << endl;
                }break;
                
                case 4: {
                    cout <<  "\n"<<"===> So phan tu gia tri LE: " << generalTable(h,value) << endl;
                }break;
                
                case 5: {
                    cout <<  "\n"<<"===> So phan tu gia tri AM: " << generalTable(h,value) << endl;
                }break;
                
                case 6: {
                    cout << "\n"<< "===>So phan tu gia tri DUONG: " << generalTable(h,value) << endl;
                }break;
                
                default:
                    break;
                }; }break;
                default:
                break;
            }
    }
}
