#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<"Nhap vao nam: ";
	cin>>a;
	if(a < 0){
		cout<<"Gia tri khong hop le";
	}
	if(((a % 4 == 0 ) && (a % 100 != 0 )) || (a % 400 == 0)){
		cout<<" Yes "<<endl;
	}else{
		cout<<" No "<< endl;
	}
	return 0;
}
