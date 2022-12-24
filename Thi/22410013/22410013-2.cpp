
//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Kiểm Tra - đề số 02
/////////////////////////////////

#include <iostream>
using namespace std;

struct SinhVien{            
    int maSV;                  
    string hoTen;
    float diemMH;       
};
typedef SinhVien SV;

struct Node {
    SV data;
    Node *pNext;
};

struct ListNode{
    Node *pHead;
    Node *pTail;
};

Node* CreateNode(SV sv) {
    Node *node = new Node();
    if(node == NULL){
        return NULL;
    } else {
        node->data.maSV = sv.maSV;
        node->data.hoTen = sv.hoTen;
        node->data.diemMH = sv.diemMH;
        node->pNext =NULL;
    }
    return node;
}

ListNode CreateListNode(ListNode &l){
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

/* Câu 1:
    Input: 
        + Listnode , node
    Output
        + true or false
*/
bool addNodeSVTail (ListNode &l , Node *p){
    if (l.pHead ==NULL)
    {
        l.pHead =p;
        l.pTail =l.pHead; 
        return true; 
    }else{
        l.pTail->pNext=p;
        l.pTail= p;
        return true; 
    };
    return false;
};

Node* inputSv(SV &sv){

    // cout << "Nhap maSV sinh vien: ";
    // cin >> sv.maSV;
    // cout << "Nhap hoTen sinh vien: ";
    // cin >> sv.hoTen;
    // cout << "Nhap diemMH sinh vien: ";
    // cin >> sv.diemMH;
    return CreateNode(sv);
};

void outputOneSV(Node* sv){
    cout <<"Ma sv : "<< sv->data.maSV << " Ho va ten : " << sv->data.hoTen << " GPA : " <<sv->data.diemMH<< endl;
};

/* Câu 2:
    Input: 
        + node
    Output
        + node
*/
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

/* Câu 3:
    Input: 
        + node
    Output
        + null  
*/
Node* findSvID(ListNode &l, int idSv){
    for(Node *sv = l.pHead ; sv != NULL; sv=sv->pNext){
        if (idSv == sv->data.maSV){
            return sv;
        };
    }
    return NULL;
}

ListNode findSvScore(ListNode &l, float gpaSv){
    ListNode ListSameGpa = CreateListNode(ListSameGpa);
    for(Node *sv = l.pHead ; sv != NULL; sv=sv->pNext){
        if (gpaSv == sv->data.diemMH)
        {
            addNodeSvHead(ListSameGpa,sv);
        };
    };
    return ListSameGpa;
};

/* Câu 4:
    Input: 
        + node
    Output
        + int
*/
int countSvBelowAverage(ListNode &l){
    int temp = 0;
    for (Node* sv = l.pHead; sv !=NULL; sv=sv->pNext)
    {
       if(sv->data.diemMH < 5 ){
        temp = temp + 1;
       }
    }
    return temp; 
};

/* Câu 5:
    Input: 
        + node
    Output
        + int
*/
float gpaSv(ListNode &l){
    float gpa = 0.0;
    float totalSv = 0.0;
    for (Node* sv = l.pHead; sv !=NULL; sv=sv->pNext)
    {
        gpa = gpa + sv->data.diemMH;
        totalSv = totalSv + 1;
    }
    return (gpa/totalSv);
};

/* Câu 6:
    Input: 
        + node
    Output
        + node
*/
Node* findHightScoreSv(ListNode &l){
    Node* hightScore = new Node;
    for (Node* sv = l.pHead; sv !=NULL; sv=sv->pNext)
    {
       if(sv->data.diemMH > hightScore->data.diemMH){
            hightScore = sv;
       }
    }
    return hightScore; 
};

/* Câu 7:
    Input: 
        + node
    Output
        + node
*/
Node* findScoreAboveEightSv(ListNode &l){
    Node* hightScore = new Node;
    for (Node* sv = l.pHead; sv !=NULL; sv=sv->pNext)
    {
       if(sv->data.diemMH > 8){
            hightScore = sv;
       }
    }
    return hightScore; 
};

// Đề số 02
int main(){
    ListNode listSv;
	CreateListNode(listSv);

    while (1) {
        cout<<"-------"<<endl;
        cout<<"1. Them sinh vien vao cuoi danh sach " << endl;
        cout<<"2. In ra danh sach sinh vien" << endl;
        cout<<"3. Tim sinh vien theo ID" << endl;
        cout<<"4. Dem sinh vien co diem duoi trung binh" << endl;
        cout<<"5. Tinh diem trung binh sinh vien" << endl;
        cout<<"6. Tim sinh vien cao diem nhat" << endl;
        cout<<"7. Tim sinh vien co diem mon hoc tren 8" << endl;
        int c;
        cout<<"Nhap lua chon: ";
        cin>>c;
            switch (c){
            case 1:
            {
                SV sv1 = {123, "Nguyen A", 8.8};
                SV sv2 = {124, "Nguyen B", 9.7};
                SV sv3 = {125, "Nguyen C", 2.9};
                SV sv4 = {126, "Nguyen D", 9.7};
                SV sv5 = {127, "Nguyen E", 4.8};
                SV sv6 = {128, "Nguyen F", 7.5};

                addNodeSVTail(listSv, inputSv(sv1));
                addNodeSVTail(listSv, inputSv(sv2));
                addNodeSVTail(listSv, inputSv(sv3));
                addNodeSVTail(listSv, inputSv(sv4));
                addNodeSVTail(listSv, inputSv(sv5));
                addNodeSVTail(listSv, inputSv(sv6));
            }
            break;

            case 2:
            {
            	outPut(listSv);
            }
            break;

            case 3:
            {
            	int idSv;
                cout << "Nhap ID sinh vien can tim" <<endl;
                cin>> idSv;
                outputOneSV(findSvID(listSv,idSv));
            }
            break;

            case 4:
            {
                cout << "so luong sinh vien co diem MH duoi trung binh: " << countSvBelowAverage(listSv) << endl;
            }
            break;

            case 5:
            {
                cout << "Diem trung binh cua sv: " << gpaSv(listSv) << endl;
            }
            break;
            
            case 6:
            {
                outputOneSV(findHightScoreSv(listSv));
            }

            case 7:
            {
                outputOneSV(findScoreAboveEightSv(listSv));
            }

            default:
                break;
        }
    }
    return 0;
}
