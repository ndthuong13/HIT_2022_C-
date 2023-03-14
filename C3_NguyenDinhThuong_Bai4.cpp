#include<iostream>
using namespace std;
int main()
{
	int n, m, k;
	cout<<"Nhap vao so ban nhan duoc qua: "; cin>>n;
	cout<<"Nhap vao so hop qua: "; cin>>m;
	cout<<"Nhap vao so tui qua: "; cin>>k;
	if (m*k % n == 0){
		cout<<"Yes. ";
		cout<<"So tui qua cac ban nhan duoc la: " <<m*k/n<< endl;
}else {
	cout<<"No";
}
}
