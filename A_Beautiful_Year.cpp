#include<bits/stdc++.h>
using namespace std;
bool hasDistinctDigits(int year)
{
    set<int> s;
    int cnt=0;
    while(year)
    {
        s.insert(year%10);
        year/=10;
        cnt++;
    }
    if(s.size()==cnt)
       return true;
    return false;
}
int main()
{
    int year;
    cin>>year;
    for(int i=year+1;i<=9500;i++)
    {
        if(hasDistinctDigits(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}