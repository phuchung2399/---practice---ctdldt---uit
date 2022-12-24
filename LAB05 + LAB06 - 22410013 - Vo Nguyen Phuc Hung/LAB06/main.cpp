//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài tập LAB06
/////////////////////////////////

#include <iostream>
#include <time.h>

using namespace std;s

void mInput(int *a, int size) {
    float value;
    for (int i = 0; i < size; ++i) {
        cout << "Nhap vao value : ";
        cin >> value;
        *(a + i) = value;
    }
}

void input(int*a, int n){
    for(int i =0 ; i< n ;i++){
        *(a +i ) = rand()%9;
 }
}
void output(int *a, int n){
 for(int i =0 ; i< n ;i++){
     cout<< *(a + i) << "\t";
 }
}
bool liners(int  *a, int n, int value){
 for(int i =0 ; i< n ;i++){
    if (*(a+i)== value){
        return true;
    }
 } 
 return false;
}

void selectionS(int *a, int n){
    int m;
    for(int i =0 ; i <n-1; i++){
        m =i;
        for(int j =i+1; j<n;j++){
            if(a[j]<a[m]){
                m= j;
            }
            swap(a[m],a[i]);
        }
    }
}

void input_arr(int* a,int &size){
	for(int i=1;i<size;i++){
		*(a+i)=39000+rand()%(99000-39000+1);
	}
}

int cacl_time(int* a,int &size,int typef){
    clock_t star_time,end_time;
    double total;
    star_time = clock();
    if (typef ==1)
    {
        selectionS(a,size);
    }else{

    }
    
    end_time = clock();
    total = (double) (end_time - star_time);
    return total;
}

int main()
{
    int *a = new int[(int)1e6];
    int n = (int)1e5;

  while (1) {
        cout<<"-------"<<endl;
        cout<<"1. Nhap gia tri cho mang thu cong: "<<endl;
        cout<<"2. Tao 100000 phan tu: " << endl;
        cout<<"3. Xuat cac gia tri trong mang:" << endl;
        cout<<"4. Sap xep gia tri tang dan:" << endl;
        cout<<"5. Tinh thoi gian thuc hien: " << endl;
        cout<<"6. " << endl;
        int c;
        cout<<"Nhap lua chon: ";
        cin>>c;
            switch (c){
            case 1:{
                int size;
                cout << "Nhap vao so luong phan tu: " << endl;
                cin >> size;
                    mInput(a, size);
                    }break;
            case 2:{
                    input_arr(a,n);
                    }break;
            case 3:{
                   output(a,n);
                    }break;
            case 4:{
               
                selectionS(a,n);
                cout << "Da hoan thanh"<<endl;
                output(a,n);

                     }break;
            case 5:{
                cout <<"thoi gian thuc hien:" <<cacl_time(a,n,1) <<endl;
                     }break;
            case 6:{
                     }break;

            default:
                break;
        }
    }


}
