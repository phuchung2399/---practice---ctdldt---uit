
//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài 02 - LAB04
/////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct HoaDon{
	string maDH;
	int soLuong;
	int tongTien;
};

HoaDon nhapHoaDon(){
    HoaDon hoadon;
    cin.ignore();
    cout<<"Nhap ma Don hang: ";
    getline(cin,hoadon.maDH);
    do{
        cout<<"Nhap so luong hang (>0): ";
        cin>>hoadon.soLuong;
    }while(hoadon.soLuong<0);
    do{
        cout<<"Nhap tong tien: ";
        cin>>hoadon.tongTien;
    }while(hoadon.tongTien<0);
    return hoadon;
}

void xuatHoaDon(HoaDon hoadon){
	cout<<"Ma DH: "<<hoadon.maDH<<endl;
	cout<<"So luong: "<<hoadon.soLuong<<endl;
	cout<<"Tong tien: "<<hoadon.tongTien<<endl;
}

struct Node{
	HoaDon data;
	Node* pLeft;
	Node* pRight;
	vector<HoaDon> v_dup;
};

struct Tree{
	Node* root;
};

Node* createNode(HoaDon data){
	Node* newNode = new Node;
	newNode->data=data;
	newNode->pLeft=nullptr;
	newNode->pRight=nullptr;
	return newNode;
}

void createTree(Tree &t){
	t.root=nullptr;
}

void insertNode(Tree &t,HoaDon hoadon){
	Node* newNode= createNode(hoadon);
	if(t.root==nullptr){
		t.root=newNode;
		return;
	}
	Node* temp=t.root;
	while(temp!=nullptr){
		if(temp->data.soLuong<hoadon.soLuong){
			if(temp->pRight==nullptr){
				temp->pRight=newNode;
				break;
			}
			temp=temp->pRight;
		} else if(temp->data.soLuong>hoadon.soLuong)
		{
			if(temp->pLeft==nullptr){
				temp->pLeft=newNode;
				break;
			}
			temp=temp->pLeft;
		} else if(temp->data.soLuong==hoadon.soLuong){
		    temp->v_dup.push_back(hoadon);
			break;
		}
	}
}

void run_LNR(Node* root){
	if(root==nullptr){
		return;
	}
	if(root!=nullptr){
		run_LNR(root->pLeft);
		cout<<"("<<root->v_dup.size()+1<<")"<<endl;
		xuatHoaDon(root->data);
		if(root->v_dup.size()>0){
			cout<<endl;
            for(auto x = root->v_dup.begin(); x<root->v_dup.end(); x++){
                xuatHoaDon(*x);
				cout<<endl;
            }
		}
		cout<<"==================="<<endl;
		run_LNR(root->pRight);
	}
}

void run_NLR(Node* root){
	if(root==nullptr){
		return;
	}
	if(root!=nullptr){
		cout<<"("<<root->v_dup.size()+1<<")"<<endl;
		xuatHoaDon(root->data);
		if(root->v_dup.size()>0){
			cout<<endl;
            for(auto x = root->v_dup.begin(); x<root->v_dup.end(); x++){
                xuatHoaDon(*x);
				cout<<endl;
            }
		}
		cout<<"==================="<<endl;
		run_NLR(root->pLeft);
		run_NLR(root->pRight);
	}
}

void run_LRN(Node* root){
	if(root==nullptr){
		return;
	}
	if(root!=nullptr){
		run_LRN(root->pLeft);
		run_LRN(root->pRight);
		cout<<"("<<root->v_dup.size()+1<<")"<<endl;
		xuatHoaDon(root->data);
		if(root->v_dup.size()>0){
			cout<<endl;
            for(auto x = root->v_dup.begin(); x<root->v_dup.end(); x++){
                xuatHoaDon(*x);
				cout<<endl;
            }
		}
		cout<<"==================="<<endl;
	}
}

int countHoadon(Node* root){
	int n=0;
	if(root==nullptr){
		return 0;
	} 
	return ++n+root->v_dup.size()+countHoadon(root->pLeft)+countHoadon(root->pRight);
	
}

