#include<iostream>
using namespace std;
int main()
{
	int doanhso;
	cin >> doanhso;
	if( doanhso < 0 ) cout<< 0;
	if(doanhso <= 200 ) cout<< doanhso * 0.1;
	else if (doanhso <= 500) cout << doanhso * 0.15;
	else if (doanhso > 500 ) cout << doanhso * 0.25;
}
