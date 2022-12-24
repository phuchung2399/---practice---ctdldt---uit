//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// LAB05
/////////////////////////////////

#include<iostream>
#include<time.h>
#include<string>

using namespace std;

//Cau 1: Viet ham nhap gia tri tu dong cho arrayX
/*
	Input: arrayX, size
	Output: size
*/
void input_auto(int* a,int &size){
	srand(time(0));
	int n=30+rand()%(50-20+1);
	if(n+size>100){ //maximun = 100
		n=100-size;
	}
	for(int i=size;i<(size+n);i++){
		*(a+i)=100+rand()%(999-100+1);
	}
	size+=n; //update size
}

//Cau 2: Viet ham nhap gia tri tu dong cho arrayY
/*
	Input: arrayY, size
	Output: size
*/
void input_tangdan(int* a,int &size){
	srand(time(0));
	int n=30+rand()%(50-30+1);
	*a=100+rand()%(130-100+1);
	for(int i=1;i<n;i++){
		*(a+i)=*(a+i-1)+rand()%15;
	}
	size+=n;
}

//Cau 3: Xuat mang
/*
	Input: mang a, size
	Output: cout
*/
void duyet(int* a,int size){
	for(int i=0;i<size;i++){
		cout<<*(a+i)<<" ";
	}
}

//Cau 4: Viet ham tim kiem tuyen tinh
/*
	Input: mang a, size, key
	Output: true/false
*/
bool linearSearch(int* a,int size,int key){
	for(int i=0;i<size;i++){
		if(*(a+i)==key){
			return true;
		}
	}
	return false;
}

//Cau 5: Tim kiem nhi phan
/*
	Input: mang a, int l, int r, key
	Output: true/false
*/
bool binarySearch(int* a,int l,int r,int key){
	if(l>r){
		return false;
	}
	int m=(l+r)/2;
	if(*(a+m)==key){
		return true;
	}
	else if(*(a+m)<key){
		return binarySearch(a,m+1,r,key);
	} else{
		return binarySearch(a,l,m-1,key);
	}
}

//Cau 6: Viet ham tim kiem noi suy
/*
	Input: mang a, int low, int high, int key
	Output: true/false
*/
bool interpolationSearch(int* a,int low, int high, int key){
	int pos;
	if(low<=high&&key>=*(a+low)&&key<=*(a+high)){
		pos=low+((double)(high - low) / (*(a+high) - *(a+low)))* (key - *(a+low));
	}
	if(*(a+pos)==key){
		return true;
	}
	if(*(a+pos)<key){
		return interpolationSearch(a,pos +1, high, key);
	} else{
		return interpolationSearch(a,low,pos-1,key);
	}
	return false;
}

int main(){
	int* arrayX=new int[100];
	int size_x=0;
	int* arrayY=new int[100];
	int size_y=0;
	while(true){
		cout<<"\n-------------- MENU -------------"<<endl;
		cout<<"1. Tao mang \n\tA. Tao mang arrayX\n\tB. Tao mang arrayY"<<endl;
		cout<<"2. Xuat mang \n\tA. Xuat mang arrayX\n\tB. Xuat mang arrayY"<<endl;
		cout<<"3. Tim kiem tuyen tinh \n\tA. Ap dung mang arrayX\n\tB. Ap dung mang arrayY"<<endl;
		cout<<"4. Tim kiem nhi phan, ap dung mang arrayY"<<endl;
		cout<<"5. Tim kiem noi suy, ap dung mang arrayY"<<endl;
		int c;
		cout<<"Nhap lua chon: ";
		cin>>c;
		switch(c){
			case 1:{
				cout<<"\tA. Tao mang arrayX\n\tB. Tao mang arrayY"<<endl;
				char c;
				cout<<"Lua chon: ";
				cin>>c;
				if(c=='A'||c=='a'){
					input_auto(arrayX,size_x);
					cout<<"Da tao mang arrayX"<<endl;
				} else if(c=='B'||c=='b'){
					input_tangdan(arrayY,size_y);
					cout<<"Da tao mang arrayY"<<endl;
				} else{
					cout<<"Chon loi!"<<endl;
				}
				break;
			}
			case 2:{
				cout<<"\tA. Xuat mang arrayX\n\tB. Xuat mang arrayY"<<endl;
				char c;
				cout<<"Lua chon: ";
				cin>>c;
				if(c=='A'||c=='a'){
					cout<<"Mang arrayX: ";
					duyet(arrayX,size_x);
				} else if(c=='B'||c=='b'){
					cout<<"Mang arrayY: ";
					duyet(arrayY,size_y);
				} else{
					cout<<"Chon loi!"<<endl;
				}
				break;
			}
			case 3:{
				int x;
				cout<<"Nhap gia tri can tim kiem: ";
				cin>>x;
				cout<<"3. Tim kiem tuyen tinh \n\tA. Ap dung mang arrayX\n\tB. Ap dung mang arrayY"<<endl;
				char c;
				cout<<"Lua chon: ";
				cin>>c;
				if(c=='A'||c=='a'){
					cout<<"Ap dung mang arrayX: "<<endl;
					if(linearSearch(arrayX,size_x,x)){
						cout<<"Tim thay!"<<endl;
					} else{
						cout<<"Khong tim thay!"<<endl;
					}
				} else if(c=='B'||c=='b'){
					cout<<"Ap dung mang arrayY: "<<endl;
					if(linearSearch(arrayY,size_x,x)){
						cout<<"Tim thay!"<<endl;
					} else{
						cout<<"Khong tim thay!"<<endl;
					}
				} else{
					cout<<"Chon loi!"<<endl;
				}
				break;
			}
			case 4:{
				int x;
				cout<<"Nhap gia tri can tim kiem: ";
				cin>>x;
				if(binarySearch(arrayY,0,size_y-1,x)){
					cout<<"Tim thay!"<<endl;
				} else{
					cout<<"Khong tim thay!"<<endl;
				}
				break;
			}
			case 5:{
				int x;
				cout<<"Nhap gia tri can tim kiem: ";
				cin>>x;
				if(interpolationSearch(arrayY,0,size_y-1,x)){
					cout<<"Tim thay!"<<endl;
				} else{
					cout<<"Khong tim thay!"<<endl;
				}
				break;
			}
		}
	}
	return 0;
}
