//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Kiểm Tra - đề số 02
/////////////////////////////////

#include <iostream>
#include<string.h>
#include<ctime>
#include<iomanip>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

struct SinhVien{
	int maSV;
	string hoTen;
	float diemMH;
};

typedef SinhVien SV;

struct Node{
	SV data;
	Node* next;
};

struct List{
	Node* head;
	Node* tail;
};

void printSV(SV sv){
	cout<<setw(5)<<left<<sv.maSV<<setw(30)<<left<<sv.hoTen<<setw(10)<<left<<setprecision(2)<<fixed<<sv.diemMH<<endl;
}

/*
Khoi tao Node SV
	Input: 
	      - SinhVien
	Output:
	      - Node (data la SinhVien)
*/
Node* createNode(SV sv){
	Node* newSV = new Node;
	newSV->data=sv;
	newSV->next=nullptr;
	return newSV;
}

/*
Khoi tao List SV
	Input: 
	      - List sv
	Output:
	      - listsv
*/
List createListSV(List &listsv){
	listsv.head=nullptr;
	listsv.tail=nullptr;
	return listsv;
}

/*
Cau 1: Chen Node chua SinhVien vao cuoi danh sach
 	Input:
    	+ SinhVien + DS sinh vien
 	Output:
    	+ DS sinh vien
 */
void addTail(List &listsv, Node* newSV){
	if(listsv.head==nullptr){
		listsv.head=listsv.tail=newSV;
	} else{
		listsv.tail->next=newSV;
		listsv.tail=newSV;
	}
}

/*
Cau 2: Xuat danh sach sinh vien ra man hinh
	Input:
    	+ listSV
 	Output:
    	+ Thong tin tat ca sinh vien
 */
void printListSV(List listsv){
	cout<<setw(5)<<left<<"Ma SV"<<setw(30)<<left<<"Ho Ten"<<setw(10)<<left<<"Diem Mon Hoc"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	if(listsv.head==nullptr){
		cout<<"DS SV rong!"<<endl;
		return;
	}
	for(auto x=listsv.head;x!=nullptr;x=x->next){
		printSV(x->data);
	}
}

/*
Cau 3: Tim kiem sinh vien theo MaSV
	Input:
    	+ listSV, key (maSV can tim kiem)
	Output:
    	+ return (Node(sv) neu tim thay HOAC NULL neu khong tim thay)
*/
Node* findSvID(List listsv, int key){
	for(auto i=listsv.head;i!=nullptr;i=i->next){
		if(i->data.maSV==key){
			return i;
		}
	}
	return nullptr;
}

/*
Cau 4: Dem SV co diem mon hoc duoi trung binh
	Input:
    	+ listSV
 	Output:
    	+ return (int)
 */
int countSvBelowAverage(List listSV){
	int n=0;
	for(Node* i=listSV.head;i!=nullptr; i=i->next){
		if(i->data.diemMH<5.0){
			++n;
		}
	}
	return n;
}

/*
 Dem so luong sinh vien
 Input:
    + listSV
 Output:
    + return (int) - so luong SV
 */
int countSV(List listSV){
	int n=0;
	for(Node* i=listSV.head;i!=nullptr;i=i->next){
		++n;
	}
	return n;
}

/*
 Cau 5: Tim diem TB cua ca lop
 Input:
    + listSV
 Output:
    + return (float) diemTB
 */
float diemTB(List listSV){
	float diemtb=0.0;
	float diemTong=0.0;
	for(Node* i=listSV.head;i!=nullptr;i=i->next){
		diemTong+=i->data.diemMH;
	}
	if(countSV(listSV)!=0){
		return diemTong/countSV(listSV);
	}
	return 0.0;
}

/*
 Cau 6: Tim SV dau tien co diem lon nhat
 Input:
    + listSV
 Output:
    + return SV.maSV (int)
 */
int find_maxdiem(List listSV){
	float max=-1.0;
	int ma=-1;
	for(Node* x=listSV.head;x!=nullptr;x=x->next){
		if(x->data.diemMH>max){
			max=x->data.diemMH;
			ma=x->data.maSV;
		}
	}
	return ma;
}