long long TongTien(Node* root){
	long long tongtien=0;
	if(root==nullptr){
		return 0;
	}
	tongtien+=root->data.tongTien;
	if(root->v_dup.size()>0){
		for(auto x:root->v_dup){
			tongtien+=x.tongTien;
		}
	}
	tongtien+=TongTien(root->pLeft);
	tongtien+=TongTien(root->pRight);
	return tongtien;
}

long long Tong_SLhang(Node* root){
	long long tonghang=0;
	if(root==nullptr){
		return 0;
	}
	tonghang+=root->data.soLuong;
	if(root->v_dup.size()>0){
		for(auto x: root->v_dup){
			tonghang+=x.soLuong;
		}
	}
	tonghang+=Tong_SLhang(root->pLeft);
	tonghang+=Tong_SLhang(root->pRight);
	return tonghang;
}

void tim_maDH(Node* root, string key, vector<HoaDon> &result){
	if(root==nullptr){
		return;
	}

	if(root!=nullptr){
		if(root->data.maDH==key){
			result.push_back(root->data);
		}
		if(root->v_dup.size()>0){
			for(auto x:root->v_dup){
				if(x.maDH==key){
					result.push_back(x);
				}
			}
		}
		tim_maDH(root->pLeft,key,result);
		tim_maDH(root->pRight,key,result);
	}
}

void tim_tongTien(Node* root,int key, vector<HoaDon> &result){
	if(root==nullptr){
		return;
	}

	if(root!=nullptr){
		if(root->data.tongTien==key){
			result.push_back(root->data);
		}
		if(root->v_dup.size()>0){
			for(auto x: root->v_dup){
				if(x.tongTien==key){
					result.push_back(x);
				}
			}
		}
		tim_tongTien(root->pLeft,key,result);
		tim_tongTien(root->pRight,key,result);
	}
}

void tim_slHang(Node* root,int key,vector<HoaDon> &result){
	if(root==nullptr){
		return;
	}
	if(root!=nullptr){
		if(key==root->data.soLuong){
			result.push_back(root->data);
		}
		if(key==root->data.soLuong&&root->v_dup.size()>0){
			for(auto x:root->v_dup){
				result.push_back(x);
			}
		}
		if(key<root->data.soLuong){
			tim_slHang(root->pLeft,key,result);
		} else if(key>root->data.soLuong){
			tim_slHang(root->pRight,key,result);
		}
	}
}

bool cmp(HoaDon h1,HoaDon h2){
	return(h1.tongTien>h2.tongTien);
}

void tree_vector(Node* root,vector<HoaDon> &v){
	if(root==nullptr){
		return;
	}
	if(root!=nullptr){
		v.push_back(root->data);
		if(root->v_dup.size()>0){
			for(auto x: root->v_dup){
				v.push_back(x);
			}
		}
		tree_vector(root->pLeft,v);
		tree_vector(root->pRight,v);
	}
}

