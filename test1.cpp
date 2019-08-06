#include<iostream>
using namespace std;
int datetoday(int year,int month,int th,int w,bool p)
{
    int day,week,k=0;
    if(month==1||month==2)
    {
        month+=12;
        year--;
    }
    for(day=p?1:31;day<=p?31:1;p?(day++):(day--))
    {
        week=(day+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
        if(week+1==w)
            k++;
        if(k==th)
            break;
    }
    return day;
}
int main(void)
{
    int year;
    while(cin>>year)
    {
        cout<<year<<"-01-01"<<endl;
        printf("%d-01-%02d\n",year,datetoday(year,1,3,1,1));
        printf("%d-02-%02d\n",year,datetoday(year,2,3,1,1));
        printf("%d-05-%02d\n",year,datetoday(year,5,1,1,0));
        cout<<year<<"-07-04"<<endl;
        printf("%d-09-%02d\n",year,datetoday(year,9,1,1,1));
        printf("%d-11-%02d\n",year,datetoday(year,11,4,4,1));
        cout<<year<<"-12-25"<<endl<<endl;
    }
    return 0;
}