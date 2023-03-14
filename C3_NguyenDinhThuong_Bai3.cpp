#include <iostream>
#include<conio.h>
using namespace std;
int main()
{

	long int a;
	float b;
	cout << "Nhap gia tri doanh so  = ";
	cin>>a;
	if(a<0){
		cout<<"Gia tri khong hop le";
	}
	if(a<=200)
	{
	b=a*10/100;
	cout << "Voi tong doanh so la " << a << ", ";
	cout << "Thi hoa hong nhan duoc la " << b;
	}
	else if(a<=500)
	{
	b=a*15/100;
	cout << "Voi tong doanh so la " << a << ", ";
	cout << "Thi hoa hong nhan duoc la " << b;
	}
	else if(a>500)
	{
	b=a*25/100;
	cout << "Voi tong doanh so la " << a << ", ";
	cout << "Thi hoa hong nhan duoc la " << b;
	}
	return 0;
}
