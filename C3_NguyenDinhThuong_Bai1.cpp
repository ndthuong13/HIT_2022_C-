#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<"Nhap vao tuoi cua ban: ";
	cin>>a;
	if(a < 18){
		cout<<"Gia tri khong hop le";
	}else if(a > 22){
		cout<<"Gia tri khong hop le";
	}
	if(a == 18 ){
		cout<<"Ban dang la sinh vien nam nhat";
	}else if(a == 19){
		cout<<"Ban dang la sinh vien nam hai";
	}else if(a == 20){
		cout<<"Ban dang la sinh vien nam ba";
	}else if(a == 21){
		cout<<"Ban dang la sinh vien nam bon";
	}else if(a == 22){
		cout<<"Ban da tot nghiep";
	}
}
	
