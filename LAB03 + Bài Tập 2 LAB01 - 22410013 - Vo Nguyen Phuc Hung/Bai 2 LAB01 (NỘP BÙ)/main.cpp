//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài 02 - LAB02 (Nộp bù, do nộp nhầm bài tập LAB02 vào phần nộp bài của bài tập 2 của LAB01)
/////////////////////////////////

#include <iostream>
using namespace std;

struct SINH_VIEN{            
    int ID;                  
    string NAME;             
    float GPA;               
};                           

struct Node {
    SINH_VIEN data;
    Node *pNext;
};

struct ListNode{
    Node *pHead;
    Node *pTail;
};

Node* CreateNode(SINH_VIEN sv) {
    Node *node = new Node();
    if(node == NULL){
        return NULL;
    } else {
        node->data.ID = sv.ID;
        node->data.NAME = sv.NAME;
        node->data.GPA = sv.GPA;
        node->pNext =NULL;
    }
    return node;
}

ListNode  CreateListNode(ListNode &l){
    l.pHead = NULL;
    l.pTail = NULL;
    return l;
}

void addNodeSvHead(ListNode &l, Node *p){
    if (l.pHead==NULL)
    {
        l.pHead =p;
        l.pTail =l.pHead;   
    }else{
        p->pNext = l.pHead;
        l.pHead = p;
    };
};

void addNodeSVTail (ListNode &l , Node *p){
    if (l.pHead ==NULL)
    {
        l.pHead =p;
        l.pTail =l.pHead;  
    }else{
        l.pTail->pNext=p;
        l.pTail= p;
    };
    
};

Node* inputSv(SINH_VIEN &sv){
    cout << "Nhap ID sinh vien: ";
    cin >> sv.ID;
    cout << "Nhap NAME sinh vien: ";
    cin >> sv.NAME;
    cout << "Nhap GPA sinh vien: ";
    cin >> sv.GPA;
    return CreateNode(sv);
};

void outputOneSV(Node* sv){
    cout <<"Ma sv : "<< sv->data.ID << " Ho va ten : " << sv->data.NAME << " GPA : " <<sv->data.GPA<< endl;
};

void outPut(ListNode l){
    if (l.pHead ==NULL)
    {
        return;
    }else{
        for(Node *sv = l.pHead ; sv != NULL; sv=sv->pNext){
            outputOneSV(sv);
        };
    };
};

Node* findSvID(ListNode &l, int idSv){
    for(Node *sv = l.pHead ; sv != NULL; sv=sv->pNext){
        if (idSv == sv->data.ID)
        {
            return sv;
        };
       
        }
         return NULL;
}

ListNode findSvName(ListNode &l, string nameSv){
    ListNode ListSameName = CreateListNode(ListSameName);
    for(Node *sv = l.pHead ; sv != NULL; sv =sv->pNext){
        if (nameSv == sv->data.NAME)
        {
            addNodeSVTail(ListSameName,sv);
        };
    };
    return ListSameName;
};

ListNode findSvScore(ListNode &l, float gpaSv){
    ListNode ListSameGpa = CreateListNode(ListSameGpa);
    for(Node *sv = l.pHead ; sv != NULL; sv=sv->pNext){
        if (gpaSv == sv->data.GPA)
        {
            addNodeSvHead(ListSameGpa,sv);
        };
    };
    return ListSameGpa;
};

Node* findHightScoreSv(ListNode &l){
    Node* hightScore = new Node;
    for (Node* sv = l.pHead; sv !=NULL; sv=sv->pNext)
    {
       if(sv->data.GPA > hightScore->data.GPA){
        hightScore = sv;
       }
    }
    return hightScore; 
};

Node* findLowScoreSv(ListNode &l){
    Node* lowtScore = new Node;
    lowtScore = l.pHead;
    for (Node* sv = l.pHead; sv !=NULL; sv=sv->pNext)
    {
       if(sv->data.GPA < lowtScore->data.GPA ){
          lowtScore = sv; 
       }

    };
    return lowtScore;
};

int main(int argc, const char * argv[]) {
	ListNode listSv;
	CreateListNode(listSv);
    while (1) {
        cout<<"-------"<<endl;
        cout<<"1. Them sinh vien vao dau danh sach"<<endl;
        cout<<"2. Them sinh vien vao cuoi danh sach " << endl;
        cout<<"3. In ra danh sach sinh vien" << endl;
        cout<<"4. Tim sinh vien cao diem nhat" << endl;
        cout<<"5. Tim sinh vien thap diem nhat" << endl;
        cout<<"6. Tao sinh vien ngau nhien" << endl;
        cout<<"7. Tim sinh vien theo ID" << endl;
        cout<<"8. Tim sinh vien theo NAME" << endl;
        cout<<"9. Tim sinh vien theo DIEM" << endl;
        int c;
        cout<<"Nhap lua chon: ";
        cin>>c;
            switch (c){
            case 1:{
                SINH_VIEN sv;
                 addNodeSvHead(listSv, inputSv(sv));
                    }break;

            case 2:{
            	SINH_VIEN sv;
                 addNodeSVTail(listSv, inputSv(sv));
                    }break;
            case 3:{
                outPut(listSv);
                    }break;
            case 4:{

                outputOneSV(findHightScoreSv(listSv));
                     }break;
            case 5:{

                outputOneSV(findLowScoreSv(listSv));
                     }break;
            case 6:{
                SINH_VIEN sv;
                SINH_VIEN sv1= {100, "Duong", 9.5};
                SINH_VIEN sv2 = {101, "Hung", 10.0};
                Node *s1 = CreateNode(sv1);
                Node *s2 = CreateNode(sv2);
                addNodeSvHead(listSv, s1);
                addNodeSvHead(listSv, s2);
                     }break;
            case 7:{
                int idSv;
                cout << "Nhap ID sinh vien can tim" <<endl;
                cin>> idSv;
                outputOneSV(findSvID(listSv,idSv));
                     }break;
             case 8:{
                SINH_VIEN sv;
                string idName ;
                cout << "Nhap NAME sinh vien can tim" <<endl;
                cin>> idName;
                outPut(findSvName(listSv,idName));
                     }break;
             case 9:{
                SINH_VIEN sv;
                float idScore ;
                cout << "Nhap DIEM sinh vien can tim" <<endl;
                std::cin >> idScore;
                outPut(findSvScore(listSv,idScore));
                     }break;
            default:
                break;
        }
    }
}