/*
 Cau 7: Tim cac sinh vien co diem > 8
 Input:
    + listSV
 Output:
    + return vector<int> chua cac maSV
 */
vector<int> find_diemtren8(List listSV){
	vector<int> v_list;
	for(Node* x=listSV.head;x!=nullptr;x=x->next){
		if(x->data.diemMH>8.0){
			v_list.push_back(x->data.maSV);
		}
	}
	return v_list;
}

/*
Cau 8: Cap nhat diem mon hoc theo maSV
    Input:
        + listSV, maSV can cap nhat
    Output:
        + listSV da cap nhat
 */
void capnhatDiem(List &listSV,int masv){
	if(listSV.head==nullptr){
		cout<<"DSSV rong!"<<endl;
		return;
	}
	for(Node* x=listSV.head;x!=nullptr;x=x->next){
		if(x->data.maSV==masv){
			float diem;
			do{
				cout<<"Nhap diem can cap nhat: ";
				cin>>diem;
			}while(diem<0||diem>10);
			x->data.diemMH=diem;
			cout<<"Hoan thanh cap nhat!"<<endl;
			return;
		}
	}
	cout<<"Khong tim thay maSV can thay doi!"<<endl;
}

/*
Cau 9: sao chep cac SV sang mot danh sach moi
    Input:
        + listSV
    Output:
        + newListSV
 */
List newListSV(List listSV){
	List newList=createListSV(newList);
	for(Node* x = listSV.head;x!=nullptr;x=x->next){
		addTail(newList,x);
	}
	return newList;
}

// Đề số 02
int main(){
	List listSV;
	createListSV(listSV);
	SV sv1={123,"Nguyen A",8.8};
	SV sv2={124,"Nguyen B",9.7};
	SV sv3={125,"Nguyen C",2.9};
	SV sv4={126,"Nguyen D",9.7};
	SV sv5={127,"Nguyen E",4.8};
	SV sv6={128,"Nguyen F",7.5};
    
	//Cau 1: chen SV vao cuoi danh sach
	addTail(listSV,createNode(sv1));
	addTail(listSV,createNode(sv2));
	addTail(listSV,createNode(sv3));
	addTail(listSV,createNode(sv4));
	addTail(listSV,createNode(sv5));
	addTail(listSV,createNode(sv6));

	//Cau 2: In danh sach sinh vien
	printListSV(listSV);

	//Cau 3: Tim sinh vien theo maSV
	if(findSvID(listSV,123)!=nullptr){
		cout<<findSvID<<endl;
	} else{
		cout<<"NULL";
	}

	//Cau 4: Dem sinh vien co diem duoi Trung Binh
	cout<<"So SV co diem duoi trung binh: "<<countSvBelowAverage(listSV)<<endl;

	//Cau 5: Tinh diem trung binh cua ca lop
	cout<<"Diem trung binh ca lop: "<<diemTB(listSV)<<endl;

	//Cau 6: Tim maSV dau tien co diem mon hoc lon nhat
	cout<<"Sinh vien co diem lon nhat maSV: "<<find_maxdiem(listSV)<<endl;

	//Cau 7: Tim cac SV co diem mon hoc tren 8
	vector<int> v_list;
	v_list=find_diemtren8(listSV);
	if(v_list.size()>0){
		cout<<"Danh sach sinh vien co diem mon hoc >8: ";
		for(auto x:v_list){
			cout<<x<<"\t";
		}
		cout<<endl;
	} else{
		cout<<"Khong co!"<<endl;
	}
	
	//Cau 8: Cap nhat diem mon hoc theo maSV
	int masv;
	cout<<"Nhap maSV can cap nhat diem: ";
	cin>>masv;
	capnhatDiem(listSV,masv);

	//Cau 9: Sao chep SV sang danh sach moi
	List newList=newListSV(listSV);
	printListSV(newList);

	return 0;
}