int main(){
	int ma =0;
	Tree t;
	createTree(t);
	while(true){
        cout<<"======================= MENU ======================="<<endl;
        cout<<"1. Duyet cay - Xuat thong tin don hang (Cau 5) "<<endl;
        cout<<"2. Nhap don hang thu cong vao BST (Cau 3)"<<endl;
        cout<<"3. Tao don hang tu dong vao BST (Cau 4)"<<endl;
		cout<<"4. Tinh trung binh tong_tien, sl_hang (Cau 6)"<<endl;
		cout<<"5. Tim kiem don hang (ma_DH) (Cau 7)"<<endl;
		cout<<"6. Tim kiem don hang (tong_tien) (Cau 8)"<<endl;
		cout<<"7. Tim kiem don hang (sl_hang) (Cau 9)"<<endl;
		cout<<"8. Xuat 20 don hang co tong tien lon nhat \n      - 10 don hang co tong tien nho nhat (Cau 10)"<<endl;
        cout<<endl;
        int k;
        cout<<"     Chon chuc nang: ";
        cin>>k;
        switch(k){
			case 1:{
				while(1){
					cout<<endl<<"================= HIEN THI HOA DON ================="<<endl;
					cout<<"1. Duyet cay LNR "<<endl;
					cout<<"2. Duyet cay NLR "<<endl;
					cout<<"3. Duyet cay LRN "<<endl;
					cout<<"0. THOAT"<<endl;
					int k;
					cout<<"Nhap lua chon: ";
					cin>>k;
					if(k==1){
						run_LNR(t.root);
					} else if(k==2){
						run_NLR(t.root);
					} else if(k==3){

					} else if(k==0){
						break;
					}
				}
				break;
			}
            case 2:{
				char c;
				do{
					insertNode(t,nhapHoaDon());
					do{
						cout<<"Ban muon nhap tiep khong? (y/n)";
						cin>>c;
					}while(c!='y'&&c!='Y'&&c!='n'&&c!='N');
				}while(c!='n'&&c!='N');
                break;
            }
			case 3:{
				srand(time(0));
				int sodonhang=5;

				for(int i=0;i<sodonhang;i++){
					string k="DH";
					HoaDon hoadon={k+to_string(++ma),10+rand()%(113-10+1),985000+rand()%(3000000-985000+1)};
					insertNode(t,hoadon);
				}
				break;
			}
			case 4:{
				if(countHoadon(t.root)!=0){
					cout<<"Trung binh tong_tien = "<<(TongTien(t.root)/countHoadon(t.root))<<endl;
					cout<<"Trung binh sl_hang = "<<float((Tong_SLhang(t.root)/countHoadon(t.root)))<<endl;
				} else{
					cout<<"So luong don hang rong~!!"<<endl;
				}
				break;
			}
			case 5:{
				string key;
				cout<<"Nhap ma don hang can tim: ";
				cin.ignore();
				getline(cin,key);
				vector<HoaDon> v_result;
				tim_maDH(t.root,key,v_result);
				cout<<"KET QUA TIM KIEM: "<<endl;
				if(v_result.size()>0){
					for(auto x:v_result){
						xuatHoaDon(x);
					}
				} else{
					cout<<"Khong tim thay hoa don!"<<endl;
				}
				break;
			}
			case 6:{
				int key;
				cout<<"Nhap tong_tien can tim kiem: ";
				cin>>key;
				vector<HoaDon> v2_result;
				tim_tongTien(t.root,key,v2_result);
				cout<<"KET QUA TIM KIEM: "<<endl;

				if(v2_result.size()>0){
					for(auto x: v2_result){
						xuatHoaDon(x);
					}
				} else{
					cout<<"Khong tim thay thong tin!"<<endl;
				}
				break;
			}
			case 7:{
				int key;
				cout<<"Nhap so luong hang can tim kiem: ";
				cin>>key;
				vector<HoaDon> v3_result;
				tim_slHang(t.root,key,v3_result);
				cout<<"KET QUA TIM KIEM: "<<endl;
				if(v3_result.size()>0){
					for(auto x: v3_result){
						xuatHoaDon(x);
					}
				} else{
					cout<<"Khong tim thay thong tin!"<<endl;
				}
				break;
			}
			case 8:{
				vector<HoaDon> vector_t;
				tree_vector(t.root,vector_t);
				sort(vector_t.begin(),vector_t.end(),cmp);
				cout<<"20 hoa don co tong tien lon nhat: "<<endl;
				if(vector_t.size()>=20){
					for(int i=0;i<20;i++){
						xuatHoaDon(vector_t.at(i));
						cout<<endl;
					}
				} else{
					for(auto x:vector_t){
						xuatHoaDon(x);
						cout<<endl;
					}
				}
				cout<<"10 hoa don con tong tien nho nhat"<<endl;
				if(vector_t.size()<=10){
					for(auto x:vector_t){
						xuatHoaDon(x);
						cout<<endl;
					}
				} else{
					for(int i=vector_t.size()-1;i>(vector_t.size()-11);i--){
						xuatHoaDon(vector_t.at(i));
						cout<<endl;
					}
				}
				break;
			}
        }
	}
	return 0;
}
