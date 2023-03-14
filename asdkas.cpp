#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int day, month, year, tg, day1, month1, year1;
    cout<<"Nhap vao ngay: "; cin>>day; day1=day;	
    cout<<"Nhap vao thang: "; cin>>month; month1=month;
    cout<<"Nhap vao nam: "; cin>>year; year1=year;
    int KiemTraNam(int year);
	int KiemTraNgay(int day,int month,int year);
    if(month>0 && month<=12 && year>1){
            cout<<"Dinh dang ngay dung \n";
        }else cout<<"Dinh dang ngay sai";
        return 0;
    switch(month)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            tg = 30;
            break;
        case 2:
            tg = 28 + ((year%4==0 && year%100) || (year%400==0));
            break;
        default:
            tg = 31;
    }
    day = (day%tg)+1;
    if(day==1)
    {
        month = (month%12)+1;
    }

    cout<<"Ngay mai: "<<day<<"/"<<month<<"/"<<year+(month==1 && day==1);
    if(day1==1)
    {
        switch(month1-1)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                day1=30;
                break;
            case 2:
                day1=28+((year1%4==0 && year1%100) || (year1%400==0));
                break;
            default:
                day1=31;
        }
        if(month1==1)
        {
            month1=12;
            year1--;
        }
        else
        {
            month1--;
        }
    }
    else
    {
        day1--;
    }

    cout<<"\nHom qua: "<<day1<<"/"<<month1<<"/"<<year1;

    cout<<endl;
    return 0;
}
